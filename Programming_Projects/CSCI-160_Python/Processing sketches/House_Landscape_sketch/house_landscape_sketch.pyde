'''
Mason Motschke
mason.motschke@und.edu
CSCI 160-02
Program to draw House with background
'''
size (1000,1000)

#Sky + Sun
background (24,149,244) #Sky
fill (243,250,42); stroke (243,250,42) #Sun -->
ellipse (900,100,150,150) #<--

#Grass + Tree
fill (0,200,0); stroke (0,200,0)
rect (0,600,1000,400) #Grass
stroke (128, 124, 98); fill (128, 124, 98)
rect (150, 400, 100, 400) #Tree
fill (124, 235, 135); stroke (124, 235, 135) #Leaves -->
rect (100, 325, 200, 200)
fill (39, 236, 59); stroke (39, 236, 59) 
rect (125, 350, 100, 150)
fill (45, 166, 57); stroke (45, 166, 57)
rect (150, 375, 125, 100)
fill (13, 211, 33); stroke (13, 211, 33)
rect (215, 355, 75, 135) #<--
fill (255, 15, 15); stroke (255, 15, 15) #Apples -->
ellipse (150, 375, 10, 10); ellipse (220, 400, 10, 10)
ellipse (175, 500, 10, 10); ellipse (275, 450, 10, 10)
ellipse (140, 450, 10, 10); ellipse (275, 355, 10, 10) #<--

#House + House Details
stroke (231, 231, 226); fill (231, 231, 226)
rect (550, 500, 400, 300) #House
stroke (144, 56, 56); fill (144, 56, 56)
triangle (750, 380, 515, 500, 985, 500) #Roof
fill (0,0,0); stroke (0,0,0) #Door -->
rect (730, 725, 40, 75)
fill (252,219,33); stroke (252,219,33)
ellipse (765, 762.5, 5, 5) #<--
fill (244, 63, 199); stroke (0, 0, 0) #Windows -->
rect (600, 550, 50, 50); rect (850, 550, 50, 50)
fill (0,0,0)
rect (625, 550, 1, 50); rect (600, 575, 50, 1)
rect (875, 550, 1, 50); rect (850, 575, 50, 1) #<--
