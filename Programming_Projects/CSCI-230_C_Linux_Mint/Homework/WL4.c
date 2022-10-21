//Mason Motschke CSCI-230 - 01
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data { char *name; long number; };

int Scan(FILE *(*stream)){ // Works
	*stream = fopen("hw4.data", "r");
	if (*stream == NULL){ printf("Error: Fail couldn't be opened!\n"); exit(1); }
	int index = 0; size_t line_size = 0; char *line_buff = NULL; printf(" - Getting File Size...\n");
	while (1){
		getline(&line_buff, &line_size, *stream);
		if (feof(*stream)) break; else index++;
	}
	rewind(*stream); free(line_buff); line_buff = NULL; printf("File Size Found\n\n"); return index;
}

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

void Search(struct data *phoneBook, char *name, int size){ // Works
	int index, flag = 0;
	for (index = 0; index < size; index++){
		if (flag == 1) break; if (strcmp((phoneBook + index)->name, name) == 0) flag = 1;
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

void Free(struct data *phoneBook, int size){ // Works
	/* Free's the memory allocated in Load to all *name in struct and phoneBook */
	int index;
	for (index = 0; index < size; index++){
		free((phoneBook + index)->name);
	}
	free(phoneBook);
}

int main(int argv, char **argc){
	/* Input: ./wl4 Ken Walloby Jenkens <- argv counts these for size
	In argc: [./wl4, Ken, Walloby, Jenkens, NULL] 
  In argv: size = 4 */
	if (argv < 2){
		printf("***********************************************************************\n");
		printf("* You must include a name to search for (EX: 'Joe' not 'Joe Swanson') *\n");
		printf("***********************************************************************\n"); exit(1);
	} else {
			int size; FILE *stream; size = Scan(&stream); struct data *phoneBook = LOAD(stream, size);
			Search(phoneBook, argc[1], size); Free(phoneBook, size);
		}
	return 0;
}
