'''
Mason Motschke @ mason.motschke@und.edu
CSCI 160
Thursday Lab 5-7
Lab 6 Part 1
'''
def square(intValue):
    '''
    Finds the square of inputed value. Return Value is "root."
    Parameters: intValue = number in range (Negative Infinity, Infinity)
    ''' 
    root = intValue ** 2
    return root

def summation(intValue):
    '''
    Finds summation of given value. Return Value is "num."
    Parameters: intValue = Whole Number greater than zero
    '''
    num = 0
    for x in range (1, intValue + 1):
        num = num + x
    return num

def sumOfSquare(intValue): 
    '''
    Finds the sum of the squares starting at 1 and ending at intValue. Return Value is "num."
    Parameters: intValue = number in range [0, Infinity) 
    '''
    num = 0
    for x in range(1, intValue + 1):
        num = num + square(x)
    return num

def factorial(intValue):
    '''
    Finds the Factorial of the number intValue. Return Value is "num."
    Parameters: intValue = number in range [0, Infinity)
    '''
    if intValue == 0:
        num = 0
    else:
        num = 1
        
    for x in range(1, intValue + 1):
        num = num * x
    return num
    
def distance(x1, y1, x2, y2):
    '''
    Finds the distance between two points; (x1, y1) is first point, (x2, y2) is second point.
    Parameters: number(s) in range (Negative Infinity, Infinity); Return Value is "final."
    '''
    import math
    xDiff = (x2 - x1) ** 2
    yDiff = (y2 - y1) ** 2
    final = math.sqrt(xDiff + yDiff)
    return final

def isOdd(intValue):
    '''
    Finds if the inputed value is odd or not. Retrun value is "result."
    Parameters: intValue = a number in range (Negative Infinity, Infinity)
    '''
    intValue = int(intValue)
    if (intValue % 2 != 0):
        result = True
    else: 
        result = False
    return result

def isEven(intValue):
    '''
    Finds if the inputed value is Even or not. Return Value is "finalT_F."
    Parameters: intValue = a number in range (Negative Infinity, Infinity)
    '''
    result = isOdd(intValue)
    if (result == False):
        finalT_F = True
    else:
        finalT_F = False
    return finalT_F

def main():
    a = 0
    b = 0
    c = 0
    d = 0
    e = 0
    f = 0
    g = 0
    
    a = square(9)
    b = summation(8)
    c = sumOfSquare(14)
    d = factorial(4)
    e = distance(8, 4, 13, 9)
    f = isOdd(1.7 * (10 ** 6))
    g = isEven(1.7 * (10 ** 6))
    return a, b, c, d, e, f, g

print(main())