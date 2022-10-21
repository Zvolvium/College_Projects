'''
Mason Motschke @ mason.motschke@und.edu, ID: 1253634
CSCI 160
Thursday Lab 5-7
Lab 8 Part 1
Program writes test scores to a chosen file.
'''
import os
import FileUtils

def main():
    testScores = []
    testScore = int(input("Enter the first test score (Enter -1 to Quit): "))
    if (testScore == -1): #Exits if user want to leave right away
        os._exit(0)
    while (testScore != -1):
        testScores.append(testScore)
        testScore = int(input("Enter next score(Enter -1 to Quit): "))
    fileName = FileUtils.selectSaveFile("Choose File Name")
    if (fileName == None): #If no file is selected: Exit
        os._exit(0) 
    inFile = open(fileName, 'w')
    for score in testScores: #writes to file from list
        inFile.write(str(score) + '\n')
    inFile.close()
    anotherFile = str(input("Do you wish to create another file? "))
    while (anotherFile.lower() != "yes") and (anotherFile.lower() != "no"):
        anotherFile = str(input("Error: Enter a Valid Response (Yes or No): "))
    if (anotherFile.lower() == "yes"): #Calls itself if another file is Required
        main()
    elif (anotherFile.lower() == "no"):
        os._exit(0)
        
main()
