// Mason Motschke CSCI 230 - 01

struct data { char *name; long number; };

#include "./hw5-D-Mason_Motschke.h"

void Free(struct data *phoneBook, int size){ // Works
	/* Free's the memory allocated in Load to all *name in struct and phoneBook */
	int index;
	for (index = 0; index < size; index++){
		free((phoneBook + index)->name);
	}
	free(phoneBook);
}
