'''
Mason Motschke @ mason.motschke@und.edu
CSCI 160
Thursday Lab @ 5-7
'''
earnedCredits = int(input("How many credits have you earned so far in college? "))
currentCredits = int(input("How many credits are you taking this semester? "))

#Current Semester Calculation
if earnedCredits >= 0 and earnedCredits <= 23:
    print("Current Status: Freshman")
elif earnedCredits >= 24 and earnedCredits <= 59:
    print("Current Status: Sophomore")
elif earnedCredits >= 60 and earnedCredits <= 89:
    print("Current Status: Junior")
elif earnedCredits >= 90:
    print("Current Status: Senior")
    
#Next Semester calculation   
nextSemester = int(earnedCredits + currentCredits)
if nextSemester >= 0 and nextSemester <= 23:
    print("Future Status for next semester: Freshman")
elif nextSemester >= 24 and nextSemester <= 59:
    print("Future Status for next semester: Sophomore")
elif nextSemester >= 60 and nextSemester <= 89:
    print("Future Status for next semester: Junior")
elif nextSemester >= 90:
    print("Future Status for next semester: Senior")

#Future Semester Calculation
gradCredits = int(120 - nextSemester)
print("Minimum credits to graduate after this semester for most degree's:", gradCredits)
semestersLeft = int(gradCredits / 15)
print("Semesters left till graduation @ 15 credits per semester:", semestersLeft)
