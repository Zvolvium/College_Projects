'''
Mason Motschke @ mason.motschke@und.edu
CSCI 160
Thursday Lab 5-7
'''
posCounter = 0
negCounter = 0
positiveNum = 0
negetiveNum = 0

a = int(input("Enter an integer (Enter 0 when finished): "))
while (a != 0): 
    if a > 0:
        positiveNum += a
        posCounter += 1
    elif a < 0:
        negetiveNum += a
        negCounter += 1
    a = int(input("Enter an integer (Enter 0 when finished): "))

if (posCounter == 0):
    posCounter = 1
if (negCounter == 0):
    negCounter = 1
positiveAv = positiveNum / posCounter
negetiveAv = negetiveNum / negCounter
print("Average of positive values:", format(positiveAv, "1.2f"))
print("Average of Negetive values:", format(negetiveAv, "1.2f"))
    
        
