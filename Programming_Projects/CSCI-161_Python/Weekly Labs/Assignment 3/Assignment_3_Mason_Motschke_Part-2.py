'''
Mason Motschke
CSCI-161
Thursday Lab 5-7
Program #3 Part 2
'''
def main():
    product = 1; five = -1; numbers = [8,11,2,12,22,36,5]
    for num in numbers:
        if (num == 5):
            five = numbers.index(5)
            break
        product = product * num
    
    print("Product of list before 5 was found:", product)
    if (five > -1):
        print("There is a Five at index:", five)
    else: 
        print("No Five was not found")

main()