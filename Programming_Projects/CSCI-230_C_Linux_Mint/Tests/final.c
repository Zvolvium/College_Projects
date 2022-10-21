// Mason Motschke CSCI 230-01
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct binaryTree { float val; struct binaryTree *right, *left; };
struct LinkedList { int *pointer; struct LinkedList *next; };

int Scan(void){
	FILE *fp; fp = fopen("final.data", "r"); if (fp == NULL){ printf("Error: File Failed to open!\n"); exit(1); }
	printf(" - Getting File Size...\n"); int index = 0; size_t line_size = 0; char *line_buff = NULL;
	while (1){
		getline(&line_buff, &line_size, fp); if (feof(fp)){ printf("File Size Found\n\n"); fclose(fp); return index; } else index++; }
}

void Readfile(float data[], int size){
	FILE *fp; fp = fopen("final.data", "r"); if (fp == NULL){ printf("Error: File Failed to open!\n"); exit(1); }
	printf(" - Reading File...\n"); int index;
	for (index = 0; index < size; index++){ fscanf(fp, "%f", &data[index]); } fclose(fp); printf("File Read\n\n");
}

void Sort(float data[], int size){
	int index, temp, cont; printf(" - Sorting Data...\n");
	for (cont = 0; cont < (size * size); cont++){
		for (index = 0; index < size; index++){
			if (data[index] > data[index + 1]){ temp = data[index]; data[index] = data[index + 1]; data[index + 1] = temp; }
		}
	}
	printf("Data Sorted\n\n");
}

void AddTree(struct binaryTree *(*tree), float item, struct LinkedList *List){
	if (*tree == NULL){ // Base Case
		while (List != NULL){ List = List->next; }
		List = (struct LinkedList*)malloc(sizeof(struct LinkedList)); // Sets up List
		/*List->pointer = (int*)malloc(sizeof(int));*/ List->next = NULL;
		*tree = (struct binaryTree*)malloc(sizeof(struct binaryTree)); // Sets up Tree
		(*tree)->val = item; (*tree)->right = NULL; (*tree)->left = NULL;
		List->pointer = (*tree); // Points List pointer to Tree
	}
	else if (item < (*tree)->val){ AddTree(&(*tree)->left, item, &(*List)); }
	else if (item > (*tree)->val){ AddTree(&(*tree)->right, item, &(*List)); }
}

void TraverseTreePre(struct binaryTree *tree){
	printf("%5.2f ", tree->val);
	if (tree->left != NULL){ TraverseTreePre(tree->left); }
	if (tree->right != NULL){ TraverseTreePre(tree->right); }
}

void TraverseTreeIn(struct binaryTree *tree){
	if (tree->left != NULL){ TraverseTreeIn(tree->left); }
	printf("%5.2f ", tree->val);
	if (tree->right != NULL){ TraverseTreeIn(tree->right); }
}

void TraverseTreePost(struct binaryTree *tree){
	if (tree->left != NULL){ TraverseTreePost(tree->left); }
	if (tree->right != NULL){ TraverseTreePost(tree->right); }
	printf("%5.2f ", tree->val);
}

void TraverseList(struct LinkedList *List){
	/*
	struct LinkedList *curr = List;                     //Still doesn't work
	while(curr != NULL){
		printf("%5.2f ", &List->pointer->val);
		curr = curr->next;
	}
	*/
}

void FreeAll(struct LinkedList *List){ // Should work if list works
	struct LinkedList *curr = List; struct LinkedList *temp = List;
	while (curr != NULL){
		curr = curr->next; free(temp); temp = curr;
	}
}

int main(void){
	int size = Scan(); float data[size]; Readfile(data, size); int index;
	struct binaryTree *myTree; myTree = NULL; struct LinkedList *head; head = NULL;
	for (index = 0; index < size; index++){ AddTree(&myTree, data[index], head); } // Builds Tree from data list
	printf("Pre-Order: "); TraverseTreePre(myTree); printf("\n");
	printf("In-Order: "); TraverseTreeIn(myTree); printf("\n");
	printf("Post-Order: "); TraverseTreePost(myTree); printf("\n");
	printf("Traverse List: "); TraverseList(head); printf("\n"); FreeAll(head);
}
