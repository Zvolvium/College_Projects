'''
Mason Motschke @ mason.motschke@und.edu; ID: 1253634
CSCI 160
Thursday Lab 5-7
Lab Test 2 - Part 2
'''
import FileUtils
import os
def numOfStrokes(List):
    add = 0
    for val in List:
        add += val
    return add

def holeInOne(List):
    for index in range(0, len(List)):
        if (List[index] == 1):
            return True
    return False

def printResults(List):
    holeNum = 1
    print("\nHole to Score")
    for val in List:
        print(holeNum, format(val, ' >7'), "\n")
        holeNum += 1
    
def main():
    fileName = FileUtils.selectOpenFile("Enter a File to Open")
    if (fileName == None):
        print("There is no file with that Name")
        os._exit(0)
    inFile = open(fileName, 'r')
    scoreList = []
    for val in inFile:
        val = int(val.strip())
        scoreList.append(val)
    totalScore = numOfStrokes(scoreList)
    if (totalScore < 36):
        below = (36 - totalScore)
        print("You scored below Par by", below, "strokes.")
    elif (totalScore > 36):
        above = (totalScore - 36)
        print("You scored above Par by", above, "strokes.")
    elif (totalScore == 36):
        print("You scored at Par")
    if (holeInOne(scoreList) == True):
        print("\nCongradulations on the hole in one!!")
    printResults(scoreList)
    print("Total for Round:", totalScore)
    inFile.close()
    
    
main()