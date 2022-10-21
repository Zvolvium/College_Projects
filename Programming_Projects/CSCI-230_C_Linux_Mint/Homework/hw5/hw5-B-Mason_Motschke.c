// Mason Motschke CSCI 230 - 01

struct data { char *name; long number; };

#include "./hw5-B-Mason_Motschke.h"

struct data* LOAD(FILE *stream, int size){ // Works
	/* Loads data from file into struct returns filled struct. File format[name phoneNumber] */
	struct data *phoneBook; phoneBook = (struct data*)malloc(size * (sizeof(struct data)));
	if (phoneBook == NULL){ printf("Error: Failed to Allocate Memory to struct!\n"); exit(1); }
	int index, token_num; size_t line_size = 0; char *line_buff = NULL, *token; printf(" - Reading File...\n");
	for (index = 0; index < size; index++){
		getline(&line_buff, &line_size, stream); token = strtok(line_buff, " "); token_num = 0;
		while (token != NULL){
			if (token_num == 0){
				(phoneBook + index)->name = (char*)malloc(sizeof(token)); strcpy((phoneBook + index)->name, token); token_num++;
			} else if (token_num == 1){
					(phoneBook + index)->number = atoi(token); token_num++;
				}
			//printf("%s\n", token);
			token = strtok(NULL, " ");
		}
		if (feof(stream)) break;
	}
	fclose(stream); free(line_buff); line_buff = NULL; printf("File Read\n\n"); return phoneBook;
}
