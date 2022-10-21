'''
Mason Motschke 
CSCI 160
Thursday, 5 - 7 pm
Writing the initials to my full name
'''
#SetUp
size (1000, 1000)
background (255, 255, 255)

#Starting Variables
x = 100; y = 400

#Starting Boxes
noStroke()
rect (x, y, 200, 200); rect (x + 250, y, 200, 200); rect (x + 500, y, 200, 200)

#Drawing Letter - # 1: M
fill (72, 83, 242); noStroke()
rect (x, y, 25, 200); rect (x + 175, y, 25, 200) #Sides
fill (255, 255, 255) #Top Cut offs
triangle (x, y, x + 25, y, x + 25, y + 25); triangle (x + 175, y, x + 175, y + 25, x + 200, y)
fill (72, 83, 242) #Middle Pieces
quad (x, y, x, y + 25, x + 100, y + 100, x + 100, y + 75)
x = x + 100; y = y + 75
quad (x, y, x, y + 25, x + 100, y - 50, x + 100, y - 75)

#Drawing Letter - # 2: M
x = 600; y = 400
fill (72, 83, 242);
rect (x, y, 25, 200); rect (x + 175, y, 25, 200) #Sides
fill (255, 255, 255) #Top Cut offs
triangle (x, y, x + 25, y, x + 25, y + 25); triangle (x + 175, y, x + 175, y + 25, x + 200, y)
fill (72, 83, 242) #Middle Pieces
quad (x, y, x, y + 25, x + 100, y + 100, x + 100, y + 75)
x = x + 100; y = y + 75
quad (x, y, x, y + 25, x + 100, y - 50, x + 100, y - 75)

#Drawing Letter - A
x = 350; y = 400
quad (x, y + 200, x + 25, y + 200, x + 110, y, x + 85, y)
quad (x + 200, y + 200, x + 175, y + 200, x + 85, y, x + 110, y)
rect (x + 60, y + 85, 85, 25)
