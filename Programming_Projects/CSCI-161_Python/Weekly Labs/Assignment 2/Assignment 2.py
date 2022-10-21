'''
Mason Motschke 
CSCI-161
Thursday Lab 5-7
Program #2
'''
def multOfEachother(V1, V2):
    if (V1 % V2 == 0):
        print("Value 1 is a multiple of Value 2")
    else:
        print("Value 1 is not a multiple of Value 2")
    if (V2 % V1 == 0):
        print("Value 2 is a multiple of Value 1")
    else:
        print("Value 2 is not a multiple of Value 1")
    
def equalOrNot(V1, V2):
    if (V1 > V2):
        print("Value 1 is greater")
    elif (V1 < V2):
        print("Value 2 is greater")
    elif (V1 == V2):
        print("Values 1 and 2 are equal")
    
def in1000s(Value):
    if (( -1000>= Value) or (Value >= 1000)):
        print("Value is within the 1000's")
    else:
        print("Value is not within the 1000's")
    
def inRange(Value):
    if (10 <= Value <= 99):
        print("Value is in range {10-99}")
    else:
        print("Value is out of range {10-99}")
    
def allignmentTest(Value):
    if (Value > 0):
        print("Value is Positive")
    elif (Value < 0):
        print("Value is Negative")
    else:
        print("Value is Zero")
    
def multiple_9(Value):
    if (Value % 9 == 0):
        print("Value is a Multiple of 9")
    else:
        print("Value is not a Multiple of 9")
    
def wholeNumTest(Value):
    string = str(Value)
    if (Value % 1 > 0):
        print('\n' + string + " is not a Whole Number")
    else:
        print('\n' + string + " is a Whole Number")
        
def main():
    user = float(input("Enter first Value (EX: 10): "))
    wholeNumTest(user)
    multiple_9(user)
    allignmentTest(user)
    inRange(user)
    in1000s(user)
    user2 = float(input("\nEnter second Value: "))
    equalOrNot(user, user2)
    multOfEachother(user, user2)
    
main()