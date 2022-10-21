'''
Mason Motschke
CSCI-161
Thursday Lab 5-7
Program #3 Part 1
'''
def betweenSkipMult_3(num1, num2):
    print("\nValues between", num1, "and", num2, "skipping multiples of 3:")
    for x in range(num1, num2 + 1, 2):
        if (x % 3 == 0):
            continue
        else:
            print(x)
    
def betweenVal(num1, num2):
    print("\nValues between", num1, "and", num2, "by 2's:")
    for x in range(num1, num2 + 1, 2):
        print(x)
        
def primeNum(num1, num2):
    x = num1
    print("\nPrime Values between", num1, "and", num2, ":")
    while (num1 <= x <= num2):
        if ((x % 2 == 0) or (x % 3 == 0) or (x % 5 == 0) or (x % 7 == 0) or (x % 11 == 0)):
            if ((x == 2) or (x == 3) or (x == 5) or (x == 7) or (x == 11)):
                print(x)
        else:
            if (x != 1):
                print(x)
        x += 1            
        
def main():
    low = int(input("Enter the Minimum Value: "))
    high = int(input("Enter the Maximum Value: "))
    assert low < high
    primeNum(low, high)
    betweenVal(low, high)
    betweenSkipMult_3(low, high)
    
main()