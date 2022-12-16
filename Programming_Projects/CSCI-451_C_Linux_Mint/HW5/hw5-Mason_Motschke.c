// Mason Motschke - CSCI_351 - HW5
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Global's
int flag = 0, balance = 0, lock = 0; pthread_mutex_t mutex, getPG;
typedef struct threadData { FILE *fp; int threadNum; } tData;
typedef struct node { int owner, refBit, modBit, Class; struct node *next; } node;
typedef struct page { struct node *pg; } pages;
node *head = NULL;

void os (int check){
  // Go through LL
  node *curr = head->next;
  if (check == 0){ // Assign Classes
    for (int i = 0; i < 6; i++){
      if (curr->refBit == 0 && curr->modBit == 0){ curr->Class = 0; }
      else if (curr->refBit == 0 && curr->modBit == 1){ curr->Class = 1; }
      else if (curr->refBit == 1 && curr->modBit == 0){ curr->Class = 2; }
      else if (curr->refBit == 1 && curr->modBit == 1){ curr->Class = 3; }
      curr = curr->next;
    }
  } else {
    // Reset R Bits
    for (int i = 0; i < 6; i++){
      curr->refBit = 0; curr = curr->next;
    }
  }
}

void *Add (void *arg){
  // Detach Thread
  pthread_detach(pthread_self());

  // Interpret arg
  tData data = *(tData*)arg;

  // File Setup
  FILE *fp = data.fp;

  // Page Setup - Grab Initial Page
  node *curr = head->next; pages page[2]; int pg = 0; pthread_mutex_lock(&getPG);
  for (int i = 0; i < 10; i++){
    if (curr->owner == 0){
      page[pg % 2].pg = curr; page[pg % 2].pg->owner = data.threadNum; break;
    } else { curr = curr->next; }
  } pthread_mutex_unlock(&getPG); lock++;
  while (lock != 5){ /* Do Nothing */ } // Wait for all threads to grab page

  // File Reading
  char *line; size_t len = 0; ssize_t nread; int sum = 0, num;
  node* small = NULL; curr = head->next;
  while ((nread = getline(&line, &len, fp)) != -1){

    // Check pgs
    if (line[0] == 'R'){ // Start Critical Section
      // Start Mutex
      pthread_mutex_lock(&mutex);
      if ((num = rand()) % 5 == 3){

        // Generate Page Fault
        printf("-- Page Fault in thread %d\n", data.threadNum);

        // Calc Classes
        os(0);

        // Find Lowest class
        small = head->next;
        for (int i = 0; i > 6; i++){ if (curr->Class < small->Class){ small = curr; } }
        printf("--- Details\n--- R Bit: %d, M Bit: %d\n", small->refBit, small->modBit);
        printf("--- Owner: %d\n", small->owner);

        // Initialize
        pg++;
        page[pg % 2].pg = small;
        page[pg % 2].pg->refBit = page[pg % 2].pg->modBit = 0;
        page[pg % 2].pg->owner = data.threadNum;
      }

      // Reset adder
      sum = 0;
    }
    else if (line[0] == 'W'){ // End Critical Section
      if ((page[pg % 2].pg == NULL) && (page[(pg + 1) % 2].pg == NULL)){
        // Generate Page Fault
        printf("-- Page Fault in thread %d\n", data.threadNum);

        // Calc Classes
        os(0);

        // Find Lowest Class
        small = head->next;
        for (int i = 0; i > 6; i++){ if (curr->Class < small->Class){ small = curr; } }
        printf("--- Details\n--- R Bit: %d, M Bit: %d\n", small->refBit, small->modBit);
        printf("--- Owner: %d\n", small->owner);

        // Initialize
        page[pg % 2].pg = small;
        page[pg % 2].pg->refBit = page[pg % 2].pg->modBit = 0;
        page[pg % 2].pg->owner = data.threadNum;

      } else if (page[pg % 2].pg == NULL){ pg++; }
      if (sum < 0){ page[pg % 2].pg->refBit = page[pg % 2].pg->modBit = 1; }
      else { page[pg % 2].pg->refBit = 1; }

      balance += sum;
      printf("- Account balance after thread %d is $%d\n", data.threadNum, balance);
      // End Mutex
      pthread_mutex_unlock(&mutex);

      // Sleep to allow another thread to grab mutex
      usleep(250);
    }
    else { sum += atoi(line); } // Add from files
  } page[0].pg = page[1].pg = NULL; curr = NULL;

  printf("-- Thread %d died!!\n", data.threadNum); fp = NULL; flag++; pthread_exit(1);
}

int main (void){
  printf("\n--- Program Started...\n");
  // Check for all available data files
  tData data[5];
  data[0].fp = fopen("data1.in", "r"); data[1].fp = fopen("data2.in", "r");
  data[2].fp = fopen("data3.in", "r"); data[3].fp = fopen("data4.in", "r"); data[4].fp = fopen("data5.in", "r");
  for (int i = 0; i < 5; i++){
    if (data[i].fp == NULL){ flag++; printf("\n--- File: data%d.in NOT FOUND!!", i + 1); }
  } printf("\n");
  if (flag > 0){ // If Files are Missing Free Opened Files and End Parent Program
    for (int i = 0; i < 5; i++){ if (data[i].fp != NULL){ fclose(data[i].fp); data[i].fp = NULL; } }
    printf("\n"); return 1;
  } flag = 0;

  // Page Setup
  head = (node*)malloc(sizeof(node)); node *curr = head;
  for (int i = 0; i < 6; i++){
    curr->next = (node*)malloc(sizeof(node)); curr = curr->next;
    curr->owner = curr->refBit = curr->modBit = 0; curr->next = NULL;
    if (i == 5){ curr->next = head->next; } // Last Node in LL to First for Circular
  }

  // Thread Creation
  pthread_t threads[5]; srand(55);
  for (int i = 0; i < 5; i++){ data[i].threadNum = i + 1; pthread_create(&threads[i], NULL, Add, &data[i]); }

  // Main Waits for all threads to terminate
  while (flag != 5){ if (rand() % 50 == 4){ os(1); usleep(2500); } }

  // Answer Checking
  for (int i = 0; i < 5; i++){ rewind(data[i].fp); } // Rewind Files to beginning
  int sum = 0; char *line; size_t len = 0; ssize_t nread;
  for (int i = 0; i < 5; i++){
    FILE *fp = data[i].fp;
    while ((nread = getline(&line, &len, fp)) != -1){
      //printf("Line Read: %s\n", line);
      if (line[0] == 'R' || line[0] == 'W'){ /* Do Nothing */ }
      else { sum += atoi(line); }
    }
  } printf("\n-- Final Balance: %d\n", balance); printf("-- Sum Check: %d\n", sum);

  // Free Linked List
  curr = head->next;
  for (int i = 0; i < 6; i++){ if (i == 5){ curr->next = NULL; break; } else { curr = curr->next; } }
  for (int i = 0; i < 6; i++){
    curr = head;
    while (curr->next->next != NULL){ curr = curr->next; }
    free(curr->next); curr->next = NULL;
  } if (head->next == NULL){ printf("\n-- Freed Linked List\n"); free(head); head = curr = NULL; }

  // Close Files
  for (int i = 0; i < 5; i++){ fclose(data[i].fp); data[i].fp = NULL; }
  printf("\n--- Program Finished...\n\n"); return 0;
}
