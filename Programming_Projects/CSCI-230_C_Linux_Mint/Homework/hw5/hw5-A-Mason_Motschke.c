// Mason Motschke CSCI 230 - 01
#include "./hw5-A-Mason_Motschke.h"

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
