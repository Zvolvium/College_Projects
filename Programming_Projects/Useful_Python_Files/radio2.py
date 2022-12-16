# #########################################################
# WFMdemod.py
#
# This program implements a FM demodulator using a RTL-SDR
# dongle and a Raspberry PI
#
# Author: Kasun Somaratne
# Date: July 2, 2018
# #########################################################

from rtlsdr import RtlSdr
from scipy.signal import decimate, remez, convolve
from numpy import array, reshape, square, sqrt, zeros, absolute
import alsaaudio as sd
from StoppableThread import StoppableThread
import queue
from time import sleep
import asyncio
import sys
               
# initialize and configure the SDR
sdr = RtlSdr()
sdr.sample_rate = 240e3 # Hz
sdr.center_freq = 94.5 * 1e6 # Hz
sdr.gain = 'auto'

# create a PCM object for data playback
player = sd.PCM()
player.setrate(24000) # Hz
player.setchannels(1)
player.setperiodsize(13107)
player.setformat(sd.PCM_FORMAT_FLOAT64_LE)

dif = remez(30, [0, 0.9*sdr.sample_rate/2], [0.9], Hz=sdr.sample_rate, type='differentiator')

aqueue = queue.Queue(100)
        
async def streaming():
    # collect samples
    async for samples in sdr.stream():
        # separate into real and imaginary parts
        sampReal = array(samples.real)
        sampImag = array(samples.imag)
        # normalize
        sampMag = sqrt((square(sampReal) + square(sampImag)))
        sampReal = sampReal / sampMag
        sampImag = sampImag / sampMag
        # reshape arrays
        sampReal = reshape(sampReal, (131072,))
        sampImag = reshape(sampImag, (131072,))
        # demodulate
        fm_demod = ((sampReal * convolve(sampImag, dif, mode='same')) - (sampImag * convolve(sampReal, dif, mode='same'))) / (square(sampReal) + square(sampImag))
        # down sample to capture the audio
        dec_demod = decimate(fm_demod, 10, ftype='fir')
        # put data in queue
        aqueue.put(dec_demod)
        # print('Queue size: ' + str(aqueue.qsize())

async def stopStreaming():
    await sdr.stop()

def playAudio():
    try:
        data = aqueue.get_nowait()
        # play data
        player.write(data)
        aqueue.task_done()
    except queue.Full:
        print('Queue is full!')
    except Exception as e:
        #print(type(e).__name__ + ': ' + str(e))
        pass

# start audio thread
audioThread = StoppableThread( playAudio )
audioThread.daemon = True
audioThread.start()

# start streaming data from the SDR
loop = asyncio.get_event_loop()
try:
    loop.run_until_complete(streaming())
except KeyboardInterrupt:
    try:
        loop.run_until_complete(stopStreaming())
    except RuntimeError:
        pass    
finally:
    audioThread.stop = True