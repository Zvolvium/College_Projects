// Mason Motschke CSCI 230

typedef struct BinaryTree { int val; struct BinaryTree *left, *right; } Btree;
typedef struct LinkedList { struct BinaryTree *node; struct LinkedList *next, *last;} Llist;

#include "./hw8-list-Mason_Motschke.h"

void PrintList (Llist *head){ // Prints nodes using the linked list
  printf(" - Printing Linked List...\n"); Llist *curr = head->next;
  while (curr != NULL){ printf("Node: %d\n", curr->node->val); curr = curr->next; } printf("\n"); return;
}
