# Display alphabet w/ corrosponding numbers for encryption/ decryption

def Main():
    alphabet = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']; x = 0;
    for x in range(0, 26):
        print( alphabet[x] + "-" + str(x) );
    user = str(input("End Session(y/n): ")); print();
    if (user == 'y'):
        return;
    else:
        Main();

Main();