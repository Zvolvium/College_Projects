// Mason Motschke CSCI 230 - 01
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node { char name[42]; struct node *next; } node_t;

int Scan(void){
	FILE *fp; fp = fopen("hw7.data", "r"); if (fp == NULL){ printf("Error: File failed to open!!\n"); exit(1); }
	char name[42], letter[2]; int index = 0; printf(" - Getting File Size...\n");
	while (1){ fscanf(fp, "%s %s", name, letter); if (feof(fp)) break; else index++; }
	fclose(fp); printf("File Size Found\n\n"); return index;
}

int InList(node_t *head, char name[]){ // Iterating over list
	node_t *curr = head;
	while (curr != NULL){
		if (strcmp(curr->name, name) == 0){ return 1; }
		else curr = curr->next;
	}
	return 0;
}

void firstNode(node_t *head, char name[]){
	head = (node_t*)malloc(sizeof(node_t)); head->next = NULL;
	strcpy(head->name, name); printf(" -  - Name: %s \n", head->name);
}

void addNode(node_t *head, char name[]){
	node_t *curr = head; while (curr->next != NULL){ curr = curr->next; } // Finding Last Item
	curr->next = (node_t*)malloc(sizeof(node_t)); curr = curr->next; curr->next = NULL; strcpy(curr->name, name);
	printf(" -  - Name: %s \n", curr->name);
}

void delete(node_t *head, char name[]){
	if (head->next == NULL){ free(head); head = NULL; return; /*If only one item in list*/}
	node_t *curr = head; node_t *temp = NULL;
	while (curr != NULL){
		if ( (strcmp(curr->next->name, name) == 0) && (curr->next->next == NULL) ){ free(curr->next); curr->next = NULL; return; }
		else if (strcmp(curr->name, name) == 0){ temp = curr; break; } // In middle of list       Last in List -----^
		curr = curr->next;
	}
	curr = head;
	while (curr->next != temp){ curr = curr->next; } // In middle of list cont...
	curr->next = temp->next; free(temp);
}

void PrintAll(node_t *head){
	node_t *curr = head; printf("Printing List - \n");
	while (curr != NULL){ printf("Name: %s\n", curr->name); curr = curr->next; }
}

void freeAll(node_t *head){
	node_t *curr = head; node_t *temp = head;
	while (curr != NULL){ curr = curr->next; free(temp); temp->next = NULL; temp = curr; }
}

void main(void){
	int size = Scan(); FILE *fp; fp = fopen("hw7.data", "r");
	if (fp == NULL){ printf("Error: File failed to open!!\n"); exit(1); } int index, inList; char name[42], letter[2];
	printf(" - Creating List...\n");
	node_t *head = NULL;
	for (index = 0; index < size; index++){
		fscanf(fp, "%s %s", name, letter);
		if (strcmp(letter, "a") == 0){ // If letter is 'a' <---------------------------------------------------------------------------
			if (head == NULL){ firstNode(head, name); }
			else { addNode(head, name); }
		} else if (strcmp(letter, "d") == 0){ // If letter is 'd' <--------------------------------------------------------------------
				inList = InList(head, name);
				if (inList == 1){ delete(head, name); } // Name in List
				else if (inList == 0){ continue; } // Name not in List
			}
	}
	printf("List Created\n\n"); PrintAll(head); freeAll(head);
}
