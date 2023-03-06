#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class HW3 {
    public:
        int inputWithinRange (string prompt, int lowerLimit, int upperLimit);
        int inputWithinRange (string prompt, int upperLimit);
        bool isAFactor (int value1, int value2);
        void rectangle (int width, int height, char character);
        void rectangle (int width, int height, char character, char fillChar);
        int summation (int value);
        int sumOfSquare (int value);
        int square (int value);
};

int main (void){
    printf("Hello");
    return 0;
};
