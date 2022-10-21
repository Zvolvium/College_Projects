'''
Mason Motschke @ mason.motschke@und.edu; ID: 1253634
CSCI 160
Thursday Lab 5-7
'''
import FileUtils
import os

def addOddNumbers(string):
    add = 0
    for index in range(0, len(string) - 1, 2):
        val = int(string[index])
        add += val
    return (add * 3)
    
def addEvenNumbers(string):
    add = 0
    for index in range(1, len(string) - 1, 2):
        val = int(string[index])
        add += val
    return (add * 3)

def checkNumbers(List):
    final = 0
    num = addEvenNumbers(List) + addOddNumbers(List)
    if ((num % 10) != 0):
        x = 10 - (num % 10)
        x = num + x
        final = x - num
    return final

def validCheck(value, product):
    if (value == 0):
        print(product[0], "is Valid.")
    else:
        print(product[0], "is InValid")
    
def main():
    fileName = FileUtils.selectOpenFile("Select File")
    #fileName = "Sample for Lab 9.txt"
    if (fileName == None):
        os._exit
    inFile = open(fileName, 'r')
    for items in inFile:
        items = items.strip()
        split = items.split(":")
        items = split[len(split) - 1]
        validCheck(checkNumbers(items), split)
    inFile.close() 
    
main()