'''
Mason Motschke @ mason.motschke@und.edu, ID: 1253634
CSCI 160
Thursday Lab 5-7
Lab 8 Part 2
Program reads file and outputs: Largest value, smallest value, average, 
as well as values within the limits. 
'''
import FileUtils
import os

def largestVal(list1):
    bigVal = -1 * (10 ** 100)
    for val in list1:
        if (val > bigVal):
            bigVal = val
    return bigVal

def matchingVals(list1, limLow, limHigh):
    print("\n" + "Matching Values: ")
    for val in list1:
        if (val > limLow) and (val < limHigh):
            print(val)
    
def average(list1):
    add = 0
    for val in list1:
        add += val
    return (add / len(list1))
    
def smallestVal(list1):
    smallVal = (10 ** 100)
    for val in list1:
        if (val < smallVal):
            smallVal = val
    return smallVal
    
def main():
    values = []
    fileName = FileUtils.selectOpenFile("Select a File")
    if (fileName == None):
        os._exit(0)
    inFile = open(fileName, 'r')
    for val in inFile: #Converts File to List 
        values.append(int(val.strip()))
    inFile.close()
    bigVal = largestVal(values)
    smallVal = smallestVal(values)
    valAv = average(values)
    print("Largest Score:", format(bigVal, '>5'))
    print("Smallest Score:", format(smallVal, '>4'))
    print("Average Score:", format(format(valAv, '1.2f'), '>5'), "\n")
    print("Search for Values - ")
    limLow = int(input("Enter the Lower Limit: "))
    limHigh = int(input("Enter the Upper Limit: "))    
    matchingVals(values, limLow, limHigh)
    
main()