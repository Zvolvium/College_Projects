'''
Mason Motschke @ mason.motschke@und.edu, ID: 1253634
CSCI 160
Thursday Lab 5-7
Lab 7 Part 2
This program finds the min, max, average, the closest to 70, and
if the values are greater than or equal to 70, and less than 70
from reading the selected file. 
'''
import FileUtils
import os
import math

fileName = FileUtils.selectOpenFile("Select File")
if (fileName == None):
    print("Error: Selected File Not Found")
    os._exit(0)
    
inFile = open(fileName, 'r')

#Functions--->
def average(finalNum, count):
    num = 0
    if (count == 0):
        return num
    else:
        num = (finalNum / count)
        return num

def minValue(fileValue, smallNum):
    if (fileValue < smallNum):
        smallNum = fileValue   
    return smallNum

def maxValue(fileValue, bigNum):
    if (fileValue > bigNum):
        bigNum = fileValue  
    return bigNum

def lessThan_70(fileValue, closestNum):
    if (fileValue <= 70):
        if (fileValue > closestNum):
            closestNum = fileValue
    return closestNum

def closestTo_70(fileValue, closestValue):
    if (math.isclose(fileValue, 70, abs_tol= (10 ** 100)) == True):
        if (abs(70 - fileValue) < abs(70 - closestValue)):
            closestValue = fileValue
    return closestValue
        
#<---
#Main--->
minVal = (1 * (10 ** 99999))
maxVal = (-1 * (10 ** 99999))
avCount = 0
addAv = 0
highCt = 0
lowCt = 0
closeTo_70Num = 0
closestValue = (10 ** 100)
closeTo_70N2 = 0

for val in inFile:
    val = int(val.strip())
    minVal = minValue(val, minVal)
    maxVal = maxValue(val, maxVal)
    closeTo_70Num = lessThan_70(val, closeTo_70Num)
    closeTo_70N2 = closestTo_70(val, closestValue)
    if (val >= 70): #Num of Values >= 70
        highCt += 1
    if (val < 70): #Num of Values < 70
        lowCt += 1
    avCount += 1
    addAv += val

average = average(addAv, avCount)
if (avCount == 0):
    print("No Data in File")
else:
    print("Minimum Value:", minVal)
    print("Maximum Value:", maxVal)
    print("Average of the Data is:", format(average, "1.3f"))
    print("The Total Amount of Data is:", avCount)
    print("Number of Values greater than and equal to 70:", highCt)
    print("Number of Values less than 70:", lowCt)
    print("The Closest Value to 70 is:", closeTo_70N2)
    print("Closest Value less than or equal to 70:", closeTo_70Num)
inFile.close()
#<---
