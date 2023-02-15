/*
    File Name: prog2MAM.cpp

    g++ version: 12.2.0

    Author: Mason A. Motschke

    Contact: mason.motschke@und.edu

    Comment:
        Write each of the following programs in C, C++, Python, and Java.
        Write a program that surveys the majors of students in some unnamed class.
        Only majors I’m concerned with are Computer Science, Data Science, and Cyber Security.
        For only the CS majors we want to ask about their minor.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct majorDict { char majors[4][10]; int occur[4]; } majDict;
typedef struct minorDict { char minors[4][10]; int occur[4]; } minDict;

void dictSetup (majDict *MajDict, minDict *MinDict){
    // Major Setup
    strcpy(MajDict->majors[0], "cs");
    strcpy(MajDict->majors[1], "data");
    strcpy(MajDict->majors[2], "cyber");
    strcpy(MajDict->majors[3], "other");
    MajDict->occur[0] = MajDict->occur[1] = 0;
    MajDict->occur[2] = MajDict->occur[3] = 0;

    // Minor Setup
    strcpy(MinDict->minors[0], "data");
    strcpy(MinDict->minors[1], "cyber");
    strcpy(MinDict->minors[2], "math");
    strcpy(MinDict->minors[3], "other");
    MinDict->occur[0] = MinDict->occur[1] = 0;
    MinDict->occur[2] = MinDict->occur[3] = 0;
}

void getMinor (minDict *MinDict){
    char input[100];
    printf("Enter your Minor: ");
    scanf("%s", input); printf("\n");
    for (int i = 0; i < strlen(input); i++){ input[i] = tolower(input[i]); }
    if (strcmp(input, "data") == 0){ MinDict->occur[0]++; }
    else if (strcmp(input, "cyber") == 0){ MinDict->occur[1]++; }
    else if (strcmp(input, "math") == 0){ MinDict->occur[2]++; }
    else { MinDict->occur[3]++; }
}

void getData (majDict *MajDict, minDict *MinDict){
    printf("\nEnter a Major('done to quit'): ");
    char input[100];
    scanf("%s", input); printf("\n");
    for (int i = 0; i < strlen(input); i++){ input[i] = tolower(input[i]); }
    while (strcmp(input, "done") != 0){
        if (strcmp(input, "cs") == 0){
            MajDict->occur[0]++;
            getMinor(MinDict);
        }
        else if (strcmp(input, "data") == 0){ MajDict->occur[1]++; }
        else if (strcmp(input, "cyber") == 0){ MajDict->occur[2]++; }
        else { MajDict->occur[3]++; }

        printf("\nEnter a Major('done to quit'): ");
        scanf("%s", input); printf("\n");
        for (int i = 0; i < strlen(input); i++){ input[i] = tolower(input[i]); }
    }
}

void printData (majDict *MajDict, minDict *MinDict){
    printf("\nNumber of students surveyed: ");

    int cnt = 0;
    for (int i = 0; i < 4; i++){
        MajDict->majors[i][0] = toupper(MajDict->majors[i][0]);
        MinDict->minors[i][0] = toupper(MinDict->minors[i][0]);
        cnt = MajDict->occur[i] + cnt;
    } printf("%d\n", cnt);

    printf("\nMajors:\n");
    for (int i = 0; i < 4; i++){
        if (cnt == 0){
            printf("%-10s %3d %10.2f\n", MajDict->majors[i], MajDict->occur[i], (float)cnt);
        }
        else {
            printf("%-10s %3d %10.2f\n", MajDict->majors[i], MajDict->occur[i], (float)(((float)MajDict->occur[i] / (float)cnt) * 100));
        }
    }

    cnt = 0;
    for (int i = 0; i < 4; i++){ cnt = MinDict->occur[i] + cnt; }

    printf("\nMinors of CS Majors:\n");
    for (int i = 0; i < 4; i++){
        if (cnt == 0){
            printf("%-10s %3d %10.2f\n", MinDict->minors[i], MinDict->occur[i], (float)cnt);
        }
        else {
            printf("%-10s %3d %10.2f\n", MinDict->minors[i], MinDict->occur[i], (float)(((float)MinDict->occur[i] / (float)cnt) * 100));
        }
    } printf("\n");
}

int main (void){
    majDict *MajDict = (majDict*)malloc(sizeof(majDict));
    minDict *MinDict = (minDict*)malloc(sizeof(minDict));

    dictSetup(MajDict, MinDict);

    getData(MajDict, MinDict);

    printData(MajDict, MinDict);

    free(MajDict); free(MinDict);
    return 0;
}
