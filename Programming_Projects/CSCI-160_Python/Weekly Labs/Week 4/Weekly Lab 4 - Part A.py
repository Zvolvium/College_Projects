'''
Mason Motschke @ mason.motschke@und.edu
CSCI 160
Thursday Lab 5-7
'''
print("Part 1: ")
for z in range(10,51):
    print(z)

print("Part 2: ")
for y in range(20, -1, -1):
    print(y)
    
print("Part 3: ")
x = 0
while x <= 10:
    print(x)
    x += .5

print("Part 4: ")
w = input("Enter a single letter, Ex: 'a': ")
lowerCase = 0
upperCase = 0
while (w != "q") and (w != "Q"):
    print("Letter entered was:", "'" + w + "'")
    if (w >= "a") and (w <= "z"):
        lowerCase += 1
    elif (w >= "A") and (w <= "Z"):
        upperCase += 1
    w = input("Enter a single letter, Enter 'q' or 'Q' to quit: ")
    
print("Number of Lowercase letters entered:", lowerCase)
print("Number of Uppercase letters entered:", upperCase)