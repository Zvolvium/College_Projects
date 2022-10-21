// Mason Motschke CSCI 230 - 01
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct data { char className[42]; int *head; };

struct doublyLinkedList { char name[42]; char number[8]; int *last; int *next; } *FAT;

int Scan(void){
	FILE *fp; fp = fopen("hw6.data", "r"); if (fp == NULL){ printf("Error: File Failed to open"); exit(1); }
	printf(" - Getting File Size...\n"); int index = 0; char class[42], name[42], number[8], letter[2];
	while (1){ fscanf(fp, "%s %s %s %s", class, name, number, letter); if (feof(fp)) break; else index++; }
	fclose(fp); printf("File Size Found\n\n"); return index;
}

int SearchDirect(char class[], struct data directory[], int choice){// Returns if class is found or not (1 = Found, 0 = not Found)
	int Flag = 0, place;
	if (choice == 0){ // in direct = 1; not in direct = 0
		for (place = 0; place < 10; place++){
			if (strcmp(class, directory[place].className) == 0){ Flag = 1; break; }
		} return Flag;
	}
	else if (choice == 1){ // returns index of class
		for (place = 0; place < 10; place++){
			if (strcmp(class, directory[place].className) == 0){ break; }
		} return place;
	}
}

int OpenSpace(struct data directory[], struct doublyLinkedList *FAT, char choice[], int size){
	int openSpace, index, flag = 0;
	if (strcmp(choice, "FAT") == 0){ // Search FAT for open space
		for (index = 0; index < size; index++){
			if (strcmp(FAT[index].name, "") == 0){ flag = 1; break; } }
			if (flag == 0){ printf("Error: No Open Space in FAT!\n"); exit(1); } return index;
	} else if (strcmp(choice, "Direct") == 0){ // Search Directory for open space
			for (index = 0; index < 10; index++){ if(strcmp(directory[index].className, "") == 0){ flag = 1; break; } }
			if (flag == 0){ printf("Error: No Open Space in Directory!\n"); exit(1); } return index;
		}
}

void addFirstNode(struct data directory[], struct doublyLinkedList *FAT, char class[], char name[], char number[], int size){
	int openIndexDirect = OpenSpace(directory, FAT, "Direct", size); int Dcurr = openIndexDirect;
	int openIndexFAT = OpenSpace(directory, FAT, "FAT", size); int Fcurr = openIndexFAT;
	strcpy(directory[Dcurr].className, class); // Adds class to directory
	directory[Dcurr].head = (int*)malloc(1*sizeof(int)); *directory[Dcurr].head = openIndexFAT; // Sets head to start of list
	strcpy(FAT[Fcurr].name, name); strcpy(FAT[Fcurr].number, number);
	FAT[Fcurr].last = (int*)malloc(1*sizeof(int)); FAT[Fcurr].next = (int*)malloc(1*sizeof(int));
	*FAT[Fcurr].last = (0 - Dcurr); *FAT[Fcurr].next = (0 - Dcurr);
}

void addNode(struct data directory[], struct doublyLinkedList *FAT, char class[], char name[], char number[], int size){
	int openIndexFAT = OpenSpace(directory, FAT, "FAT", size); int Fcurr = openIndexFAT;
	strcpy(FAT[Fcurr].name, name); strcpy(FAT[Fcurr].number, number); // Sets up node
	FAT[Fcurr].last = (int*)malloc(1*sizeof(int)); FAT[Fcurr].next = (int*)malloc(1*sizeof(int));
	int classIndex = SearchDirect(class, directory, 1); int fatIndex = *directory[classIndex].head; int index;
	while (1){ // Finds last node in linked list
		if (*FAT[fatIndex].next == (0 - classIndex)){ break; } fatIndex = *FAT[fatIndex].next; }
	*FAT[fatIndex].next = Fcurr; *FAT[Fcurr].last = fatIndex; *FAT[Fcurr].next = (0 - classIndex); // Sets .last + .next
}

void PrintAll(struct data directory[], struct doublyLinkedList *FAT){
	int index, curr; printf("Printing Format - \n"); printf("DIRECTORY Information\n"); printf(" - FAT Information\n");
	for (index = 0; index < 10; index++){
		if (strcmp(directory[index].className, "") == 0){ continue; }
		else {
			curr = *directory[index].head;
			printf("\nIndex: %d, Class: %s, Starting Block: %d\n", index, directory[index].className, *directory[index].head);
			while (1){
				printf(" - Index: %d, Name: %s, Number: %s, Previous: %d, Next: %d\n", curr, FAT[curr].name, FAT[curr].number, *FAT[curr].last, *FAT[curr].next);
				if (*FAT[curr].next == (0 - index)){ break; } curr = *FAT[curr].next;
			}
		}
	}
	printf("\n");
}

void FreeAll(struct data directory[], struct doublyLinkedList *FAT){ // Problems in PrintAll apply here ;(
	int index, curr;
	for (index = 0; index < 10; index++){
		if (strcmp(directory[index].className, "") == 0){ continue; }
		else {
			curr = *directory[index].head; free(directory[index].head); // Frees all directory.heads
			while (1){
				if (*FAT[curr].next == (0 - index)){  free(FAT[curr].next); free(FAT[curr].last); break; }
				curr = *FAT[curr].next; free(FAT[*FAT[curr].last].next); free(FAT[*FAT[curr].last].last); // Frees all .last + .next
			}
		}
	}
}

