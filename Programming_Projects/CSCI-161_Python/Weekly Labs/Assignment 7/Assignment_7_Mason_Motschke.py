'''
Mason Motschke
CSCI-161
Thursday Lab 5-7
Program #7
'''
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
    
def main():
    item1 = ItemToPurchase()
    item1.name = input("Enter Item 1's Name: ")
    item1.describe = input("Enter Items Decscription: ") # ^
    item1.quantity = int(input("Enter Items Quantity: "))
    item1.price = float(input("Enter Items Price (EX: 10.00): "))
    
    item2 = ItemToPurchase()
    item2.name = input("\nEnter Item 2's Name: ")
    item2.describe = input("Enter Items Decscription: ") # ^
    item2.quantity = int(input("Enter Items Quantity: "))
    item2.price = float(input("Enter Items Price (EX: 10.00): "))  
    
    totalCost = (item1.price * item1.quantity) + (item2.price * item2.quantity)
    print("\nTotal Cost")
    item1.print_item_cost(); item2.print_item_cost()
    print("Total: ${0:1.2f}".format(totalCost))
    
    print("\nItem Descriptions")
    item1.print_item_description(); item2.print_item_description()
    
main()