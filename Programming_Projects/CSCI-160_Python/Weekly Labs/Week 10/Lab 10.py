'''
Mason Motschke @ mason.motschke@und.edu; ID: 1253634
CSCI 160
Thursday Lab 5-7
'''
import FileUtils
import os

def readFile(List):
    fileName = FileUtils.selectOpenFile("Select File to Open")
    if (fileName == None):
        os._exit(0)
    inFile = open(fileName, 'r')    
    for line in inFile:
        line = line.strip()
        List.append(line)
    inFile.close()

def characterSearch(List, Dictionary):
    doNothing = 0
    for item in List:
        item = item.strip()
        for letter in item:
            if (letter == ",") or (letter == " ") or (letter == "."):
                doNothing += 1
            else:
                letter = letter.lower()
                if (Dictionary.get(letter) == None):
                    Dictionary[letter] = 1 #Adds value @ key
                else:
                    Dictionary[letter] += 1 #Increments value @ key
                    
def printDict(Dictionary):
    print("Letters to Occurances:")
    for key in Dictionary:
        print('%s %10d' % (key, Dictionary[key]))
    print()
 
def mostOccurChar(Dictionary):
    bigNum = -1 * (10 ** 100)
    bigKeys = []
    for key in Dictionary:
        if (Dictionary[key] > bigNum):
            bigKeys = [] #Allows for multiple keys with same val
            bigKeys.append(key)
            bigNum = Dictionary[key]
        elif (Dictionary[key] == bigNum):
            bigKeys.append(key)
    print("Letter(s) with Most Occurances is:")
    print(bigKeys, ":", bigNum, '\n')

def leastOccurChar(Dictionary):
    smallNum = 1 * (10 ** 100)
    smallKeys = []
    for key in Dictionary:
        if (Dictionary[key] < smallNum):
            smallKeys = [] #Allows for multiple keys with same val
            smallKeys.append(key)
            smallNum = Dictionary[key]
        elif (Dictionary[key] == smallNum):
            smallKeys.append(key)
    print("Letter(s) with Least Occurances is:")
    print(smallKeys, ":", smallNum, '\n')
    
def main():
    itemList = []
    letterDict = {}
    readFile(itemList)
    characterSearch(itemList, letterDict)
    printDict(letterDict)
    mostOccurChar(letterDict)
    leastOccurChar(letterDict)
    
main()