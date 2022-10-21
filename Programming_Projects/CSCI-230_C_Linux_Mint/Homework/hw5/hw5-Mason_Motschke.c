#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct data { char *name; long number; };

#include "./hw5-A-Mason_Motschke.h"
#include "./hw5-B-Mason_Motschke.h"
#include "./hw5-C-Mason_Motschke.h"
#include "./hw5-D-Mason_Motschke.h"

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
