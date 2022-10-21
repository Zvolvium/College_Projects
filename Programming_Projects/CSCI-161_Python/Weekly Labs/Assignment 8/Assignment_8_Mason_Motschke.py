'''
Mason Motschke
CSCI-161
Thursday Lab 5-7
Program #8
'''
import os
class ShoppingCart:
    def __init__(self):
        self.costomer_name = 'None'
        self.current_date = 'None'
        self.cart_items = []
        
    def add_item(self, item):
        self.cart_items.append(item)
    
    def get_cost_of_cart(self):
        totalCost = 0
        for item in self.cart_items:
            item.print_item_cost() #item class == ItemToPurchase
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
            print("{}'s Shopping Cart - {}".format(self.name, self.date))
            print()
            for item in self.cart_items:
                item.print_item_description()        
        
class ItemToPurchase: #Class carried over from Assignment 7
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
    print("i - Output items' descriptions")
    print("o - Output shopping cart")
    print("q - Quit")

def menu_select(Cart):
    printMenu()
    user = str(input("Enter a option: "))
    if (user.lower() == 'q'):
        os._exit(0)
    elif (user.lower() == 'a'):
        addItem(Cart)
    elif (user.lower() == 'i'):
        outputItemDescription(Cart)
    elif (user.lower() == 'o'):
        outputShoppingCart(Cart)
    else:
        print("\n    Option not recognized: Please try again ")
        menu_select(Cart)

def addItem(Cart):
    item = 'item'; item_num = str(len(Cart.cart_items)) #--
    nextItem = item + item_num                             #Initialize nextItem with its number (EX: 'item0') and class
    nextItem = ItemToPurchase()                         #--
    print("\nAdd Item to cart")
    nextItem.name = str(input("Enter item's name: "))
    nextItem.describe = str(input("Enter item's description: ")) # ^
    nextItem.price = float(input("Enter item's price (EX: 10.00): "))
    nextItem.quantity = int(input("Enter item's quantity (EX: 3): "))
    Cart.add_item(nextItem)
    menu_select(Cart)
    
def outputItemDescription(Cart):
    Cart.print_descriptions()
    menu_select(Cart)
    
def outputShoppingCart(Cart):
    if (Cart.cart_items == []):
        print("\n    No Items in cart!")
    else:
        print("\nOutput Shopping Cart")
        print("{}'s Shopping Cart - {}".format(Cart.name, Cart.date))
        print("Number of items: {}".format(len(Cart.cart_items)))
        print()
        totalCost = Cart.get_cost_of_cart()
        Cart.print_total(totalCost)
    menu_select(Cart)
    
def main():
    cart1 = ShoppingCart() #Cart class == ShoppingCart
    cart1.name = str(input("Enter customer's name: "))
    cart1.date = str(input("Enter today's date: "))
    print("Customer name: {}".format(cart1.name))
    print("Today's date: {}".format(cart1.date))
    menu_select(cart1)
    
main()