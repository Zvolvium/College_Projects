// Mason Motschke CSCI 230 - 01

struct data { char *name; long number; };

#include "./hw5-C-Mason_Motschke.h"

void Search(struct data *phoneBook, char *name, int size){ // Works
	printf("Searching File...\n"); int index, flag = 0;
	for (index = 0; index < size; index++){
		if (flag == 1) break;
		if (strcmp((phoneBook + index)->name, name) == 0) flag = 1;
	}
	if (flag == 0){
		printf("**********************\n");
		printf("* Name was not Found *\n");
		printf("**********************\n\n");
	} else if (flag == 1){
			printf("*************************\n");
			printf("* Name Found at Entry %d *\n", index - 1);
			printf("*************************\n\n");
		}
}
