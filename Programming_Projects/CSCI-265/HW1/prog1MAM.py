"""
    File Name: prog1MAM.py

    Python Version: 3.11.0

    Author: Mason A. Motschke

    Contact: mason.motschke@und.edu

    Comment:
        Write each of the following programs in C, C++, Python, and Java.
        Write a single problem that addresses all three parts:
            Part 1 – Convert from seconds
            Part 2 – Convert to dollars
            Part 3 - Work with output
"""
def main():
    # Part 1
    print("-" * 10, "Part 1", "-" * 10);
    start = int(input("Enter the number of seconds(EX: 5): "));
    sec = int(start % 60); min = int((start / 60) % 60); hrs = int((start / 60) / 60);
    print(" -- Hours: {0}, Minutes: {1}, Seconds: {2}".format(hrs, min, sec));

    # Part 2
    print("\n" + "-" * 10, "Part 2", "-" * 10);
    quarters = int(input("Enter Number of Quarters(EX: 5): ")); dimes = int(input("Enter Number of Dimes(EX: 5): "));
    nickles = int(input("Enter Number of Nickles(EX: 5): ")); pennies = int(input("Enter Numbrer of Pennies(EX: 5): "));
    dollars = int((quarters * 0.25) + (dimes * 0.10) + (nickles * 0.05) + (pennies * 0.01));
    cents = int(((quarters * 0.25) + (dimes * 0.10) + (nickles * 0.05) + (pennies * 0.01)) * 100) % 100;
    print(" -- Dollars: {0}, Cents: {1}".format(dollars, cents));

    # Part 3
    print("\n" + "-" * 10, "Part 3", "-" * 10);
    firstName = input("Enter your First Name: "); lastName = input("Enter your Last Name: ");
    addr = input("Enter Address: "); city = input("Enter City: "); state = input("Enter State: ");
    zip = input("Enter Zip Code: ");

    # Print in format using 1 print statement
    print("\n{first}, {last}\n{address}\n{city}, {state}  {zip}\n".format(first = firstName, last = lastName, address = addr, city = city, state = state, zip = zip));

    # Pritn in format using 6 print statements
    print(firstName, end=', '); print(lastName);
    print(addr);
    print(city, end=', '); print(state, end='  '); print(zip, end='\n\n');
    return;

main();
