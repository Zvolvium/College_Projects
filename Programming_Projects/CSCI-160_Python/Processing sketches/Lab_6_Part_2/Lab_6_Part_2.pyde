'''
Mason Motschke 
CSCI 160
Thursday, 5 - 7 pm
Writing the initials to my full name
'''
size (1000, 1000)
background (255, 255, 255)
myColor = color(72, 83, 242)
shadow = color(0, 0, 0)
    
def drawM (x, y, letterColor):
    #noStroke()
    #rect (x, y, 200, 200)
    fill (letterColor); noStroke()
    rect (x, y, 25, 200); rect (x + 175, y, 25, 200) #Sides
    fill (255, 255, 255) #Top Cut offs
    triangle (x, y, x + 25, y, x + 25, y + 25); triangle (x + 175, y, x + 175, y + 25, x + 200, y)
    fill (letterColor) #Middle Pieces
    quad (x, y, x, y + 25, x + 100, y + 100, x + 100, y + 75)
    x = x + 100; y = y + 75
    quad (x, y, x, y + 25, x + 100, y - 50, x + 100, y - 75)
    
def drawA (x, y, letterColor):
    fill(letterColor); noStroke()
    quad (x, y + 200, x + 25, y + 200, x + 110, y, x + 85, y)
    quad (x + 200, y + 200, x + 175, y + 200, x + 85, y, x + 110, y)
    rect (x + 60, y + 85, 85, 25)
    
def drawShadowedLetterM(x, y, letterColor, offset):
    drawM(x + offset, y, shadow)
    drawM(x, y, letterColor)
    
def drawShadowedLetterA(x, y, letterColor, offset):
    drawA(x + offset, y, shadow)
    drawA(x, y, letterColor)
    
def drawInitalsH(x, y):
    drawM (x, y, myColor)
    drawA (x + 250, y, myColor)
    drawM (x + 500, y, myColor)
    
def drawInitalsV(x, y):
    drawM (x, y, myColor)
    drawA (x, y + 250, myColor)
    drawM (x, y + 500, myColor)
    
drawInitalsH(100, 25)
#drawInitalsV(100, 250)

drawShadowedLetterM(100, 400, myColor, 10)
drawShadowedLetterA(350, 400, myColor, 10)
drawShadowedLetterM(600, 400, myColor, 10)

'''
#Starting Boxes
noStroke()
rect (x, y, 200, 200)
rect (x + 250, y, 200, 200)
rect (x + 500, y, 200, 200)

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
'''
