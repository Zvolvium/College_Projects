'''
Mason Motschke
CSCI 160
9/19/2019
'''
a = float(input("Input a numeric value:"))
if a % 1 == 0:
    print(a, "is a whole number")
else:
    print(a, "is not a whole number")
if a % 5 == 0: 
    print(a, "is a mulitple of 5")
else: 
    print(a, "is not a mulitple of 5")
if a % 2 == 0:
    print(a, "is even")
else: 
    print(a, "is odd")
if a > 0:
    print(a, "is positive")
elif a == 0:
    print(a, "is zero")
elif a < 0:
    print(a, "is negative")
if a >= 2010 and a <= 2019:
    print(a, "is within the range of 2010 and 2019")
else:
    print(a, "is not within the range of 2010 and 2019")
if (a >= 100 and a < 200) or (a <= -100 and a > -200):
    print(a, "is within the 100's")
else:
    print(a, "is not within the 100's")

user = str(input("Enter text:"))
print(user, "has", len(user), "characters")
if user == "yes":
    print(user, "is yes")
elif user == "no":
    print(user, "is no")
else: 
    print(user, "is neither yes or no")
if (user == "yes"):
    print(user, "is lowercase")
elif user == "YES":
    print(user, "is Uppercase")
if user < "b":
    print(user, "starts with an 'a'")
else:
    print(user, "doesn't start with an 'a'")
    
    
    