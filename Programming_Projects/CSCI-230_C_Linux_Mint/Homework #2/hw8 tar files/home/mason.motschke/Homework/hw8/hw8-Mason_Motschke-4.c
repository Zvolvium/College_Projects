// Mason Motschke CSCI 230
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

typedef struct BinaryTree { int val; struct BinaryTree *left, *right; } Btree;
typedef struct LinkedList { struct BinaryTree *node; struct LinkedList *next, *last;} Llist;

#include "./hw8-list-Mason_Motschke.h"
#include "./hw8-tree-Mason_Motschke.h"

int ScanFile (void){
  FILE *fp; fp = fopen("hw6.data", "r");
  if (fp == NULL){ printf("\nError: File Failed to Open!!\n"); exit(0); }
  printf("\n - Getting File Size...\n"); int index = 0; size_t line_size = 0; char *line_buff = NULL;
  while (1){
    getline(&line_buff, &line_size, fp);
    if (feof(fp)){ printf("File Size Found\n"); fclose(fp); return (index + 1); } else index++;
  }
}

void ReadFile (int data[], int size){
  FILE *fp = fopen("hw6.data", "r"); int i; printf("\n - Reading File...\n");
  for (i = 0; i < size; i++){ fscanf(fp, "%d", &data[i]); } fclose(fp); printf("File Read\n\n"); return;
}

void Sort (int data[], int size){
  int i, x, temp; printf(" - Sorting Data...\n");
  for (i = 0; i < (size * size); i++){
    for (x = 0; x < (size - 1); x++){
      if (data[x] > data[x+1]){ temp = data[x+1]; data[x+1] = data[x]; data[x] = temp; }
    }
  } printf("Sorting Complete\n\n");
}

void FreeAll (Llist *head){ // Frees all nodes using traversal of linked list
  Llist *curr = head->next; head->next = NULL; Btree *TreeNode; free(head);
  printf(" - Freeing Tree and List...\n");
  while (curr != NULL){
    /* Free Tree Nodes */
    TreeNode = curr->node; TreeNode->left = TreeNode->right = NULL; free(TreeNode); TreeNode = NULL;
    /* Free List Nodes */
    if (curr->next != NULL){ curr = curr->next; free(curr->last); curr->last = NULL; }
    else { free(curr); printf("Tree and List Freed\n\n"); return; }
  } return;
}

int main (void){
  // Sets up shared Library ---------------\/
  void *handle = dlopen("./hw8-lib-Mason_Motschke.so", RTLD_LAZY);
  if (!handle){ printf("\nError: %s\n", dlerror()); }
  void (*printTree)(Btree*); void (*printList)(Llist*);
  void (*addTree)(Btree**, int, Llist**, Llist*);
  printTree = dlsym(handle, "PrintTree"); printList = dlsym(handle, "PrintList");
  addTree = dlsym(handle, "AddTree");
  // --------------------------------------^

  int size = ScanFile(); int data[size], index; ReadFile(data, size); Sort(data, size);
  Btree *myTree = NULL; Llist *head; head = (Llist*)malloc(sizeof(Llist)); head->next = NULL;
  for (index = 0; index < size; index++){ (*addTree)(&myTree, data[index], &head, head); }
  (*printTree)(myTree); (*printList)(head); FreeAll(head); dlclose(handle); return 0;
}