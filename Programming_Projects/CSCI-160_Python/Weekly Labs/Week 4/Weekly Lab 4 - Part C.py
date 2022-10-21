'''
Mason Motschke @ mason.motschke@und.edu
CSCI 160
Thursday Lab 5-7
'''
multNum = int(input("Enter a value to multiply by (1-10): "))
print("")
if (multNum > 10) or (multNum < 1):
    print("Error: Input is INVALID ")
else: 
    print("Multiplication table for:", multNum)
    print("")
    for x in range (1, 11):
        finalMult = (multNum * x)
        if (multNum >= 10):
            print(format(x, "2d"), "*", multNum, "=", format(finalMult, "3d"))
        else:
            print(format(x, "2d"), "*", multNum, "=", format(finalMult, "2d"))
    
