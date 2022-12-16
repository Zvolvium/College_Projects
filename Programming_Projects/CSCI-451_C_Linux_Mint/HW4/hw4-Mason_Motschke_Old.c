// Mason Motschke - CSCI_351 - HW4
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Global's
int flag = 0, balance = 0; pthread_mutex_t mutex;
typedef struct threadData { FILE *fp; int threadNum; } tData;

void *Add (void *arg){
  // Detach Thread
  pthread_detach(pthread_self());

  // Interpret arg
  tData data = *(tData*)arg;

  // File Setup
  FILE *fp = data.fp;

  // File Reading
  char *line; size_t len = 0; ssize_t nread; int sum = 0;
  while ((nread = getline(&line, &len, fp)) != -1){
    if (line[0] == 'R'){ // Start Critical Section
      // Start Mutex
      pthread_mutex_lock(&mutex);

      // Reset adder
      sum = 0;
    }
    else if (line[0] == 'W'){ // End Critical Section
      balance += sum;
      printf("- Account balance after thread %d is $%d\n", data.threadNum, balance);
      // End Mutex
      pthread_mutex_unlock(&mutex);

      // Sleep to allow another thread to grab mutex
      usleep(1000);
    }
    else { sum += atoi(line); } // Add from files
  }

  flag++; fp = NULL; printf("-- Thread %d died!!\n", data.threadNum); pthread_exit(1);
}

int main (void){
  printf("\n--- Program Started...\n");
  // Check for all available data files
  tData data[5];
  data[0].fp = fopen("data1.in", "r"); data[1].fp = fopen("data2.in", "r");
  data[2].fp = fopen("data3.in", "r"); data[3].fp = fopen("data4.in", "r"); data[4].fp = fopen("data5.in", "r");
  for (int i = 0; i < 5; i++){
    if (data[i].fp == NULL){ flag++; printf("\n--- File: data%d.in NOT FOUND!!", i + 1); }
  } printf("\n\n");
  if (flag > 0){ return 1; } flag = 0;

  // Thread Creation
  pthread_t threads[5];
  for (int i = 0; i < 5; i++){ data[i].threadNum = i + 1; pthread_create(&threads[i], NULL, Add, &data[i]); }

  // Main Waits for all threads to terminate
  while (flag != 5){ /* Do Nothing */ }

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

  // Close Files
  for (int i = 0; i < 5; i++){ fclose(data[i].fp); data[i].fp = NULL; }
  printf("\n--- Program Finished...\n\n"); return 0;
}
