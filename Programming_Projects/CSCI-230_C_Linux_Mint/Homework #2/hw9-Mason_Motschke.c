// Mason Motschke - CSCI 230
/* I will be doing the extra credit using a doubly linked list */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node { char name[5]; struct node *next; struct node *last; } list;

void AddFirstNode (list *head, char name[]){ // adds first node to linked list
  list *curr = head->next; strcpy(curr->name, name); curr->last = NULL; curr->next = NULL; return;
}

void AddNode (list *head, char name[]){
/* Segfaulted at last else if statment because it was last */
/* Now works after moving said else if to second else if in sequence from top to bottom???? */

  list *curr = head->next;
  if (strcmp(curr->name, "") == 0){ AddFirstNode(head, name); return; }
  while (curr != NULL){
    //printf("while\n %s %d %s %s\n", curr, strcmp(name, curr->name), curr->name, curr->next);
    if ( (strcmp(name, curr->name) < 0) && (curr->last == NULL) ){
      list *node = (list*)malloc(1*sizeof(list)); head->next = node;
      node->next = curr; node->last = NULL; curr->last = node; strcpy(node->name, name); return;
    } // Troublesome else if statement directly below <---------------------------------------------------
    else if ( (strcmp(name, curr->name) > 0) && (curr->next == NULL) ){ //printf("!\n");
      list *node = (list*)malloc(1*sizeof(list)); node->last = curr; //printf("@\n");
      node->next = NULL; curr->next = node; strcpy(node->name, name); return;
    }
    else if ( (strcmp(name, curr->name) < 0) && (strcmp(name, curr->last->name) > 0) ){
      list *node = (list*)malloc(1*sizeof(list));
      node->next = curr; node->last = curr->last; curr->last = node; curr = curr->last->last;
      //if (curr == NULL){ head->next = node; curr = head->next; strcpy(curr->name, name); return; }
      curr->next = node; curr = curr->next; strcpy(curr->name, name); return;
    }
    else if ( (strcmp(name, curr->name) > 0) && (strcmp(name, curr->next->name) < 0) ){
      list *node = (list*)malloc(1*sizeof(list));
      node->next = curr->next; node->last = curr; curr->next = node; curr = curr->next->next;
      //if (curr == NULL){ curr = node; strcpy(curr->name, name);  return; }
      curr->last = node; curr = curr->last; strcpy(curr->name, name); return;
    }
    /*else if ( (strcmp(name, curr->name) > 0) && (curr->next == NULL) ){ //printf("!\n");
      list *node = (list*)malloc(1*sizeof(list)); node->last = curr; //printf("@\n");
      node->next = NULL; curr->next = node; strcpy(node->name, name); return;
    }*/ /*printf("next\n");*/
    curr = curr->next;
  } return;
}
/*
void AddFirstNode (list *head, char name[]){ // adds first node to linked list
  list *curr = head->next; strcpy(curr->name, name); curr->last = NULL; curr->next = NULL; return;
}*/

void DeleteNode (list *head, char name[]){ // deletes node from linked list ------ Works -------
  list *curr = head->next;
  while (curr != NULL){
    if (strcmp(curr->name, name) == 0){ // Delete node from list
      curr->next->last = curr->last; curr->last->next = curr->next;
      curr->next = NULL; curr->last = NULL; free(curr); return;
    } curr = curr->next;
  }
}

void FreeAll (list *head){ // frees all data points in linked list
  list *curr = head->next->next; free(head); head = NULL;
  while (curr != NULL){
    curr->last->last = NULL; curr->last->next = NULL; free(curr->last);
    if (curr->next == NULL){
      curr->last = NULL; curr->next = NULL; free(curr); curr = NULL; break;
    } curr = curr->next;
  } return;
}

void PrintAll (list *head){ // prints data all points in list
  list *curr = head->next; printf("\n - Forwards List: \n");
  while (curr != NULL){ printf("Node: %s\n", curr->name); curr = curr->next; } curr = head->next;
  while (curr->next != NULL){ curr = curr->next; } printf("\n - Backwards List: \n");
  while (curr != NULL){ printf("Node: %s\n", curr->name); curr = curr->last; } printf("\n"); return;
}

int main (void){
  FILE *fp; fp = fopen("hw5.data", "r");
  if (fp == NULL){ printf("Error: File couldn't be opened!\n"); exit(1); }
  printf("\n - Reading File...\n"); char letter[2], name[5]; int size;
  list *head; head = (list*)malloc(sizeof(list)); head->next = (list*)malloc(sizeof(list));
  size_t line_size = 0; char *line_buff = NULL;
  while (1){
    getline(&line_buff, &line_size, fp); size = strlen(line_buff); line_buff[size - 1] = '\0';
    strncpy(name, line_buff, 4); name[4] = '\0'; // Index 4 is last index in name[5]; indicate string w/  '\0'
    letter[0] = line_buff[size - 2]; letter[1] = '\0'; // Set letter to be string w/ '\0' at last index
    //printf("Buffer: %s\nSize: %d\n", line_buff, size);
    //printf("Name: %s - Letter: %s\n\n", name, letter);
    if (strcmp(letter, "a") == 0){ AddNode(head, name); }// <---------'a'-------------------------
    else if (strcmp(letter, "d") == 0){ DeleteNode(head, name); }// <----'d'----------------------
    if (feof(fp)){ break; }
  } free(line_buff); line_buff = NULL; // Final buffer termination
  fclose(fp); printf("File Read\n"); PrintAll(head); FreeAll(head); return 0;
}
