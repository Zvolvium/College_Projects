// Mason Motschke - CSCI 364

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <omp.h>
using namespace std;

bool checkArgs (int argc, char *argv[]){
    if (argc != 2){
        printf("\n - Error: Number of command line arguments invalid...Needs 1!\n\n");
        return false;
    }

    string arg = argv[1];
    long value = 0;
    try {
        value = (long)stoi(arg);
        return true;
    }
    catch (...){
        printf("\n - Error: Command Line Argument Not Valid!!\n\n");
        return false;
    }
}

int add (int argVal){
    long sum = 0;
    for (int i = 0; i <= argVal; i++){
        sum += (long)i;
    }
    
    if (argVal < 0){ sum = 0; }
    return sum;
}

int main (int argc, char *argv[]){
    /*
        Phase I: 
         - Write a C++ program that adds the integers from 0 to a positive integer specified on the command line,
            and prints the sum to the console.

         - If the command line value is less than 0, the sum should be 0.
    */
    if (!checkArgs(argc, argv)){ return 0; }
    int argVal = stoi(argv[1]);
    printf("\n -- Found Command Line Argument: %d\n", argVal);
    long res = add(argVal);

    long tres = 0;
    double start = -1, end = -1;

    start = omp_get_wtime();

    #pragma omp parallel for reduction(+:tres)
    for (int i = 0; i <= argVal; i++){ tres = tres + i; }

    end = omp_get_wtime();

    printf("\n -- Sum = %ld\n", res);
    printf("\n -- Threaded Sum = %ld\n", tres);

    printf("\n -- Threaded Time: %f\n\n", end - start);
}
