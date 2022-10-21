'''
Mason Motschke
CSCI-161
Thursday Lab 5-7
Program #10
'''
import os #Starting Program #9
class ShoppingCart:
    def __init__(self):
        self.costomer_name = 'None'
        self.current_date = 'None'
        self.cart_items = []
        
    def add_item(self, itemToAdd):   
        self.cart_items.append(itemToAdd)
    
    def get_cost_of_cart(self):
        totalCost = 0
        for item in self.cart_items:
            item.print_item_cost()
            totalCost = totalCost + (item.price * item.quantity)    
        return totalCost
        
    def print_total(self, totalCost):
        if (self.cart_items == []):
            print("Shopping cart is Empty")
        else:
            print("\nTotal: ${0:1.2f}".format(totalCost))
            
    def print_descriptions(self):
        if (self.cart_items == []):
            print("\n    No Items in cart!")
        else:
            print("\nOutput item descriptions")
            print("{}'s Shopping Cart - {}".format(self.costomer_name, self.current_date))
            print()
            for item in self.cart_items:
                item.print_item_description()        
                
    def remove_item(self):
        if (self.cart_items == []):
            print("Cart is empty! No items to remove!")
        else:
            itemToRemove = str(input("Enter item to remove: "))
            for item in self.cart_items:
                if (item.name == itemToRemove):
                    self.cart_items.remove(item)
                    print("Item Found: Item has been removed")
                    
    def print_modify_items_menu(self):
        print("\n    What would you like to modify?")
        print("    q - Quantity"); print("    p - Price"); print("    d - Description")
        
    def modify_item(self):
        if (self.cart_items == []):
            print("Cart is empty! No items to modify!")
        else:
            itemToModify = str(input("Enter item to modify: "))
            flag = 0
            for item in self.cart_items:
                if (item.name == itemToModify):
                    flag = 1
                    self.print_modify_items_menu()
                    user = str(input("    Enter choice: "))
                    if (user.lower() == 'q'):
                        item.quantity = int(input("    Enter new quantity(EX: 5): "))
                    elif (user.lower() == 'p'):
                        item.price = float(input("    Enter new price(EX: 5.00): "))
                    elif (user.lower() == 'd'):
                        item.describe = str(input("    Enter new description: "))
            if (flag == 0):
                print("Item Not Found: Item isn't in the cart")
    
    def write_reciept_to_file(self):
        fileName = self.costomer_name
        openFile = open(fileName, 'w')
        openFile.write("---RECEIPT---\n"); openFile.write('\n')
        openFile.write(self.costomer_name + " - " + self.current_date + '\n')
        numOfItems = 0
        for item in self.cart_items:
            numOfItems += 1
        openFile.write("Number of Items: " + str(numOfItems) + '\n')
        openFile.write('\n')
        totalCost = 0
        for item in self.cart_items:
            openFile.write("{0} {1} @ ${2:1.2f} = ${3:1.2f}".format(item.name, item.quantity, item.price, (item.price * item.quantity)) + '\n')
            openFile.write("-Item Decription: " + "{0}".format(item.describe) + '\n')
            totalCost = totalCost + (item.price * item.quantity)
        
        openFile.write('\n'); openFile.write("Total: " + "${0:1.2f}".format(totalCost) + '\n')
        openFile.write('\n'); openFile.write("---RECIEPT---")
        openFile.close
        
    def view_receipt_file(self):
        file = self.costomer_name
        try:
            openFile = open(file, 'r')
            for line in openFile:
                line = line.strip()
                print(line)
        except:
            print("    File-Error: File can't be found!")
        
class ItemToPurchase:
    def __init__(self):
        self.name = "none"
        self.describe = "none" #Bug Found: "describe" was spelled as "decribe" ^
        self.price = 0    #Float
        self.quantity = 0   #Int
        
    def print_item_cost(self):
        print("{0} {1} @ ${2:1.2f} = ${3:1.2f}".format(self.name, self.quantity, self.price, (self.price * self.quantity)))
        
    def print_item_description(self):
        print("{0}: {1}".format(self.name, self.describe)) # ^
        
