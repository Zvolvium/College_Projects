'''
Homework Help for Math - Creator: Mason A. Motschke
Last Modification Date - 11/11/2021

Current In-Progress:
    None

Bugs Fixed:
    In PersonalUtils @ AddCommas:
        - Commas wouldn't be placed correctly for Length 6 or 9 numbers due to var offset definition.
        - Crashed due to Python Default: Float Converted to Scientific Notation for unknown reason @ Float Half str() convert,
            - Future Proofed Int Half Incase of Same Issue (Goto PersonalUtils @ AddCommas for more info).

    In Math_Help @ Factorial:
         - Kept crashing console on large recursive run.
         - Crashed due to python being unable to properly recover from error mid-recursion. 
            - Fixed by making Factorial function iterative instead of recursive.
                - Factorial is now functionally infinite for max possible call.
'''
from sys import setrecursionlimit as setRecurrLimit;
from sys import exit as Exit;
from PersonalUtils import clearConsole;
from PersonalUtils import Display;
from PersonalUtils import AddCommas;
recurrLimit = 10000; setRecurrLimit(recurrLimit);

def Congruences():
    # Finds the Congruence Between 'numByX' Which is the Number next to 'x',
    # While 'wantedVal' is What Your Looking for and 'modNum' is the Modulo Value;
    # Continue Will Find All Answers if 'y' is Indicated Until NO Answer Remains.

    print("-" * 5, "Congruences", "-" * 5); print(" ** To quit early enter '-1' for all enteries ** ");
    numByX = int(input("Enter Num by 'x': ")); exp = int(input("Enter exponent: ")); wantedVal = int(input("Enter Desired Value: "));
    modNum = int(input("Enter mod Num: ")); maxVal = modNum; i = -1; x = 1;
    if ( (wantedVal == -1) and (modNum == -1) and (numByX == -1) and (exp == -1)):
        print("\n--- Quit Early"); return;
    while (1):
        i += 1;
        if (i > maxVal): print("\n--- Error: No Solution"); break;
        elif ( (((numByX * i)**exp) % modNum) == (wantedVal%modNum) ):
            print("\n--- Answer {0} equals {1}".format(x, i)); user = str(input("Continue (y/n): ")); x += 1;
            if (user == "y"): continue;
            else: break;
    return;

def Modulo():
    # Finds the Mod in the Format of ( (mainNum**exp) % modNum ) and Outputs Answer.

    print("-" * 5, "Modulo", "-" * 5); print(" ** Syntax: NumtoMod ^ exponent mod ModNum ** ");
    mainNum = int(input("Enter Number to Mod: ")); exp = int(input("Enter Exponent: ")); modNum = int(input("Enter Mod Number: "));
    if (modNum == 0): print("\n--- Error: Can't mod by zero!"); return;
    print("\n--- ({0} ^ {1}) mod {2} = {3}".format(mainNum, exp, modNum, ((mainNum**exp) % modNum) )); return;

def Factorial(n):
    # Finds the Factorial of Any Non-Negative Numbers, Auto-Casts to 'int' in Case of 'float';
    # Returns '-1' on Negative Number. Handles up to 2464 factorial

    if (isinstance(n, float)): n = int(n);
    if (n < 0): print("\n--- Error: Negative Factorial Value Entered"); return -1;
    result = 1;
    for i in range(2, n + 1): result *= i;
    return result;

def FactorialSetup():
    # Setup Stuff for Factorial to Keep Main() Pretty and Neat Plus Factorial() is Recursive,
    # Returns on Negative Num indicating a Error Occured;

    print("-" * 5, "Factorial", "-" * 5); print(" ** Entered 'floats' will be auto-cast to 'ints' ** ");
    num = float(input("Enter Number: ")); answer = Factorial(num);
    if (answer < 0): return;
    else:
        if (isinstance(num, float) == True): num = int(num);
        answer = AddCommas(answer); print("\n--- {0}! = {1}".format(num, answer)); return;

def Exponent():
    # Setup Stuff for Exponent to Keep Main() Pretty and Neat.

    print("-" * 5, "Exponent", "-" * 5); print(" ** Calculates the exponent in the form a^b ** ");
    print(" ** Answer will be rounded to 5 figures after decimal ** ");
    x = float(input("Enter Base Num(a): ")); y = float(input("Enter Power(b): "));
    try:
        answer = (x**y); answer = AddCommas(answer);
    except OverflowError as flowError: print("\n--- Error: {}".format(flowError)); return;
    print("\n--- ({0} ^ {1}) = {2}".format(x, y, answer)); return;

