def sumArray(Array, size):
    if (size == 0): return 0;
    elif (size == 1): return Array[0];

    mid = int(size // 2); rsize = int(size - mid);
    
    rightArray = []; leftArray = [];
    for x in range(mid, size, 1): rightArray.append(Array[x]);
    for x in range(0, mid, 1): leftArray.append(Array[x]);
    
    lsum = int(sumArray(leftArray, mid));
    rsum = int(sumArray(rightArray, rsize));
    return int(lsum + rsum);

def sumArraySetUp():
    startArray = []; choice = int(input("Size of Array: "));
    for x in range(0, choice, 1):
        startArray.append(x);
    
    arraySum = sumArray(startArray, len(startArray));
    print("Sum: {0}".format(arraySum));

    cSum = 0;
    for x in startArray:
        cSum += x;
    
    print("Correct Answer: {0}".format(cSum));

def averageArray(Array, low, high):
    if (low > high): return 0;
    if (low == high): return Array[low];
    
    mid = (low + high) // 2;
    avLeft = averageArray(Array, low, mid);
    avRight = averageArray(Array, mid + 1, high);
    aV = avLeft + avRight;
    return aV;
    

def averageArraySetUp():
    startArray = []; choice = int(input("Size of Array: "));
    for x in range(0, choice, 1):
        startArray.append(x);

    arrayAv = averageArray(startArray, 0, len(startArray) - 1) / len(startArray);
    print("Average: {0}".format(arrayAv));

    cSum = 0;
    for x in startArray:
        cSum += x;
    cAv = cSum / len(startArray);
    
    print("Correct Answer: {0}".format(cAv));

def occurance(Array, toFind, low, high):
    if ((low == high) and (Array[low] != toFind)): return 0;
    elif ((low == high) and (Array[low] == toFind)): return 1;
    
    print("Low: {0}, High: {1}".format(low, high));
    
    mid = (low + high) // 2;
    occurLeft = occurance(Array, toFind, low, mid);
    occurRight = occurance(Array, toFind, mid + 1, high);
    
    return occurLeft + occurRight;

def occuranceSetUp():
    startArray = [0,2,3,5,66,88,4,9,7,6,5,0,0,1,3,2,8,4,9,5,4,8];
    find = int(input("Integer to find: "));

    numOfOccurance = occurance(startArray, find, 0, len(startArray) - 1);
    print("\nOccurances: {0}".format(numOfOccurance));

    cSum = 0;
    for x in startArray:
        if (x == find):
            cSum += 1;
    
    print("Correct Answer: {0}".format(cSum));

class Result:
    def __init__(self):
        self.max1 = 0;
        self.max2 = 0;

def findLarge(Array, low, high):
    pair = Result();
    pair.max1 = Array[low];
    pair.max2 = Array[low];

    if (low == high): return pair;
    
    if (high - low == 1):
        if (Array[high] >= Array[low]):
            pair.max1 = Array[high];
            pair.max2 = Array[low];
        else:
            pair.max1 = Array[low];
            pair.max2 = Array[high];
        return pair;

    mid = (high + low) // 2; lPair = Result(); rPair = Result();
    lPair = findLarge(Array, low, mid);
    rPair = findLarge(Array, mid + 1, high);

    if (rPair.max1 >= lPair.max1):
        pair.max1 = rPair.max1;
        if((rPair.max2 >= lPair.max1) and (rPair.max1 != rPair.max2)):
            pair.max2 = rPair.max2;
        else:
            pair.max2 = lPair.max1;
    else:
        pair.max1 = lPair.max1;
        if((lPair.max2 >= rPair.max1) and ( lPair.max1 != lPair.max2 )):
            pair.max2 = lPair.max2;
        else:
            pair.max2 = rPair.max2;

    return pair;

def findLargeSetUp():
    startArray = [1,3,66,88,99,5,4,6,8,2,1,5,4,7,8,6,9,5,8,4,9,5,1,2,3,61,52,55,48,36,77];

    pair = Result();
    pair = findLarge(startArray, 0, len(startArray) - 1);
    print("Large1: {0}, Large2: {1}".format(pair.max1, pair.max2));


def main():
    #sumArraySetUp();
    #averageArraySetUp();
    #occuranceSetUp();
    #findLargeSetUp();
    print("Nothing Set to Run");

main();
