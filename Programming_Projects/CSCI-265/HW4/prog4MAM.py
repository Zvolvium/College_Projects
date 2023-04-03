"""
    File Name: prog4MAM.py

    Python Version: 3.11.0

    Author: Mason A. Motschke

    Contact: mason.motschke@und.edu

    Comment:
        Write each of the following functions.
        The function header must be implemented exactly as specified.
        For Python the type of value that should be returned from each function is in parenthesis in the function description.
        Write a main function that tests each of the required functions/methods.
        You do not have to use keyboard input in main, just ensure that each function/method is called more than one.
        Remember that the functions themselves will not display any output,
        they will return values that can then be written to the screen.
"""

def findMaxScore(scoresList):
    #(int) def findMaxScore (scoresList): 
    #int findMaxScore (int[] scoresList) 
    #int findMaxScore (int scoresList[], int size)
    #
    #Return the largest integer value (int) found in the list.DO NOT make any assumptions about the range of values in the list.
    # size is the number of items in the list/array.
    
    max = -1000000;
    for score in scoresList:
        if (score > max):
            max = score;
    
    return max;

def findMinScore(scoresList):
    #(int) def findMinScore (scoresList):
    # int findMinScore (int[] scoresList)
    # int findMinScore (int scoresList[], int size)
    #
    # Return the smaller integer value (int) found in the list.
    # DO NOT make any assumptions about the range of values in the list. size is the number of items in the list/array.
    
    min = 1000000;
    for score in scoresList:
        if (score < min):
            min = score;
    
    return min;

def hasPerfectScore(scoresList):
    # (boolean) def hasPerfectScore (scoresList):
    # boolean hasPerfectScore (int[] scoresList)
    # bool hasPerfectScore (int scoresList[], int size) 
    # 
    # Returns the appropriate true reserved word if any of the scores is 100 or greater,
    # otherwise returns the appropriate false reserved word.
    
    for score in scoresList:
        if (score >= 100):
            return True;
        
    return False;

def calcAverage(scoresList):
    # (float) def calcAverage (scoresList):
    # double calcAverage (int[] scoresList) 
    # double calcAverage (int scoresList[], int size) 
    # 
    # Return the average (double) of all the scores found in the list.
    # Return -1 if unable to determine an array – don’t let the program crash.
    
    try:
        av = 0;
        for score in scoresList:
            av += score;
            
        av = av / len(scoresList);
    
        return av;
    
    except:
        return -1;

def findStudentWithMax(scoresList, namesList):
    # (str) def findStudentWithMax (scoresList, namesList):
    # String findMaxScore (int[] scoresList, String[] namesList)
    # string findMaxScore (int scoresList[], string namesList[], int size)
    # 
    # Return the name of the student with the largest score.
    # You can assume there will be only one student with the largest score.
    # IF there were two students with the largest score (there won’t be) you can return the name of the first student with that score.
    
    max = findMaxScore(scoresList);
    index = scoresList.index(max);
    
    return namesList[index];

def mergeLists(list1, list2):
    # ([]) def mergeLists (list1, list2):
    # int[] mergeLists (int[] list1, int[] list2)
    # int* mergeLists (int list1[], int list2[])
    # 
    # Return a new array/list made up of the values from the two lists, values from list1 first, then the values from list2.
    # This might not find into the theme of the other functions,
    # but we’ll still include it in the list of required functions.
    
    mergedList = [];
    for list in [list1, list2]:
        for item in list:
            mergedList.append(item);
    
    return mergedList;

def standardDeviation(scoresList):
    # (float) standardDeviation (scoresList)
    # double standardDeviation (int[] scoresList)
    # double standardDeviation (int scoresList[], int size)
    # 
    # Return the standard deviation of the values.
    # To find the standard deviation start with the average of the list – DO NOT repeat the code for calculating the average.
    # Then for each value in the list subtract the average from that value and square the result.
    # Find the average of the squared differences and then take the square root of that average.
    
    av = calcAverage(scoresList);
    
    temp = [];
    for val in scoresList:
        temp.append((val - av) ** 2);
        
    av = calcAverage(temp);
    
    return (av ** 0.5);

def findInList(scoresList, valueToFind, startingIndex=0):
    # (int) def findInList (scoresList, valueToFind, startingIndex=0):
    # int findInList (int[] scoresList, int valueToFind)
    # int findInList (int[] scoresList, int valueToFind, int startingIndex)
    # int findInList (int scoresList[], int valueToFind) 
    # int findInList (int scoresList[], int valueToFind, int startingIndex) 
    # 
    # Return the index of the first occurrence of valueToFind.
    # IF specified, starting searching at the specified index, otherwise start searching at index 0.
    # This requires a default parameter in Python and overloaded functions/methods in Java and C++.
    # In any of the functions return -1 if the value is not found.
    
    try:
        for i in range(0, len(scoresList)):
            if (scoresList[i] == valueToFind):
                return i;
    
        return -1;
    
    except:
        return -1;

def main():
    # Test Functions
    scoreList = [
           12,     15,       16,       55,       90,      102,         3
    ];
    nameList = [
        'Tom', 'Phil', 'Jackie', 'Mickel', 'Trevor', 'Teapot', 'Trishia'
    ];
    
    print(f'findMaxScore: {findMaxScore(scoresList=scoreList)}');
    print(f'findMinScore: {findMinScore(scoresList=scoreList)}');
    print(f'hasPerfectScore: {hasPerfectScore(scoresList=scoreList)}');
    print(f'calcAverage: {calcAverage(scoresList=scoreList)}');
    print(f'findStudentWithMax: {findStudentWithMax(scoresList=scoreList, namesList=nameList)}');
    print(f'mergeLists: {mergeLists(scoreList, nameList)}');
    print(f'mergeLists: {mergeLists(nameList, scoreList)}');
    print(f'standardDeviation: {standardDeviation(scoresList=scoreList)}');
    print(f'findInList: {findInList(scoresList=scoreList, valueToFind=56, startingIndex=10)}');
    print(f'findInList: {findInList(scoresList=scoreList, valueToFind=102)}');
    
    return;

if (__name__ == '__main__'):
    main();