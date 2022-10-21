'''
Mason Motschke @ mason.motschke@und.edu
CSCI 160
Thursday Lab 5-7 
'''
#Functions ---->
def drawSquares():
    y = 0
    carrot = "^"
    length = int(input("Length of the square? "))
    while (length <= 0):
        print("Error: Length Negative or Zero")
        length = int(input("Length of the square? "))
    width = int(input("Width of the square? "))
    while (width <= 0):
        print("Error: Width Negative or Zero")
        width = int(input("Width of the square {Above Zero}? "))
    carrot = carrot * length
    print("Here is the square: ")
    while (y < width):
        print(carrot)
        while (y < (width - 2)):
            print("^" + ((length - 2) * " ") + "^")
            y += 1
        y += 1    
        
def drawLines():
    carrot = "^"
    length = int(input("How long do you want the line? "))
    while (length <= 0):
        print("Error: Length Negative or Zero")
        length = int(input("How long do you want the line {Above Zero}? "))
    carrot = carrot * length
    print("Here is the line: " + carrot) 
    
def drawTriangles():
    counter = 0
    carrot = "^"
    x = 1
    width = int(input("Width of the triangle? "))
    while (width <= 0):
        print("Error: Width Negative or Zero")
        width = int(input("Width of the triangle {Above Zero}? "))
    print("Here is the triangle: ")
    while (counter < width):
        carrot = x * carrot
        print(carrot)
        carrot = "^"
        x += 1
        counter += 1 
        
def drawPyramids():
    height = int(input("Height of the pyramid? "))
    while (height <= 0):
        print("Error: Height nagative or Zero")
        height = int(input("Height of the pyramid {Above Zero}? "))
    x = 1
    y = height
    counter = 0
    carrot = "^"
    addCar = "^^"
    print("Here is the pyramid: ")
    while (counter < height):
        print((" " * y) + carrot)
        carrot = carrot + addCar
        counter += 1
        y -= 1
#<---- Functions

user = str(input("What shape do you want to draw? "))
while ((user == "Square") or (user == "square") or (user == "Line") or (user == "line") or (user == "Triangle") or (user == "triangle") or (user == "Pyramid") or (user == "pyramid")) == False:
    print("Error: INVALID SHAPE")
    user = str(input("Re-Enter Valid Shape {square, line, triangle, pyramid}: "))

if (user == "Line") or (user == "line"): #Drawing the Line's
    drawLines()
    
elif (user == "Square") or (user == "square"): #Drawing the Square's
    drawSquares()
        
elif (user == "Triangle") or (user == "triangle"): #Drawing the Triangle's
    drawTriangles()
        
elif (user == "Pyramid") or (user == "pyramid"): #Drawing the Pyramid's
    drawPyramids()