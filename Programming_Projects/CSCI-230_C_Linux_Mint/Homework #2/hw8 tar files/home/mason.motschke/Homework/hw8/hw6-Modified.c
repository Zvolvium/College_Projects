// Mason Motschke - CSCI 230
#include <stdlib.h>
#include <stdio.h>

typedef struct BinaryTree { int val; struct BinaryTree *left, *right; } Btree;
typedef struct LinkedList { struct BinaryTree *node; struct LinkedList *next, *last; } Llist;

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

void PrintList (Llist *head){ // Prints nodes using the linked list
  printf(" - Printing Linked List...\n"); Llist *curr = head->next;
  while (curr != NULL){ printf("Node: %d\n", curr->node->val); curr = curr->next; } printf("\n"); return;
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

int main (void){
  int size = ScanFile(); int data[size], index; ReadFile(data, size); Sort(data, size);
  Btree *myTree = NULL; Llist *head; head = (Llist*)malloc(sizeof(Llist)); head->next = NULL;
  for (index = 0; index < size; index++){ AddTree(&myTree, data[index], &head, head); }
  PrintTree(myTree); PrintList(head); FreeAll(head); return 0;
}
