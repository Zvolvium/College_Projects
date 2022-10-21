# Powers of 2
from PersonalUtils import AddCommas;

def Main():
    x = 0; user = int(input("Enter max exponent: "));
    while (x <= user):
        print("2^{x} = {string}".format(x = x, string = AddCommas(2**x))); x += 1;
    user2 = str(input("End Session(y/n): ")); print();
    if (user2 == 'y'):
        return;
    else:
        Main();
    
Main();