def printMenu():
    print("\nMenu")
    print("a - Add item to cart")
    print("r - Remove item from the cart")
    print("m - Modify item")
    print("i - Output items' descriptions")
    print("o - Output shopping cart")
    print("f - Finalize order")
    print("v - View receipt")
    print("q - Quit")

def menu_select(Cart):
    printMenu()
    user = str(input("Enter a option: "))
    if (user.lower() == 'q'):
        os._exit(0)
    elif (user.lower() == 'a'):
        addItem(Cart)
    elif (user.lower() == 'r'):
        removeItem(Cart)
    elif (user.lower() == 'm'):
        modifyItem(Cart)
    elif (user.lower() == 'i'):
        outputItemDescription(Cart)
    elif (user.lower() == 'o'):
        outputShoppingCart(Cart)
    elif (user.lower() == 'f'):
        finalizeOrder(Cart)
    elif (user.lower() == 'v'):
        viewReceipt(Cart)
    else:
        print("\n    Option not recognized: Please try again ")
        menu_select(Cart)

def viewReceipt(Cart):
    Cart.view_receipt_file()
    menu_select(Cart)

def finalizeOrder(Cart):
    Cart.write_reciept_to_file()
    print("\nReceipt successfully written to file")
    user = input("Are you sure your're done shopping (y/n)? ")
    if (user.lower() == 'y'):
        os._exit(0)
    else:
        menu_select(Cart)

def addItem(Cart):
    flag = 0
    item = 'item'; item_num = str(len(Cart.cart_items)) #--
    nextItem = item + item_num                             #Initialize nextItem with its number (EX: 'item0') and class
    nextItem = ItemToPurchase()                         #--
    print("\nAdd Item to cart")
    try:
        nextItem.name = str(input("Enter item's name: "))
        nextItem.describe = str(input("Enter item's description: ")) # ^
        nextItem.price = float(input("Enter item's price (EX: 10.00): "))
        while (nextItem.price < 0):
            nextItem.price = float(input("Price less than 0: Enter correct price(EX: 5.00): "))
        nextItem.quantity = int(input("Enter item's quantity (EX: 3): "))   
        while (nextItem.quantity <= 0):
            nextItem.quantity = int(input("Quantity zero or less: Enter correct quantity: "))
        flag = 1
    except:
        print("\n    An Error has Occured: Possible problems: ")
        print("     - User entered invalid characters for price/ quantity such as letters or symbols")
    if (flag == 1):
        Cart.add_item(nextItem)
    menu_select(Cart)
    
def outputItemDescription(Cart):
    Cart.print_descriptions()
    menu_select(Cart)
    
def outputShoppingCart(Cart):
    if (Cart.cart_items == []):
        print("\n    No Items in cart!")
    else:
        print("\nOutput Shopping Cart\n")
        print("{}'s Shopping Cart - {}".format(Cart.costomer_name, Cart.current_date))
        print("Number of items: {}".format(len(Cart.cart_items)))
        print()
        totalCost = Cart.get_cost_of_cart()
        Cart.print_total(totalCost)
    menu_select(Cart)
    
def removeItem(Cart):
    print("\nRemove Item")
    Cart.remove_item()
    menu_select(Cart)
    
def modifyItem(Cart):
    print("\nModify Item")
    Cart.modify_item()
    menu_select(Cart)
    
def main():
    cart1 = ShoppingCart() #Cart class == ShoppingCart
    cart1.costomer_name = str(input("Enter customer's name: "))
    cart1.current_date = str(input("Enter today's date: "))
    print("Customer name: {}".format(cart1.costomer_name))
    print("Today's date: {}".format(cart1.current_date))
    menu_select(cart1)
    
main()