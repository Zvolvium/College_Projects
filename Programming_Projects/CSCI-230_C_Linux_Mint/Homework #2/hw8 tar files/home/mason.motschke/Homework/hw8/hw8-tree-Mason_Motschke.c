// Mason Motschke CSCI 230

typedef struct BinaryTree { int val; struct BinaryTree *left, *right; } Btree;
typedef struct LinkedList { struct BinaryTree *node; struct LinkedList *next, *last;} Llist;

#include "./hw8-tree-Mason_Motschke.h"

void AddTree (Btree *(*tree), int item, Llist *(*List), Llist *head){
  if (*tree == NULL){ // Base case
    /* Tree Set-Up */
    *tree = (Btree*)malloc(1*sizeof(Btree)); (*tree)->left = (*tree)->right = NULL; (*tree)->val = item;
    /* Linked List Set-Up */
    Llist *curr = (*List); while ( curr->next != NULL ){ curr = curr->next; }
    Llist *Lnode = (Llist*)malloc(1*sizeof(Llist)); Lnode->node = (*tree);
    curr->next = Lnode; Lnode->next = NULL;
    if (curr == head->next){ Lnode->last = NULL; } else Lnode->last = curr;
  }
  else if ( item < (*tree)->val ){ AddTree(&(*tree)->left, item, &(*List), head); }
  else if ( item > (*tree)->val ){ AddTree(&(*tree)->right, item, &(*List), head); }
}

/* Following Functions print Tree in Specified Orders */
void Pre_Order_Tree (Btree *tree){
  printf("%d ", tree->val);
  if (tree->left != NULL){ Pre_Order_Tree(tree->left); }
  if (tree->right != NULL){ Pre_Order_Tree(tree->right); }
}

void In_Order_Tree (Btree *tree){
  if (tree->left != NULL){ In_Order_Tree(tree->left); }
  printf("%d ", tree->val);
  if (tree->right != NULL){ In_Order_Tree(tree->right); }
}

void Post_Order_Tree (Btree *tree){
  if (tree->left != NULL){ Post_Order_Tree(tree->left); }
  if (tree->right != NULL){ Post_Order_Tree(tree->right); }
  printf("%d ", tree->val);
}

void PrintTree (Btree *tree){
  printf(" - Printing Tree...\n");
  printf("Pre-Order: "); Pre_Order_Tree(tree); printf("\n");
  printf("In-Order: "); In_Order_Tree(tree); printf("\n");
  printf("Post-Order: "); Post_Order_Tree(tree); printf("\n\n");
}
/* Tree Printing Functions End Here */