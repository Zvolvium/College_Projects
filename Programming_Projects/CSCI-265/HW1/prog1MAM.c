/*
    File Name: prog1MAM.c

    gcc version: 12.2.0

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

void part1 (void){
    printf("---------- Part 1 ----------\n");
    printf("Enter the number of seconds(EX: 5): ");

    long start; scanf("%ld", &start);
    long sec = (start % 60); long min = ((start / 60) % 60); long hrs = ((start / 60) / 60);

    printf("\n -- Hours: %ld, Minutes: %ld, Seconds: %ld\n\n", hrs, min, sec);
}

void part2 (void){
    int quarters, dimes, nickles, pennies;

    printf("---------- Part 2 ----------\n");
    printf("Enter Number of Quarters(EX: 5): "); scanf("%d", &quarters);
    printf("Enter Number of Dimes(EX: 5): "); scanf("%d", &dimes);
    printf("Enter Number of Nickles(EX: 5): "); scanf("%d", &nickles);
    printf("Enter Numbrer of Pennies(EX: 5): "); scanf("%d", &pennies);

    int dollars = ((quarters * 0.25) + (dimes * 0.10) + (nickles * 0.05) + (pennies * 0.01));
    int cents = ((int)(((quarters * 0.25) + (dimes * 0.10) + (nickles * 0.05) + (pennies * 0.01)) * 100) % 100);

    printf("\n -- Dollars: %d, Cents: %d\n\n", dollars, cents);
}

void part3 (void){
    char first[1000], last[1000], addr[1000], city[1000], state[1000], zip[1000];

    printf("---------- Part 3 ----------\n");
    printf("Enter your First Name: "); scanf("%s", first);
    printf("Enter your Last Name: "); scanf("%s", last);
    printf("Enter Address: "); scanf("%s", addr);
    printf("Enter City: "); scanf("%s", city);
    printf("Enter State: "); scanf("%s", state);
    printf("Enter Zip Code: "); scanf("%s", zip);

    // Print format using 1 print statement
    printf("\n%s, %s\n%s\n%s, %s  %s\n\n", first, last, addr, city, state, zip);

    // Print format using 6 print statements
    printf("%s, ", first); printf("%s\n", last);
    printf("%s\n", addr);
    printf("%s, ", city); printf("%s  ", state); printf("%s\n\n", zip);
}

int main (void){
    part1(); part2(); part3();
    return 0;
}
