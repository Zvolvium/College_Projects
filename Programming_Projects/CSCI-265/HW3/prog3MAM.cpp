#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class HW3 {
    public:
        int   inputWithinRange  (string prompt, int lowerLimit, int upperLimit               );
        int   inputWithinRange  (string prompt, int upperLimit                               );
        bool  isAFactor         (int value1   , int value2                                   );
        void  rectangle         (int width    , int height    , char character, char fillChar);
        void  rectangle         (int width    , int height    , char character               );
        int   summation         (int value                                                   );
        int   sumOfSquare       (int value                                                   );
        int   square            (int value                                                   );
};

int HW3::inputWithinRange (string prompt, int lowerLimit, int upperLimit){
    // int inputWithinRange (s/String prompt, int lowerLimit, int upperLimit)  //Java, C++
    // int inputWithinRange (s/String prompt, int upperLimit)                  //Java, C++
    // def inputWithinRange (prompt, lowerLimit, upperLimit=None)

    // Will ask for an integer value, using the provided prompt.
    // The value must be inclusively within lowerLimit and upperLimit, if not,
    // continue to ask for a value until the entered value is within the provided range.
    // Once a valid value has been entered return it from the function.

    // In Java (use String for the prompt datatype) and C++ (use string from the prompt datatype) overload the function.
    // Use a default lowerLimit of 0 when only the upperLimit is provided.
    // All of the work must be done in one function, the second function should call the first function.
    // We want multiple options in calling the function, but do not want to duplicate the work.
    // In Python, if only the prompt and a single number is provided use 0 for the lowerLimit and the provided number for the upperLimit.

    int user = 0;
    cout << prompt;
    cin >> user;

    while ( (user < lowerLimit) || (user > upperLimit) ){
        cout << "Number not in range, " << prompt;
        cin >> user;
    }

    return user;
}
int HW3::inputWithinRange (string prompt, int upperLimit){
    // Same Comments as Above rectangle function ---/\

    int user = this->inputWithinRange(prompt, 0, upperLimit);

    return user;
}

bool HW3::isAFactor (int value1, int value2){
    // boolean isAFactor (int value1, int value2)  //Java
    // bool isAFactor (int value1, int value2)     //C++
    // def isAFactor (value1, value2)

    // returns True (Python) or true (Java/C++),
    // if the second argument is a factor of (divides evenly into) the first argument.
    // If not, it returns False (Python) or false (Java/C++).

    if (value1 % value2 == 0){
        return true;
    }

    return false;
}

void HW3::rectangle (int width, int height, char character, char fillChar){
    // void rectangle (int width, int height, char character)
    // void rectangle (int width, int height, char character, char fillChar)
    // def rectangle (width, height, character, fillChar=' ')

    // Will draw the outline on the screen of a rectangle with the specified width and height.
    // Use character to draw the outline.
    // Use fillChar for all characters inside the outline.
    // Use a blank space as the fill character when not specified.
    // You can assume that the width and height will be positive.

    // In Java and C++ all output must originate in one of the drawRect methods.
    // The “other” rectangle will use the other rectangle method to create the output.
    // When creating the output, the outline will use the character char.
    // Python will only have a single rectangle function.

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if ( (i == 0) || (i == height - 1) ){ cout << character; }
            else {
                if ( (j == 0) || (j == width - 1) ){ cout << character; }
                else { cout << fillChar; }
            }
        }
        cout << "\n";
    }

    return;
}
void HW3::rectangle (int width, int height, char character){
    // Same Comments as Above rectangle function ---/\

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if ( (i == 0) || (i == height - 1) ){ cout << character; }
            else {
                if ( (j == 0) || (j == width - 1) ){ cout << character; }
                else { cout << " "; }
            }
        }
        cout << "\n";
    }

    return;
}

int HW3::summation (int value){
    // int summation (int value)
    // def summation (int value)

    // returns the summation of 1 to intValue. You can assume that intValue will be positive.
    // For example, summation (5) would return 15 (1 + 2 + 3 + 4 + 5).

    int sum = 0;
    for (int i = 1; i <= value; i++){
        sum += i;
    }

    return sum;
}

int HW3::sumOfSquare (int value){
    // int sumOfSquare (int value)
    // def sumOfSquare (value)

    // returns the sum of the squares from 1 to value. For example, sumOfSquares(5) would return 55 (1 + 4 + 9 + 16 + 25).
    // You MUST use a loop and the square function to determine the returned value.

    int sum = 0;
    for (int i = 1; i <= value; i++){
        sum += this->square(i);
    }

    return sum;
}

int HW3::square (int value){
    // int square (int value)
    // def square (value)

    // returns the square of value.

    return (value * value);
}

int main (void){
    // Tests all of the required functions / methods

    HW3 hw3;

    hw3.inputWithinRange("Enter a Value1: ", -20, 100); cout << '\n';
    hw3.inputWithinRange("Enter a Value2: ", 10); cout << '\n';

    hw3.isAFactor(2, 200); cout << '\n';
    hw3.isAFactor(200, 2); cout << '\n';

    hw3.rectangle(5, 5, '&'); cout << '\n';
    hw3.rectangle(10, 10, '@', '~'); cout << '\n';

    cout << hw3.square(50) << '\n';
    cout << hw3.square(10) << '\n';

    cout << hw3.summation(10) << '\n';
    cout << hw3.summation(5) << '\n';

    cout << hw3.sumOfSquare(10) << '\n';
    cout << hw3.sumOfSquare(5) << '\n';

    return 0;
}
