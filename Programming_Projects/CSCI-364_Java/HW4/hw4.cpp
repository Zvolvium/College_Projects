#include <stdlib.h>
#include <stdio.h>
#include <iostream>
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
        printf("\n%ld\n", value);
        return true;
    }
    catch (...){
        printf("\n - Error: Command Line Argument Not Valid!!\n\n");
        return false;
    }
}

int main (int argc, char *argv[]){
    /*
        Phase I: 
         - Write a C++ program that adds the integers from 0 to a positive integer specified on the command line,
            and prints the sum to the console.

         - If the command line value is less than 0, the sum should be 0.
    */
   if (!checkArgs(argc, argv)){ return 0; }

   printf("\nContinued...\n");
   int argVal = stoi(argv[1]);

   long sum = 0;
   for (int i = 0; i <= argVal; i++){
        sum += (long)i;
   }

   if (argVal < 0){ sum = 0; }
   printf("\n\n -- Sum = %ld\n\n", sum);
}
