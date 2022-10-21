def recurrSelectSort(Array, sizeN, startIndex = 0):
    # Find Minimun index
    minI = startIndex;
    for j in range(startIndex + 1, sizeN):
        if (Array[j] < Array[minI]):
            minI = j;

    # swap minI and startIndex
    temp = Array[minI];
    Array[minI] = Array[startIndex];
    Array[startIndex] = temp;

    if (startIndex + 1 < sizeN):
        recurrSelectSort(Array, sizeN, startIndex + 1);

def recurrSelectSortSetUp():
    startArray = [1,5,99,6,3,4,0,7,8,10,11];
    print("\nStarting Array: {0}".format(startArray));
    recurrSelectSort(startArray, len(startArray), 0);
    print("Sorted Array: {0}".format(startArray));

def recurrInsertionSort(Array, start, stop):
    val = Array[start];
    mVal = start - 1;
    
    while ((mVal >= 0) and (Array[mVal] >= val)):
        Array[mVal + 1] = Array[mVal];
        mVal -= 1;
        
    Array[mVal + 1] = val;

    if (start + 1 < stop):
        recurrInsertionSort(Array, start + 1, stop);

def recurrInsertionSortSetUp():
    startArray = [1,5,99,6,3,4,0,7,8,10,11];
    print("\nStarting Array: {0}".format(startArray));
    recurrInsertionSort(startArray, 1, len(startArray));
    print("Sorted Array: {0}".format(startArray));

def recurrBubbleSort(Array, start, stop, sort = False):
    if (start >= stop): # Base case if index is out of bounds
        return;
    if (sort == True): # Base case if array is sorted
        return;
    
    if (start <= stop - 1):
        sort = True;
        for x in range(stop - 1, start - 1, -1):
            if (Array[x] < Array[x - 1]): # Push smaller values left
                temp = Array[x];          # Interchange said values
                Array[x] = Array[x - 1];
                Array[x - 1] = temp;
                sort = False;
        recurrBubbleSort(Array, start + 1, stop, sort); # Recursion

def recurrBubbleSortSetUp():
    startArray = [1,5,99,6,3,4,0,7,8,10,11];
    print("\nStarting Array: {0}".format(startArray));
    recurrBubbleSort(startArray, 0, len(startArray));
    print("Sorted Array: {0}".format(startArray));

def main():
    #recurrSelectSortSetUp();
    #recurrInsertionSortSetUp();
    #recurrBubbleSortSetUp();
    print("\nAlgorithm End");

main();
