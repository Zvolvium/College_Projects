'''
Mason Motschke @ mason.motschke@und.edu; ID: 1253634
CSCI 160
Thursday Lab 5-7
'''
import FileUtils
import os
def checkDictionary(List, searchWord):
    check = List.get(searchWord.lower())
    if (check == None):
        print("I don't know this word.")
    else:
        print("German translation is", List[searchWord.lower()])
    
def main():
    fileName = FileUtils.selectOpenFile("Select a File to Open")
    if (fileName == None):
        os._exit(0)
    inFile = open(fileName, 'r')
    words = {}
    for line in inFile:
        line = line.strip()
        line = line.split(":")
        words[line[0]] = line[1]
    inFile.close()
    searchWord = input("Enter an English word to get the German translation: ")
    while (searchWord != ""):
        checkDictionary(words, searchWord)
        searchWord = input("\nEnter next word(Press ENTER to quit):")
    
main()