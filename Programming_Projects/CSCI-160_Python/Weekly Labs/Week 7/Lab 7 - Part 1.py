'''
Mason Motschke @ mason.motschke@und.edu, ID: 1253634
CSCI 160
Thursday Lab 5-7
Lab 7 Part 1 
This program asks for a file name and writes entered test scores to it.
'''
fileName = str(input("Enter a New File Name: "))
useFile = open(fileName, 'w')

testScore = int(input("Enter the first test score (0-100): "))
if (testScore != -1): 
    while (testScore > 100) or (testScore < 0): #Initial Test
        testScore = int(input("Error: Enter a Valid Score (0-100): "))
    
    while (testScore != -1):
        while (testScore > 100) or (testScore < 0): #Continuous var. test
            testScore = int(input("Error: Enter a Valid Score (0-100): "))
        
        useFile.write(str(testScore) + "\n") #writes to file
        testScore = int(input("Enter next score 0-100 (Enter '-1' to stop): "))
useFile.close()

    
    


