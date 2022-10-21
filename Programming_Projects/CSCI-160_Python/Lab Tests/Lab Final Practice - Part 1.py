'''
Lab Final Practice
Part 1
"Write test scores to a file"
'''
def displayChoices():
    print("\nWhat would you like to do?")
    print("   1) View entered scores")
    print("   2) Add scores")
    print("   3) Exit Program")
    
def choices(List):
    displayChoices()
    dicision = int(input("Enter choice: "))
    if (dicision == 1):
        scoresEntered(List)
    elif (dicision == 2):
        addScores(List)
    elif (dicision == 3):
        exit(List)

def exit(List):
    file = input("Enter a File Name: ")
    inFile = open(file, 'w')
    for index in range(0 , len(List) - 1):
        inFile.write(str(List[index]) + '\n')
    inFile.close()
    print("\nHave a nice day ;)")
    
def addScores(List):
    testScore = int(input("\nEnter first testscore (Enter -1 to quit): "))
    while (testScore != -1):
        while (testScore > 100) or (testScore < 0):
            testScore = int(input("Invalid Score: Enter a valid score (0-100): "))
        List.append(testScore)
        testScore = int(input("Enter next score (Enter -1 to quit): "))  
    choices(List)
    
def scoresEntered(List):
    if (len(List) == 0):
        print("\nNo scores entered!")
        choices(List)
    print("\nScores Entered:", end=' ')
    for index in range(0, len(List) - 1):
        print(List[index], end=' ')
    print()
    choices(List)
    
def main():
    scores = []
    choices(scores)
    
main()