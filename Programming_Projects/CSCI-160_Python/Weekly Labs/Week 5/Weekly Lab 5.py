'''
Mason Motschke @ mason.motschke@und.edu
CSCI 160
Thursday Lab 5-7
'''
def honorPointCalc(letterGrade):
    if (letterGrade == "A"):
        honorPoints = 4 * creditNum
    elif (letterGrade == "B"):
        honorPoints = 3 * creditNum
    elif (letterGrade == "C"):
        honorPoints = 2 * creditNum
    elif (letterGrade == "D"):
        honorPoints = 1 * creditNum
    return honorPoints

def GPA(honor, attCredits):
    if (attCredits != 0):
        gpaTotal = honor / attCredits
    else:
        gpaTotal = 0.0
    return gpaTotal

#Variables --->       
honorPointTotal = 0
creditsAttempted = 0
creditsPassed = 0
classAttemptCount = 0
classPassCount = 0
# <---

className = str(input("Enter a Class you are taking this semester: "))
while (className != " "):
    creditNum = int(input("Enter Number of Credits for Class: "))
    classGrade = str(input("Enter your Class Grade (A-F): ")); print(" ")
    creditsAttempted = creditsAttempted + creditNum
    classAttemptCount += 1
    if (classGrade >= "A") and (classGrade < "F"):
        classPassCount += 1
        creditsPassed = creditsPassed + creditNum
        honorPoints = honorPointCalc(classGrade)
        honorPointTotal += honorPoints
    
    className = str(input("Enter the next Class you are taking this semester {Enter a space to finish}: "))

GPA = GPA(honorPointTotal, creditsAttempted)
#Output --->
print()
txt = "GPA: {:>20} "; print(txt.format(format(GPA, "1.3f")))
txt = "Credits Attempted: {:>6} "; print(txt.format(creditsAttempted))
txt = "Credits Passed: {:>9}"; print(txt.format(creditsPassed))
txt = "Classes Attempted: {:>6} "; print(txt.format(classAttemptCount))
txt = "Classes Passed: {:>9} "; print(txt.format(classPassCount))
print()
# <---