def Combination():
    # Calculates the Given Combination ('n' choose 'k'),
    # 'n' is Auto-Cast to 'int' (Same With 'k');

    print("-" * 5, "Combination", "-" * 5); print(" ** Calculates Combination (n choose k) ** ");
    n = float(input("Enter 'n' Value: ")); k = float(input("Enter 'k' Value: "));
    if ( (isinstance(n, float) == True) or (isinstance(k, float) == True) ): n = int(n); k = int(k);
    if ( (n == 0) and (k == 0) ): print("\n--- ({0:1d} choose {1:1d}) = 1".format(n, k));
    elif (k == 0): print("\n--- ({0:1d} choose {1:1d}) = 1".format(n, k));
    elif ( (n < 0) or (k < 0) ): print("\n--- Error: 'n' or 'k' is Negative - No negatives Allowed");
    elif (k > n): print("\n--- ({0:1d} choose {1:1d}) = 0".format(n, k));
    else:
        answer = ( (Factorial(n)) // (Factorial(k) * Factorial(n - k)) ); answer = AddCommas(answer);
        print("\n--- ({0:1d} choose {1:1d}) = {2}".format(n, k, answer)); return;
    return;

def Quadratic():
    # Calculates Quadratic Equations in the Form of ax**2 +/- bx +/- c = 0;
    # 'b' is Auto-Set to '-b' for Simplicity;
    # Reminder That py Uses 'j' to Indicate Imaginary Numbers Instead of 'i'.

    print("-" * 5, "Quadratic", "-" * 5); print(" ** Solves Quadratic Equations In the Form: ** ");
    print(" ** ~ ax^2 +/- bx +/- c = 0 ** "); valFlag = 1;

    # All three while loops ensures program won't crash if input is not 'int' type ----\/
    while (valFlag == 1): # a input sanitization <----
        valFlag = 0;
        try:
            a = int(input("\nEnter a: "));
        except ValueError:
            print("- Error: 'a' is NOT a Number!"); valFlag = 1;
        else:
            valFlag = 1; break;
    
    while (valFlag == 1): # b input sanitization <----
        valFlag = 0;
        try:
            b = -(int(input("\nEnter b: ")));
        except ValueError:
            print("- Error: 'b' is NOT a Number!"); valFlag = 1;
        else:
            valFlag = 1; break;

    while (valFlag == 1): # c input sanitization <----
        valFlag = 0;
        try:
            c = int(input("\nEnter c: "));
        except ValueError:
            print("- Error: 'c' is NOT a Number!"); valFlag = 1;
        else:
            valFlag = 1; imFlag = 0; break;
    # End of Input Sanitization --------------------------------------------------------/\

    if (a == 0): print("\n--- Equation is Linear not Quadratic"); print("\n--- Error: Cannot Divide by Zero"); return;
    inRoot = ( ( (b**2) - 4*a*c) ); bottom = (2*a);
    if (inRoot < 0): print("\n--- No Real Solutions - 'j' indicates imaginary 'i'"); imFlag = 1;
    root = ( (inRoot)**(1/2) ); xpos = (b + root)/(bottom); xneg = (b - root)/(bottom);
    
    if ( (inRoot < 0) and (imFlag == 1) ): # Output
        print("\n--- Imaginary Solutions: ({0:1.5f}, {1:1.5f})".format(xpos, xneg));
        print("\n--- Equation Form: ({b} / {bottom}) +/- (sqr-root({top}) / {bottom})".format(b = b, top = inRoot, bottom = bottom));
    elif (inRoot == 0):
        print("\n--- Only Solution: ({0:1.5f})".format(xpos));
        print("\n--- Equation Form: ({b} / {bottom})".format(b = b, bottom = bottom));
    else:
        print("\n--- Real Solutions: ({0:1.5f}, {1:1.5f})".format(xpos, xneg));
        print("\n--- Equation Form: ({b} / {bottom}) +/- (sqr-root({top}) / {bottom})".format(b = b, top = inRoot, bottom = bottom));

def Main():
    # Exit Function Should Always be Last in List for Ease of Use!!
    # To add Function add to list before 'Exit' func in functions list, and while loop below ---\/
    functions = ["Congruences", "Modulo", "Factorial", "Exponent", "Combination", "Quadratic", "Exit"];
    global recurrLimit;
    
    Display(functions); user = str(input("Choice: ")); print(); clearConsole();
    while (1):
        flag = 0;
        if (user == '1'):                      # Do Congruences
            Congruences(); flag = 1;
        elif (user == '2'):                    # Do Modulo
            Modulo(); flag = 1;
        elif (user == '3'):                    # Do Factorial
            FactorialSetup(); flag = 1;
        elif (user == '4'):                    # Do Exponent
            Exponent(); flag = 1;
        elif (user == '5'):                    # Do Combination
            Combination(); flag = 1;
        elif (user == '6'):                    # Do Quadratic
            Quadratic(); flag = 1;
        elif (user == '7'):                    # Do Exit
            recurrLimit = 1000; setRecurrLimit(recurrLimit); Exit("--- Exited Program\n");
        else:                                  # Catches Any and All Other Cases and Re-Calls Main() Recursively
            print("--- Choice not found"); recurrLimit += 1; setRecurrLimit(recurrLimit); Main();
        if ( (user == None) or (flag == 1) ):
            Display(functions); user = str(input("Choice: ")); print(); clearConsole();
    return;

Main();