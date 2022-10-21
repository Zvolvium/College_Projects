'''
Mason Motschke @ mason.motschke@und.edu; ID: 1253634
CSCI 160
Thursday Lab 5-7
Lab Final
'''
def displayOptions():
    print("\nWhat do you want to do?")
    print("   1) Add food to the menu")
    print("   2) Print all food items")
    print("   3) Search for a food item")
    print("   4) Take an order")
    print("   5) Search by price")
    print("   6) Exit")
    
def optionTab(Dict):
    displayOptions()
    user = int(input("\nWhat is your choice? "))
    if (user == 1):
        addItem(Dict)
    elif (user == 2):
        printMenu(Dict)
    elif (user == 3):
        searchMenu(Dict)
    elif (user == 4):
        order(Dict)
    elif (user == 5):
        priceSearch(Dict)
    elif (user == 6):
        exit(Dict)
        
def exit(Dict):
    file = 'food.txt'
    inFile = open(file, 'w')
    for key in Dict:
        inFile.write(key + ':' + str(Dict[key]) + '\n')
    inFile.close()
    
def priceSearch(Dict):
    high = float(input("Enter highest price to search for: "))
    low = float(input("Enter lowest price to search for: "))
    for key in Dict:
        if (Dict[key] > low) and (Dict[key] < high):
            print(key, end= ',')
    print()
    optionTab(Dict)
    
def order(Dict):
    orderedFood = []
    food = input("\nWhich item would you like? ")
    while (food != ''):
        order = Dict.get(food.lower())
        if (order == None):
            food = input("Next item: ")
        else:
            num = int(input("How many would you like? "))
            totalPrice = Dict[food] * num # Messed up (doesn't add up all orders just gets set value of the last)
            orderedFood.append(food)
            food = input("Next item (ENTER to quit): ").lower()
    print("\nFood Ordered:", end= '')
    for index in range(len(orderedFood)):
        print(orderedFood[index], end= ' ')
    print()
    print("Total Price: $", end= '')
    print('%7.2f' % (totalPrice))
    optionTab(Dict)
    
def printMenu(Dict):
    print("Current food items: ")
    for key in Dict:
        print('%-10s%10.2f' % (key, Dict[key]))
    optionTab(Dict)
    
def searchMenu(Dict):
    find = input("What item would you like to find? ")
    while (find != ''):
        notFound = 1
        for key in Dict:
            if (find.lower() == key.lower()):
                print("Cost:", end=' ')
                print('%10.2f' % (Dict[key]))
                notFound = 0
        if (notFound == 1):
            print("We don't have that item on the Menu")
        find = input("\nNext item to search for (Hit ENTER to quit): ")
    optionTab(Dict)
    
def addItem(Dict):
    newItem = input("\nWhat food item do you want to add to the menu? ")
    while (newItem != ''):
        price = input("Items price: ")
        Dict[newItem.lower()] = float(price)
        newItem = input("Next item (Hit ENTER to quit): ")
    optionTab(Dict)
    
def openFile(Dict):
    file = 'food.txt'
    inFile = open(file, 'r')
    for line in inFile:
        line = line.strip()
        line = line.split(':')
        Dict[line[0].lower()] = float(line[1].lower())
    
def main():
    menu = {}
    openFile(menu)
    optionTab(menu)
    
main()