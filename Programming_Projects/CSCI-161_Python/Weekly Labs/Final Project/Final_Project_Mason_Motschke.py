'''
Mason Motschke
CSCI 161
Thursday Lab 5-7
Final Project
'''
import sys

def lowerCase(List):
    for x in range (len(List)):
        List[x] = List[x].lower()
    return List
    
def main():
    searchWords = {} #Part 1
    totalWordNum = 0
    fileToOpen = 'words.txt'
    try:
        openFile = open(fileToOpen)
    except:
        raise ("Error: File does not exist!")
    print("Collecting Search Words...")
    for line in openFile: #adds searchWords to dict with default 0 count
        line = line.strip()
        searchWords[line] = 0
    openFile.close()
    
    fileToRead = sys.argv[-1] #Part 2
    #fileToRead = 'moby_test.txt' #comment out before submission!!!
    keys = searchWords.keys()
    print("\nReading Input File...")
    with open(fileToRead, 'rb') as openFile:
        for bline in openFile: #Decode error for char workaround
            try:
                line = bline.decode()
                line = line.strip(); line = line.split(' ')
                line = lowerCase(line)
                for word in line:
                    if (word in keys):
                        searchWords[word] += 1
                    totalWordNum += 1                       
            except: #Skips line if decode error happens
                continue 
    openFile.close()
    
    #Output - - - - - - - - - - - - - - - - - - - -
    print("\nOutputing File...")
    fileToWrite = 'final-output.txt' #Part 3
    openFile = open(fileToWrite, 'w')
    for word in keys:
        percent = (searchWords[word] / totalWordNum) * 100
        openFile.write("{0} {1:1.4f}\n".format(word, percent))
    openFile.close()
    print("- - - File Output Complete - - -")
            
main()