/*
    File Name: prog4MAM.cpp
  
    g++ version: 17.0.5
    
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
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include <stdbool.h>
using namespace std;

class HW4 {
    public:
        int findMaxScore (int scoresList[], int size);
        int findMinScore (int scoresList[], int size);
        bool hasPerfectScore (int scoresList[], int size);
        double calcAverage (int scoresList[], int size);
        string findStudentWithMax (int scoresList[], string namesList[], int size);
        int* mergeLists (int list1[], int list2[]);
        double standardDeviation (int scoresList[], int size);
        int findInList (int scoresList[], int valueToFind);
        int findInList (int scoresList[], int valueToFind, int startingIndex);
};

int HW4::findMaxScore (int scoresList[], int size){
    /*
        (int) def findMaxScore (scoresList): 
        int findMaxScore (int[] scoresList) 
        int findMaxScore (int scoresList[], int size)

        Return the largest integer value (int) found in the list.
        DO NOT make any assumptions about the range of values in the list.
        size is the number of items in the list/array.
    */

    int max = -1000000;
    for (int i = 0; i < size; i++){
        if (scoresList[i] > max){
            max = scoresList[i];
        }
    }

    return max;
}

int HW4::findMinScore (int scoresList[], int size){
    /*
        (int) def findMinScore (scoresList): 
        int findMinScore (int[] scoresList) 
        int findMinScore (int scoresList[], int size) 
            
        Return the smaller integer value (int) found in the list.
        DO NOT make any assumptions about the range of values in the list.
        size is the number of items in the list/array.
    */

    int min = 1000000;
    for (int i = 0; i < size; i++){
        if (scoresList[i] < min){
            min = scoresList[i];
        }
    }

    return min;
}

bool HW4::hasPerfectScore (int scoresList[], int size){
    /*
        (boolean) def hasPerfectScore (scoresList): 
        boolean hasPerfectScore (int[] scoresList) 
        bool hasPerfectScore (int scoresList[], int size) 
         
        Returns the appropriate true reserved word if any of the scores is 100 or greater,
        otherwise returns the appropriate false reserved word.
    */

    for (int i = 0; i < size; i++){
        if (scoresList[i] >= 100){
            return true;
        }
    }

    return false;
}

double HW4::calcAverage (int scoresList[], int size){
    /*
        (float) def calcAverage (scoresList): 
        double calcAverage (int[] scoresList) 
        double calcAverage (int scoresList[], int size) 
            
        Return the average (double) of all the scores found in the list.
        Return -1 if unable to determine an array – don’t let the program crash.
    */

   try {
        double av = 0;
        for (int i = 0; i < size; i++){
            av += (double)scoresList[i];
        }

        av = (double)(av / size);

        return av;
    }
    catch (const char* e){
        return -1;
    }
}

string HW4::findStudentWithMax (int scoresList[], string namesList[], int size){
    /*
        (str) def findStudentWithMax (scoresList, namesList): 
        String findMaxScore (int[] scoresList, String[] namesList) 
        string findMaxScore (int scoresList[], string namesList[], int size) 
            
        Return the name of the student with the largest score.
        You can assume there will be only one student with the largest score.
        IF there were two students with the largest score (there won’t be) you can return the name of the first student with that score.
    */

    int max = findMaxScore(scoresList, size);

    for (int i = 0; i < size; i++){
        if (scoresList[i] == max){
            printf("%c", namesList[i][0]);
            return namesList[i];
        }
    }

    return NULL;
}

int* HW4::mergeLists (int list1[], int list2[]){
    /*
        ([]) def mergeLists (list1, list2): 
        int[] mergeLists (int[] list1, int[] list2) 
        int* mergeLists (int list1[], int list2[]) 
            
        Return a new array/list made up of the values from the two lists, values from list1 first, then the values from list2.
        This might not find into the theme of the other functions,
        but we’ll still include it in the list of required functions.
    */
    int size1 = (int)(sizeof(list1) - 1);
    int size2 = (int)(sizeof(list2) - 1);
    int newSize = size1 + size2;

    int* res = (int*)malloc(newSize * sizeof(int));

    int cnt = 0;
    for (int i = 0; i < size1; i++){
        res[cnt] = list1[i];
        cnt++;
    }
    for (int j = 0; j < size2; j++){
        res[cnt] = list2[j];
        cnt++;
    }

    return res;
}

