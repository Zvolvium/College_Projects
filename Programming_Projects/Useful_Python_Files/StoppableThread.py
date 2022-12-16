# #########################################################
# StoppableThread.py
#
# This program implements a thread object that can be stopped
#
# Author: Kasun Somaratne
# Date: July 2, 2018
# #########################################################

from threading import Thread

class StoppableThread( Thread ):
    """A thread that can be stopped or paused"""
    def __init__( self, function ):
        """Constructor for stoppable thread
        
        function: the function to be executed by this thread. This function is repeatedly executed until it is stopped
        """
        Thread.__init__( self )
        self.function = function
        self.stop = False
        self.halt = False
            
    def run( self ):
        """This function is executed when the thread is started"""
        while not self.stop:
            if not self.halt:
                self.function()