import os;

def clearConsole():
    if (os.name in ['nt', 'dos']): command = 'cls';
    else: command = 'clear';
    os.system(command); return;

def AddCommas(Input, sigfig = 5):
    # Adds Commas to answers over length 4 for easy reading,
    # Input is Int or Float and Converts to string type;
    # Returns Modified String if needed; else returns original as string.

    if (not(isinstance(sigfig, int)) == True):
        raise TypeError("--- Input for Second Argument 'sigfig' is not of 'int' Type ---"); return;
    elif (sigfig > 100):
        raise IndexError("--- Input for Second Argument 'sigfig' Greater than 100 ---"); return;

    if (isinstance(Input, int) == True): # If Input is a 'int' <-------------------------------------------------------
        # Go to elif below for information on str() cast/ crash fix, Easy find symbol(highlight/search to find line): *01#
        Input = "{0:d}".format(Input); length = len(Input);
        if (length > 3): # Add Commas
            Output = []; x = 1; offset = (length // 3) - 1; #print("Offset: {0}, Length: {1}".format(offset, length));
            for letter in Input: Output.append(letter);
            for i in range(-1, -length - offset, -1):
                if (x == 3): Output.insert(i, ','); x = -1;
                x += 1;
            Output = "".join(Output); return Output; # Outputs modified string
        return Input; # If modification isn't nessasary returns original in string format

    elif (isinstance(Input, float) == True): # If Input is a 'float' <-------------------------------------------------------
        # Line Below(:01) Actively Suppresses pythons default scientific notation converter and casts 'Input' to str(). *01#
        Input = "{0:.100f}".format(Input); Input = Input.split('.');
        intLen = len(Input[0]); floatLen = len(Input[1]); Output = []; flag = 0;
        if (intLen > 3): # Adds comma to 'int' half of 'float'
            x = 1; flag = 1; offset = (intLen // 3) - 1;
            for letter in Input[0]: Output.append(letter);
            for i in range(-1, -intLen - offset, -1): # Stops loop before last digit in string, increment -1.
                if (x == 3): Output.insert(i, ','); x = -1;
                x += 1;
        #print(floatLen);
        if (floatLen >= sigfig): # Rounds 'float' half to 5 decimal places if > sigfig.
            floatList = []; temp = Input[1];
            for x in range(0, floatLen): floatList.append(temp[x]);
            for i in range(0, floatLen):
                try:
                    x = 0;
                    for index in floatList:
                        if (x > sigfig - 1): floatList.pop(x);
                        x += 1;
                except: pass;
        ''' Since Input is rounded to 10 spaces after '.' function shouldn't need these 2 cases ---\/
        if (floatLen < 5): floatList = []; floatList.append(Input[1]); floatList.append('0'); # If floatLen is < 5 append zero at end.
        if (floatLen == 5): floatList = ['']; # If floatLen is 5 set floatList as empty list.
        # -----------------------------------------------------------------------------------------^    '''
        if (flag == 1): # If 'int' half is modified return new half w/ 'float' half.
            Output.append('.'); Float = "".join(floatList); Output.append(Float); #Output.append();
            Output = "".join(Output); return Output;
        else: # If 'int' half is not modified return original 'int' half w/ 'float' half.
            Output.append(Input[0]); Float = "".join(floatList); Output.append(Float);
            Output = ".".join(Output); return Output;
    else:
        raise TypeError("--- Data Type not Supported for First Argument 'Input' ---"); return;

def Display(PosFunc):
    # Automatically Displays All Possible Functions from the List Input 'PosFunct';
    # Does So With the Number to Call Function Being Printed as Well;
    # Warning: Number to call function still needs to be hard coded into program for successfull call;
    # Will NOT Automatically Create Code to Call Nessesary Functions by Given Number;
    # Example of Output: 'num) PosFunc[i]'

    print("\nWhat Do You Want To Do?"); listSize = len(PosFunc); cnt = 1; flag = 0;
    if (listSize % 2 == 0): isOdd = False;
    else: isOdd = True;
    if (listSize >= 6): # If listSize >= 6 prints display with 2 functions per line.
        for string in PosFunc:
            if (flag == 1):
                print("{0:2d}) {1:15s}".format(cnt, string)); cnt += 1; flag = 0;
            else:
                print("{0:2d}) {1:14s}".format(cnt, string), end = " "); cnt += 1; flag = 1;
        if (isOdd == True): print();
    else: # Else prints display with 1 function per line.
        for string in PosFunc:
            print("{0}) {1:15s}".format(cnt, string)); cnt += 1;
    return;
