'''
Mason Motschke
CSCI-161
Thursday Lab 5-7
Program #4
'''
import os

def reverseOrder(string):
    reverseList = []
    words = string.split(' ')
    for index in range(len(words) - 1, -1, -1):
        reverseList.append(words[index])
        
    rString = ' '.join([str(index) for index in reverseList])
    print("Reversed String: " + rString)
    usersChoice(string)
    
def countWords(string):
    words = string.split(' ')
    numOfWords = len(words)
    print("Number of Words:", numOfWords)
    usersChoice(string)
    
def numNonWhiteSpaceChar(string):
    NwS_Char = 0
    for place in string:
        if (place != " "):
            NwS_Char += 1
            
    print("Number of non-Whitespace characters:", NwS_Char)
    usersChoice(string)
    
def replacePuncuation(string, exclamationCount, semicolonCount):
    stringList = []
    exCount = exclamationCount
    semiCount = semicolonCount
    for x in string:
        stringList.append(x)
        
    for index in range(0, len(stringList)):
        if (stringList[index] == '!'):
            stringList[index] = '.'
            exCount += 1
        if (stringList[index] == ';'):
            stringList[index] = ','
            semiCount += 1
            
    updatedString = ''.join([str(index) for index in stringList])
    print("\nPunctuation Updated")
    print("exclamationCount:", exCount)
    print("semicolonCount:", semiCount)
    print("Edited Text:" + updatedString)
    usersChoice(string)
    
def usersChoice(string):
    menu()
    choice = input("What do you want to do? ")
    if (choice.lower() == 'q'):
        print("\nGoodbye ^_^")
        os._exit(0)
    elif (choice.lower() == 'c'):
        numNonWhiteSpaceChar(string)
    elif (choice.lower() == 'w'):
        countWords(string)
    elif (choice.lower() == 'r'):
        reverseOrder(string)
    elif (choice.lower() == 'p'):
        replacePuncuation(string, 0, 0)
    else:
        print("I don't understand")
        userChoice(string)
    
def menu():
    print('\n' + "-" * 30)
    print('{:^20}'.format("MENU"))
    print("C - Number of non-whitespace characters")
    print("W - Number of Words")
    print("R - Reverse the order of the words in the sentence")
    print("P - Replace punctuation")
    print("Q - Quit")
    print("-" * 30)
    
def main():
    user = input("Enter Text of your Choice: ")
    usersChoice(user)
    
main()