'''
Mason Motschke @ mason.motschke@und.edu
Thursday Lab 5-7
Lab Test
'''
def percent(totalNum, majorCount):
    percent = (majorCount / totalNum) * 100
    return percent
    
# Starting Variables
compSciCount = 0
dataSciCount = 0
cyberCount = 0
randomCount = 0
percentCount = 0

# Main
major = str(input("Enter your Major: "))
while (major != " "):
    if (major == "CompSci"):
        compSciCount += 1
        percentCount += 1
    elif (major == "DataSci"):
        dataSciCount += 1
        percentCount += 1
    elif (major == "Cyber"):
        cyberCount += 1
        percentCount += 1
    else:
        randomCount += 1
        percentCount += 1
    major = str(input("Enter your Major (To stop enter a Space): "))

majorPercent = percent(percentCount, compSciCount)
print("\nTotal Number of people in CompSci:", format(compSciCount, " >8"))
print("Percentage of Computor Science Majors:", format(majorPercent, "0.2f"))

majorPercent = percent(percentCount, dataSciCount)
print("\nTotal Number of people in DataSci:", format(dataSciCount, " >8"))
print("Percentage of Data Science Majors:", format(format(majorPercent, "0.2f"), " >8"))

majorPercent = percent(percentCount, cyberCount)
print("\nTotal Number of people in Cyber:", format(cyberCount, " >10"))
print("Percentage of Data Science Majors:", format(format(majorPercent, "0.2f"), " >8"))

majorPercent = percent(percentCount, randomCount)
print("\nTotal Number of people in Other Majors:", format(randomCount, " >3"))
print("Percentage of Other Majors:", format(format(majorPercent, "0.2f"), " >15"))