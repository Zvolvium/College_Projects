'''
Mason Motschke
CSCI-161
Thursday Lab 5-7
Program #5
'''
def printTable(Title, Header1, Header2, sList, iList):
    print('\n{:^61}'.format(Title))
    print('{:<30}'.format(Header1) + "|" + '{:>30}'.format(Header2))
    print("-" * 61)
    for index in range (0, len(sList)):
        print('{:<30}'.format(sList[index]) + "|" + '{:>30}'.format(iList[index]))
        print("-" * 61)
    
def main():
    strings = []
    ints = []
    
    title = str(input("Enter Title of Data: "))
    print("You Entered: " + title)
    
    column1Head = str(input("\nEnter Header for Column 1: "))
    print("You Entered: " + column1Head)
    
    column2Head = str(input("\nEnter Header for Column 2: "))
    print("You Entered: " + column2Head)
    
    data = str(input("\nEnter first data point (-1 to Quit): "))
    while (data != '-1'):
        numTest = data.split(', ')
        if (data.count(',') > 1):
            print("    Error: Too many commas in input!")
        elif (data.count(',') < 1):
            print("    Error: No comma in string!")
        elif (numTest[1].isnumeric() == False):
            print("    Error: Comma not followed by integer!")
        else:
            data = data.split(', ')
            print("Data String: " + data[0]); print("Data integer: " + data[1])
            strings.append(data[0])
            ints.append(int(data[1]))
        data = str(input("\nEnter next data point (-1 to Quit): "))
        
    printTable(title, column1Head, column2Head, strings, ints)
    
main()