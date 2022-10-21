// Mason Motschke CSCI 230 - 01
#include <stdlib.h>
#include <stdio.h>
#define ArraySize 20
#define Max 100

struct dict {char string1[ArraySize]; float fval; int ival; char string2[ArraySize];} temp;

void Display(void){
	printf("What do you want to do?\n"); printf("------------------------------\n"); printf("\n");
	printf("1) Sort data by float value & print high-low\n");
	printf("2) Sort data by float value & print low-high\n");
	printf("3) Sort data by int value & print high-low\n");
	printf("4) Sort data by int value & print low-high\n"); 
	printf("5) Exit\n"); printf("\n");
}

int ReadFile(struct dict data[]){
	FILE *fp; fp = fopen("hw2.data", "r"); int index = 0;
	if (fp == NULL){ printf("  Error: File failed to open! \n"); exit(1);} printf("Reading File - hw3.data...\n");
	while (1){
		fscanf(fp, "%s %f %d %s", data[index].string1, &data[index].fval, &data[index].ival, data[index].string2);
		if (feof(fp)) break; else index++;
	}
	printf("File Read - hw3.data\n"); printf("\n"); fclose(fp); return index;
}

void Sortf(struct dict data[], int dataAmount){
	int i = 0, z = 0; printf("Sorting by Floats...\n");
		for (; z < dataAmount; z++){
			i = 0;
			for (; i < dataAmount - 1; i++){ 
				if (data[i].fval > data[i + 1].fval){ 
					temp = data[i]; data[i] = data[i+1]; data[i+1] = temp;
				}
			}
		}
	printf("Sorting Complete\n"); printf("\n");
}

void Sorti(struct dict data[], int dataAmount){
	int i = 0, z = 0; printf("Sorting by Integers...\n");
		for (; z < dataAmount; z++){
			i = 0;
			for (; i < dataAmount - 1; i++){ 
				if (data[i].ival > data[i + 1].ival){ 
					temp = data[i]; data[i] = data[i+1]; data[i+1] = temp;
				}
			}
		}
	printf("Sorting Complete\n"); printf("\n");
}

void PrintHL(struct dict data[], int dataAmount){
	int i = dataAmount - 1;
	for (; i != -1; i--){
		printf("%s %f %d %s \n", data[i].string1, data[i].fval, data[i].ival, data[i].string2);
	}
	printf("\n");
}

void PrintLH(struct dict data[], int dataAmount){
	int i = 0;
	for (; i < dataAmount; i++){
		printf("%s %f %d %s \n", data[i].string1, data[i].fval, data[i].ival, data[i].string2);
	}
	printf("\n");
}

int main(void){
	int user, dataAmount; struct dict data[Max]; dataAmount = ReadFile(data); Display(); 
	printf("What is your choice (Ex: 5): "); scanf("%d", &user); printf("\n");
	while (1){
		if (user == 5) return 0;
		else if (user == 1){ ReadFile(data); Sortf(data, dataAmount); PrintHL(data, dataAmount);}
		else if (user == 2){ ReadFile(data); Sortf(data, dataAmount); PrintLH(data, dataAmount);}
		else if (user == 3){ ReadFile(data); Sorti(data, dataAmount); PrintHL(data, dataAmount);}
		else if (user == 4){ ReadFile(data); Sorti(data, dataAmount); PrintLH(data, dataAmount);}
		Display(); printf("What is your choice: "); scanf("%d", &user); printf("\n");
	}
}
