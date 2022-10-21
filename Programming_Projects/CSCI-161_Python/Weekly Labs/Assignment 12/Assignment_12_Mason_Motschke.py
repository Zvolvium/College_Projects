'''
Mason Motschke
CSCI 161
Thursday Lab 5-7
Program #12
'''
class BMW:
    def __init__(self, cruiseOrPark, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        self.cruiseOrPark = cruiseOrPark
        
    def startEngine(self):
        print("Engine is now on.")
        
    def stopEngine(self):
        print("Engine is now off.")
        
class ThreeSeries(BMW):
    def __init__(self, cruiseControlEnabled, make, model, year):
        BMW.__init__(self, cruiseControlEnabled, make, model, year)
        
    def display(self):
        if (self.cruiseOrPark == 'y'):
            print("Cruise Control is on.")
        else:
            print("Cruise Control is off.")
        
    def startEngine(self):
        super().startEngine()
        print("Button start is on.")
        
class FiveSeries(BMW):
    def __init__(self, parkingAssistEnabled, make, model, year):
        super().__init__(parkingAssistEnabled, make, model, year)
    
    def display(self):
        if (self.cruiseOrPark == 'y'):
            print("Parking Assist is on.")
        else:
            print("Parking Assist is off.")
        
def main():
    make1 = input("Enter the Three Series Make: ")
    model1 = input("Enter Model: ")
    year1 = input("Enter Year: ")
    cruiseControl = input("Is the cruise control on (y or n)? ")
    car1 = ThreeSeries(cruiseControl, make1, model1, year1)
    
    make2 = input("\nEnter the Five Series Make: ")
    model2 = input("Enter Model: ")
    year2 = input("Enter Year: ")
    parkingAssist = input("Is the parking assist enabled (y or n)? ")
    car2 = FiveSeries(parkingAssist, make2, model2, year2)
    
    print("\nThree Series...")
    print("This {make} is a {model} of {year}".format(make = make1, model = model1, year = year1))
    car1.startEngine()
    car1.display()
    print("-" * 10)
    print("Five Series...")
    print("This {make} is a {model} of {year}".format(make = make2, model = model2, year = year2))
    print("Starting Engine...")
    car2.startEngine()
    car2.display()
    print("-" * 10)
    
main()