int SearchFAT(struct data directory[], struct doublyLinkedList *FAT, char name[], char number[]){
	int index, curr; printf(" - - For\n");
	for (index = 0; index < 10; index++){ if (strcmp(directory[index].className, "") == 0){ continue; }
		else { printf(" - - curBefore\n");
			curr = directory[index].head; printf(" - - currAfter\n");
			while (1){ printf(" - - if1\n");
				if ((strcmp(FAT[curr].name, name) == 0) && (strcmp(FAT[curr].number, number) == 0)){ return curr; }
				printf(" - - if2\n");
				if (FAT[curr].next == (0 - index)){ printf(" ~ ~~ break\n"); break; } printf(" ~ ~~~ else\n"); curr = *FAT[curr].next; }
		}
	}
	return -1;
}

void Delete(struct data directory[], struct doublyLinkedList *FAT, char class[], char name[], char number[]){
	int deleteIndex = SearchFAT(directory, FAT, name, number);
	if (deleteIndex == -1){ return; } // Name not found in FAT
	else { // Name found in FAT
		int curr = deleteIndex;
		while (1){ if (*FAT[curr].next >= 0){ curr = *FAT[curr].next; } else { curr = *FAT[curr].next; break; } }
		int directIndex = curr; /* Direct index is still negative */
		if (*FAT[deleteIndex].last == directIndex){                               // First in list
			strcpy(FAT[deleteIndex].name, ""); strcpy(FAT[deleteIndex].number, ""); FAT[deleteIndex].next = NULL;
			FAT[deleteIndex].last = NULL; free(FAT[deleteIndex].next); free(FAT[deleteIndex].last); curr = (0 - directIndex);
			strcpy(directory[curr].className, ""); directory[curr].head = NULL; free(directory[curr].head);
		}
		else if ((*FAT[deleteIndex].last >= 0) && (*FAT[deleteIndex].next >= 0)){ // In Middle of list
			strcpy(FAT[deleteIndex].name, ""); strcpy(FAT[deleteIndex].number, ""); curr = *FAT[deleteIndex].last;
			int curr2 = *FAT[deleteIndex].next; *FAT[curr].next = curr2; *FAT[curr2].last = curr;
			FAT[deleteIndex].last = FAT[deleteIndex].next = NULL; free(FAT[deleteIndex].last); free(FAT[deleteIndex].next);
		}
		else if (*FAT[deleteIndex].next == directIndex){                          // Last in list
			strcpy(FAT[deleteIndex].name, ""); strcpy(FAT[deleteIndex].number, ""); curr = *FAT[deleteIndex].last;
			*FAT[curr].next = directIndex; FAT[deleteIndex].last = FAT[deleteIndex].next = NULL;
			free(FAT[deleteIndex].next); free(FAT[deleteIndex].last);
		}
	}
}

void Search(struct data directory[], struct doublyLinkedList *FAT, char class[], char name[], char number[]){
	printf(" - SearchFAT\n");
	int searchIndex = SearchFAT(directory, FAT, name, number); printf(" ~ Searching for %s...\n", name);
	if (searchIndex == -1){ printf(" ~ %s not found\n\n", name); return; } // Name not found in FAT
	else { // Name found in FAT
		int curr = searchIndex;
		while (1){ if (*FAT[curr].next >= 0){ curr = *FAT[curr].next; } else { curr = *FAT[curr].next; break; } }
		int directIndex = (0 - curr); curr = *directory[directIndex].head;
		printf(" ~ Name Found in Group Name: %s - Printing Group:\n", directory[directIndex].className);
		while (1){ printf(" ~~ Name: %s, Number: %s\n", FAT[curr].name, FAT[curr].number);
				if (*FAT[curr].next == (0 - directIndex)){ break; } curr = *FAT[curr].next;
		} printf("\n");
	}
}

int main(void){
	int size = Scan(); struct data directory[10]; struct doublyLinkedList *FAT;
	FAT = (struct doublyLinkedList*)malloc(size * (sizeof(struct doublyLinkedList)));
	FILE *fp; fp = fopen("hw6.data", "r"); if (fp == NULL){ printf("Error: File Failed to open\n"); exit(1);}
	printf(" - Reading File...\n\n"); int index, inDirect; char class[42], name[42], number[8], letter[2]; int openIndexDirect;
	for (index = 0; index < size; index++){ printf("Scan\n");
		fscanf(fp, "%s %s %s %s", class, name, number, letter);//printf("%s %s %s %s\n", class, name, number, letter);
		if (strcmp(letter, "a") == 0){ // If letter is 'a' <--------------------------------------------------------------------------
			printf("inDirect\n"); inDirect = SearchDirect(class, directory, 0);
			if (inDirect == 0){ printf("addFirstNode\n"); addFirstNode(directory, FAT, class, name, number, size); } // If class is not in directory
			else if (inDirect == 1){ printf("addNode\n"); addNode(directory, FAT, class, name, number, size); } // If class is in directory      'a' = completed !!
		} else if (strcmp(letter, "d") == 0){ // If letter is 'd' <-------------------------------------------------------------------
				printf("Delete\n"); Delete(directory, FAT, class, name, number); // No Class Needed; Search for person directly !!          'd' = completed !!
			} else if (strcmp(letter, "q") == 0){ // If letter is 'q' <-----------------------------------------------------------------
					printf("Search\n"); Search(directory, FAT, class, name, number); // No Class Needed; Search for person directly !!        'q' = completed !!
				}
	}
	fclose(fp); printf("File Read\n\n"); PrintAll(directory, FAT); FreeAll(directory, FAT); free(FAT); return 0;
}
