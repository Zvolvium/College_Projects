'''
Mason Motschke
CSCI-161
Thursday Lab 5-7
Program #6 Soccer Team Roster
'''
import os

def enterFirstFivePrint(Dict):
    players = ["1's", "2's", "3's", "4's", "5's"]
    sortedList = []
    x = 0
    while (x < 5):
        jerseyNum = int(input("\nEnter Player " + players[x] + " jersey number: "))
        playerRating = int(input("Enter Player " + players[x] + " rating: "))
        Dict[jerseyNum] = playerRating
        sortedList.append(jerseyNum)
        x += 1    
    sortedList.sort()
    print('\n')
    for item in sortedList:
        print("Jersey Number:", item, "Rating:", Dict[item])

def addPlayer(Dict):
    playerToAdd = int(input("\nEnter player number: "))
    ratingToAdd = int(input("Enter players rating: "))
    flag = -1
    for x in Dict:
        if (x == playerToAdd):
            print("Cannot Add: Player is already in roster!")
            flag = 0
    if (flag == -1):
        Dict[playerToAdd] = ratingToAdd
    choiceMenu(Dict)

def removePlayer(Dict):
    playerToRemove = int(input("\nEnter player number to remove: "))
    flag = -1
    for x in Dict:
        if (x == playerToRemove):
            flag = 0
    if (flag == 0):
        Dict.pop(playerToRemove)
    elif (flag == -1):
        print("Player to remove isn't in Roster!")
    choiceMenu(Dict)
    
def updateRating(Dict):
    playerToUpdate = int(input("\nEnter player jersey number: "))
    newRating = int(input("Enter new rating: "))
    flag = -1
    for x in Dict:
        if (x == playerToUpdate):
            Dict[playerToUpdate] = newRating
            flag = 0
    if (flag == -1):
        print("Player to update isn't in Roster!")
    choiceMenu(Dict)
    
def outputPlayersAboveRating(Dict):
    rating = int(input("\nEnter a rating: "))
    for x in Dict:
        if (Dict[x] > rating):
            print("\nJersey Number:", x, "Rating:", Dict[x])
    choiceMenu(Dict)

def outputRoster(Dict):
    sortedList = []
    for x in Dict:
        sortedList.append(x)
    sortedList.sort()
    print('\n')
    for item in sortedList:
        print("Jersay Number:", item, "Rating:", Dict[item])
    choiceMenu(Dict)
    
def printMenu():
    print("\nMenu")
    print("a - Add player")
    print("d - Remove player")
    print("u - Update player rating")
    print("r - Output players above a rating")
    print("o - Output roster")
    print("q - Quit")
    
def choiceMenu(Dict):
    printMenu()
    user = input("Enter your choice: ")
    if (user.lower() == 'q'):
        print("\n***** Goodbye :) *****")
        os._exit(0)
    elif (user.lower() == 'a'):
        addPlayer(Dict)
    elif (user.lower() == 'd'):
        removePlayer(Dict)
    elif (user.lower() == 'u'):
        updateRating(Dict)
    elif (user.lower() == 'r'):
        outputPlayersAboveRating(Dict)
    elif (user.lower() == 'o'):
        outputRoster(Dict)
    else:
        print("\n***** I don't understand *****")
        print("****** Please try again ******")
        choiceMenu(Dict)
    
def main():
    mainDict = {}
    enterFirstFivePrint(mainDict)
    choiceMenu(mainDict)
    
main()