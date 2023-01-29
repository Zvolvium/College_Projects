/*
    File Name: prog1MAM.cpp

    g++ version: 12.2.0

    Author: Mason A. Motschke

    Contact: mason.motschke@und.edu

    Comment:
        Write each of the following programs in C, C++, Python, and Java.
        Write a single problem that addresses all three parts:
            Part 1 – Convert from seconds
            Part 2 – Convert to dollars
            Part 3 - Work with output
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void part1 (void){
    cout << "---------- Part 1 ----------\n";
    cout << "Enter the number of seconds(EX: 5): ";

    long start; cin >> start; //scanf("%d", &start);
    long sec = (start % 60); long min = ((start / 60) % 60); long hrs = ((start / 60) / 60);

    //printf("\n -- Hours: %ld, Minutes: %ld, Seconds: %ld\n\n", hrs, min, sec);
    cout << "\n -- Hours: " << hrs << ", Minutes: " << min << ", Seconds: " << sec << "\n\n";
}

void part2 (void){
    int quarters, dimes, nickles, pennies;

    cout << "---------- Part 2 ----------\n";
    cout << "Enter Number of Quarters(EX: 5): "; cin >> quarters; //scanf("%d", &quarters);
    cout << "Enter Number of Dimes(EX: 5): "; cin >> dimes; //scanf("%d", &dimes);
    cout << "Enter Number of Nickles(EX: 5): "; cin >> nickles; //scanf("%d", &nickles);
    cout << "Enter Numbrer of Pennies(EX: 5): "; cin >> pennies; //scanf("%d", &pennies);

    int dollars = ((quarters * 0.25) + (dimes * 0.10) + (nickles * 0.05) + (pennies * 0.01));
    int cents = ((int)(((quarters * 0.25) + (dimes * 0.10) + (nickles * 0.05) + (pennies * 0.01)) * 100) % 100);

    //printf("\n -- Dollars: %d, Cents: %d\n\n", dollars, cents);
    cout << "\n -- Dollars: " << dollars << ", Cents: " << cents << "\n\n";
}

void part3 (void){
    char first[1000], last[1000], addr[1000], city[1000], state[1000], zip[1000];

    cout << "---------- Part 3 ----------\n";
    cout << "Enter your First Name: "; cin >> first; //scanf("%s", first);
    cout << "Enter your Last Name: "; cin >> last; //scanf("%s", last);
    cout << "Enter Address: "; cin >> addr; //scanf("%s", addr);
    cout << "Enter City: "; cin >> city; //scanf("%s", city);
    cout << "Enter State: "; cin >> state; //scanf("%s", state);
    cout << "Enter Zip Code: "; cin >> zip; //scanf("%s", zip);

    // Print format using 1 print statement
    //printf("\n%s, %s\n%s\n%s, %s  %s\n\n", first, last, addr, city, state, zip);
    cout << "\n" << first << ", " << last << "\n" << addr << "\n" << city << ", " << state << "  " << zip << "\n\n";

    // Print format using 6 print statements
    /*
    printf("%s, ", first); printf("%s\n", last);
    printf("%s\n", addr);
    printf("%s, ", city); printf("%s  ", state); printf("%s\n\n", zip);
    */
   cout << first << ", "; cout << last << "\n";
   cout << addr << "\n";
   cout << city << ", "; cout << state << "  "; cout << zip << "\n\n";
}

int main (void){
    part1(); part2(); part3();
    return 0;
}
