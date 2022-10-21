'''
Mason Motschke @ mason.motschke@und.edu; ID: 1253634
CSCI 160
Thursday Lab 5-7
'''
import FileUtils
import os

def findMaxValue(List):
    bigNum = -1 * (10 ** 100)
    for val in List:
        if (val > bigNum):
            bigNum = val
    return bigNum

def findMinValue(List):
    smallNum = 1 * (10 ** 100)
    for val in List:
        if (val < smallNum):
            smallNum = val
    return smallNum

def calcRange(List):
    maxVal = findMaxValue(List)
    minVal = findMinValue(List)
    rangeVal = maxVal - minVal
    return rangeVal

def calcAverage(List):
    add = 0
    count = 0
    for val in List:
        add += val
        count += 1
    final = add / count
    return final

def findNumberAbove(List, testValue):
    aboveVal = []
    for val in List:
        if (val >= int(testValue)):
            aboveVal.append(val)
    return aboveVal

def findFirstOccurance(List, findMe):
    for index in range(0, len(List)):
        val = List[index]
        if (val == findMe):
            return index
    return -1
    
def findLastOccurance(List, findMe):
    for index in range(len(List) - 1, -1, -1):
        val = List[index]
        if (val == findMe):
            return index
    return -1

def calcCount(List, findMe):
    count = 0
    for index in range(0, len(List)):
        val = List[index]
        if (val == findMe):
            count += 1
    return count

def isInList(List, findMe):
    for val in List:
        if (val == findMe):
            return True
    return False
    
def main():
    values = []
    fileName = FileUtils.selectOpenFile("Select File")
    #fileName = 'Lab9Num.txt'
    inFile = open(fileName, 'r')
    for line in inFile:
        values.append(int(line.strip()))
    inFile.close()
    
    print("The Largest value is:", findMaxValue(values))
    print("The Smallest value is:", findMinValue(values))
    print("The Range of values is:", calcRange(values))
    print("The Average is:", format(calcAverage(values), '1.2f'))
    testValue = input("Enter Number (Will find values >= the number): ")
    print("\nValues > or =", testValue, ":")
    print(findNumberAbove(values, testValue))
    findVal = int(input("\nEnter a Value to find: "))
    print("The First index of", findVal, "is:", findFirstOccurance(values, findVal))
    print("The Last index of", findVal, "is:", findLastOccurance(values, findVal))
    print("Number of occurances of", findVal, "is:", calcCount(values, findVal))
    print(findVal, "is in list:", isInList(values, findVal))
    
main()