double HW4::standardDeviation (int scoresList[], int size){
    /*
        (float) standardDeviation (scoresList) 
        Double standardDeviation (int[] scoresList) 
        double standardDeviation (int scoresList[], int size) 
            
        Return the standard deviation of the values.
        To find the standard deviation start with the average of the list – DO NOT repeat the code for calculating the average.
        Then for each value in the list subtract the average from that value and square the result.
        Find the average of the squared differences and then take the square root of that average. 
    */

    double av = calcAverage(scoresList, size);

    int* temp = (int*)malloc(size * sizeof(int));
    double res;
    for (int i = 0; i < size; i++){
        res = (scoresList[i] - av);
        temp[i] = (int)(pow(res, 2));
    }

    av = calcAverage(temp, size);

    res = pow(av, 0.5);

    free(temp);
    return res;
}

int HW4::findInList (int scoresList[], int valueToFind){
    /*
        (int) def findInList (scoresList, valueToFind, startingIndex=0): 
        int findInList (int[] scoresList, int valueToFind) 
        int findInList (int[] scoresList, int valueToFind, int startingIndex) 
        int findInList (int scoresList[], int valueToFind) 
        int findInList (int scoresList[], int valueToFind, int startingIndex) 
            
        Return the index of the first occurrence of valueToFind.
        IF specified, starting searching at the specified index, otherwise start searching at index 0.
        This requires a default parameter in Python and overloaded functions/methods in Java and C++.
        In any of the functions return -1 if the value is not found.
    */
    return findInList(scoresList, valueToFind, 0);
}
int HW4::findInList (int scoresList[], int valueToFind, int startingIndex){
    /*
        Comments same as method above -----/\
    */
    int size = (int)(sizeof(scoresList));

    for (int i = startingIndex; i < size; i++){
        if (scoresList[i] == valueToFind){
            return i;
        }
    }

    return -1;

    return 0;
}

int main (void){
    // Test Functions
    int merge[] = {
        22, 65, 4, 8, 9, 200, 300
    };
    int scoreList[] = {
            12,     15,       16,       55,       90,      102,         3
    };
    string namesList[] = {
        "Tom", "Phil", "Jackie", "Mickel", "Trevor", "Teapot", "Trishia"
    };

    HW4 test;

    int* temp;
    int mergeSize;
    int size = sizeof(scoreList) / 4;

    printf("findMaxScore: %d\n", test.findMaxScore(scoreList, size));
    printf("findMinScore: %d\n", test.findMinScore(scoreList, size));
    printf("hasPerfectScore: %s\n", test.hasPerfectScore(scoreList, size) ? "true" : "false");
    printf("calcAverage: %f\n", test.calcAverage(scoreList, size));
    printf("findStudentWithMax: ");
    string name = test.findStudentWithMax(scoreList, namesList, size);
    for (int i = 0; i < sizeof(name) / 4; i++){ printf("%c", name[i]); } cout << '\n';

    temp = test.mergeLists(scoreList, merge); printf("mergeLists: ");
    mergeSize = sizeof(temp);
    for (int i = 0; i < mergeSize * 2 - 2; i++){ printf("%d ", temp[i]); } printf("\n");
    temp = test.mergeLists(merge, scoreList); printf("mergeLists: ");
    mergeSize = sizeof(temp);
    for (int i = 0; i < mergeSize * 2 - 2; i++){ printf("%d ", temp[i]); } printf("\n");

    printf("standardDeviation: %f\n", test.standardDeviation(scoreList, size));
    printf("findInList: %d\n", test.findInList(scoreList, 56, 10));
    printf("findInList: %d\n", test.findInList(scoreList, 102));

    free(temp);
    return 0;
}
