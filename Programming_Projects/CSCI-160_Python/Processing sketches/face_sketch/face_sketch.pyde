'''
Mason Motschke
mason.motschke@und.edu
CSCI 160-02
Drawing of a weird face
'''
size (1000, 1000)

#background + head
background (77, 240, 68)
fill (240, 231, 68)
ellipse (500, 500, 600, 600)

#Facial Details
fill (0, 0, 0)
ellipse (400, 400, 75, 100); ellipse (600, 400, 75, 100) #eyes -->
fill (68, 186, 240); ellipse (400, 400, 25, 50); ellipse (600, 400, 25, 50) #<--
fill (0, 0, 0,); ellipse (500, 650, 200, 100) #mouth
rect (475, 400, 50, 100); ellipse (500, 500, 100, 50)
