'''
Mason Motschke @ mason.motschke@und.edu; ID: 1253634
CSCI 160
Thursday Lab 5-7
Lab Test 2 - Part 1
'''
def main():
    fileName = input("Enter a file Name: ")
    inFile = open(fileName, 'w')
    score = int(input("Enter the score for the first hole: "))
    while (score > 10 or score < 1):
        score = int(input("Enter a valid score (1-10): "))
    while (score != -1):
        inFile.write(str(score) + '\n')
        score = int(input("Enter the next score (Enter -1 to exit): "))
        if (score == -1):
            inFile.close()
            return
        while (score > 10 or score < 1):
            score = int(input("Enter a valid score (1-10): ") )
    
main()