'''
Mason Motschke @ mason.motschke@und.edu; ID: 1253634
CSCI 160
Thursday Lab 5-7
'''
import os
import FileUtils

def displayChoices():
    print('\n' + "What would you like to do?")
    print("   1. Open a data file")
    print("   2. Add new Names")
    print("   3. Search by date")
    print("   4. Display all birthdays for the Month")
    print("   5. Exit program \n")
    
def choices(Dict, fileToOpen):
    displayChoices()
    myChoice = int(input("Your Choice? "))
    while (myChoice > 5) or (myChoice < 1):
        myChoice = int(input("Enter a valid choice (1-5): "))
    if (myChoice == 1):
        fileToOpen = FileUtils.selectOpenFile("Select a file to Open")
        openFile(Dict, fileToOpen)
    elif (myChoice == 2):
        addEntries(Dict, fileToOpen)
    elif (myChoice == 3):
        searchByDate(Dict, fileToOpen)
    elif (myChoice == 4):
        printBirthdays(Dict, fileToOpen)
    elif (myChoice == 5):
        writeToFile(Dict, fileToOpen)

def writeToFile(Dict, fileName):
    inFile = open(fileName, 'w')
    for key in Dict:
        inFile.write(key + ':' + str(Dict[key]) + '\n')
    inFile.close()
    os._exit(0)
    
def printBirthdays(Dict, file):
    names = 'Names:'; dates = 'Dates:'
    print("\n" + '%-10s %10s' % (names, dates))
    for key in Dict:
        print('%-10s %10d' % (key, Dict[key]))
    choices(Dict, file)
    
def searchByDate(Dict, file):
    dateToFind = int(input("Enter a date to find (Day of Month): "))
    while (dateToFind != 0):
        nameFound = False
        for key in Dict:
            if (dateToFind == Dict[key]):
                print("Name Associated with Date:", key)
                nameFound = True
        if (nameFound == False):
            print("No one has that birthday")
        dateToFind = int(input("\nEnter next date (Enter 0 to quit): "))
    choices(Dict, file)
    
def addEntries(Dict, file):
    name = input("Enter a Name: ")
    date = int(input("Enter a date (Day of Month): "))
    for key in Dict:
        if (date == Dict[key]):
            print("Date already has a name: Entry will NOT be added to list.")
            choices(Dict, file)
    Dict[name] = date
    choices(Dict, file)
    
def openFile(Dict, file):
    if (file == None):
        exit = input("Do you want to exit (y/n)? ").lower()
        if (exit == "y"):
            os._exit(0)
        file = FileUtils.selectOpenFile("Select Valid File")
    fileName = file
    inFile = open(fileName, 'r')
    for line in inFile:
        line = line.strip()
        line = line.split(':')
        Dict[line[0]] = int(line[1])
    inFile.close()
    choices(Dict, file)
    
def main():
    birthdays = {}
    fileName = 0
    choices(birthdays, fileName)
    
main()
