'''
Mason Motschke @ mason.motschke@und.edu
CSCI 160
Thursday Lab @ 5-7
'''
user_input = int(input("Enter a number between 20 and 99: "))

if user_input > 99 or user_input < 20:
    print("Error: Input not in range of 20 and 99!")
else: 
    a = user_input % 10
    b = user_input % 100
    c = int((b - a) / 10)
    
    ones = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    tens = ["Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
    
    print("The number is:", tens[c - 2], ones[a])