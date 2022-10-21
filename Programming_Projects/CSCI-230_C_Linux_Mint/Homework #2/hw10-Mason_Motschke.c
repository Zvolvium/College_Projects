// Mason Motschke - CSCI 230
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Graph_All { int cost[10]; char data[101]; struct Graph_All *arcs[10]; } Graph;
typedef struct LinkedList { struct Graph_All *ptr; struct LinkedList *next; } List;

void Graph_SetUp(Graph *node){ //                                                       Works :)
  // Just Sets up pointers for Graph_All

  int i; for (i = 0; i < 10; i++){ node->arcs[i] = NULL; } return;
}

void AddList(List *head, char input[]){ //                                              Works :)
  // Adds to the List and Sets Initial Graph Node

  List *curr = head->next;
  if (head->next == NULL){ // Adds First Node to List
    head->next = (List*)malloc(sizeof(List)); head->next->next = NULL;
    Graph *node = (Graph*)malloc(sizeof(Graph)); Graph_SetUp(node); head->next->ptr = node;
    strcpy(head->next->ptr->data, input); // Copies to Graph_All Payload: data
  }
  else { // Adds to the end of the list
    while (curr->next != NULL){ curr = curr->next; } // Finds Last Item
    curr->next = (List*)malloc(sizeof(List)); curr = curr->next; curr->next = NULL;
    Graph *node = (Graph*)malloc(sizeof(Graph)); Graph_SetUp(node); curr->ptr = node;
    strcpy(curr->ptr->data, input); // Copies to Graph_All Payload: data
  } return;
}

void GraphPopulate(char start[], char stop[], int cost, List *head){ //                 Works :)
  // Populates the Graph with costs and arcs

  List *curr = head->next, *startPtr = NULL, *stopPtr = NULL;

  // Find Start Point ---\/
  while (curr != NULL){ if (strcmp(curr->ptr->data, start) == 0){ startPtr = curr; break; } curr = curr->next; }
// ----------------------^

  // Find End Point ---\/
  curr = head->next;
  while (curr != NULL){ if (strcmp(curr->ptr->data, stop) == 0){ stopPtr = curr; break; } curr = curr->next; }
// --------------------^

  // Finds Open Arc Point in Graph_All Structure if possible and adds -
  // startPtr->ptr->cost and startPtr->ptr->arcs[index] pointer ------------\/
  int i, openIndex = -1;
  for (i = 0; i < 10; i++){ if (startPtr->ptr->arcs[i] == NULL){ openIndex = i; break; } }
  if (openIndex == -1){ printf("--- No Open Arcs for %s!!\n", startPtr->ptr->data); return; }
  else if ( (startPtr != NULL) && (stopPtr != NULL) ) {
    // If there is an Arc Open set arc else do nothing
    startPtr->ptr->arcs[openIndex] = stopPtr->ptr; startPtr->ptr->cost[openIndex] = cost;
    //printf("--- Arc Destination Set: %s, Cost: %d, Index: %d\n", startPtr->ptr->arcs[openIndex]->data, startPtr->ptr->cost[openIndex], openIndex);
  }
  else { printf("--- Start or Stop Destination Doesn't Exist! Unable to Set Arc.\n"); return; }
// -------------------------------------------------------------------------^
  return;
}

int GenerateRandom(int lower, int upper, int count){ //                                 Good Enough :)
  int i;
  for (i = 0; i < count; i++){
    int rand_num = (rand() % (upper - lower + 1)) + 1;
    return rand_num;
  }
}

void JourneyToHome(char start[], List *head){ //                                        Works :)
  // Exactly as the name Suggests

  List *curr = head->next, *startPtr = NULL; Graph *gcurr = NULL;
  while (curr != NULL){ if (strcmp(curr->ptr->data, start) == 0){ startPtr = curr; break; } curr = curr->next; }
  if (startPtr == NULL){ printf("\n--- Journey Start Point Doesn't Exist! Unable to Start.\n"); return; }
  else {
    gcurr = startPtr->ptr; int randomIndex, totalCost = 0;
    printf("--- Starting Node: %s\n", gcurr->data);
    while (strcmp(gcurr->data, "Home") != 0){
      randomIndex = (GenerateRandom(0, 10, 1) % 10);
      if (gcurr->arcs[randomIndex] != NULL){ totalCost += gcurr->cost[randomIndex]; gcurr = gcurr->arcs[randomIndex]; }
    } printf("--- Ending Node: %s\n", gcurr->data); printf("--- Total Cost: %d\n", totalCost);
  }
}

void FreeAll(List *head){ //                                                            Works :)
  // Frees All Pointers using the Linked List for ease :)

  List *curr = head->next, *temp; int i; printf("\n--- Freeing All...\n");
  while (curr != NULL){
    temp = curr; curr = curr->next;
    for (i = 0; i < 10; i++){ temp->ptr->arcs[i] = NULL; } // Sets All Arcs to NULL before freeing *ptr
    free(temp->ptr); temp->ptr = NULL; temp->next = NULL; free(temp); temp = NULL;
  } free(head); head = NULL; printf("All Freed\n\n"); return;
}

int main(void){
  FILE *fp; fp = fopen("hw10.data", "r"); char Set1[101], Set2[101]; int cost;
  if (fp == NULL){ printf("\nError: File Couldn't be Opened!!\n"); exit(1); }
  List *head; head = (List*)malloc(sizeof(List)); head->next = NULL; head->ptr = NULL;
  while (1){ // First Part of File Reading <------------------------------------------------------------
    fscanf(fp, "%s", Set1);
    if (strcmp(Set1, "STOP") == 0){ printf("\n--- Step 1 Complete!\n"); break; } AddList(head, Set1);
  }
  while (1){ // Second Part of File Reading <-----------------------------------------------------------
    fscanf(fp, "%s %s %d", Set1, Set2, &cost);
    if ( (strcmp(Set1, "STOP") == 0) && (strcmp(Set2, "STOP") == 0) ){ printf("\n--- Step 2 Complete!\n\n"); break; }
    GraphPopulate(Set1, Set2, cost, head);
  }
  fscanf(fp, "%s", Set1); JourneyToHome(Set1, head);
/*
  printf("\n------ Generate Random Test -----\n"); int num[] = {0,0,0,0,0,0,0,0,0,0}, i, index;
  for (i = 0; i < 100; i++){
    num[GenerateRandom(0, 10, 1) % 10] += 1;
  }
  for (i = 0; i < 10; i++){ printf("Index: %d, List: %d\n", i, num[i]); }
*/
  fclose(fp); FreeAll(head); return 0;
}
