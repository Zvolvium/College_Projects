// Mason Motschke - CSCI_451 - HW6
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Global Variables
int flag = 0, writeF = 0; pthread_mutex_t mutex; char threadChar;
typedef struct threadData { FILE *fp; int threadNum; } tData;

// Thread Functions
void *thread1 (void *arg){
  // Detatch Thread
  pthread_detach(pthread_self());

  // Interpret arg
  tData data = *(tData*)arg;

  // Thread Purpose - Load threadChar with char from file
  while (1){
    if (feof(data.fp)){ break; }
    // Critical Section
    pthread_mutex_lock(&mutex);
    fscanf(data.fp, "%c", &threadChar);
    if (threadChar != '\n'){ writeF = 1; } usleep(100);
    pthread_mutex_unlock(&mutex); usleep(100);
  }

  flag++;
  printf("-- Thread %d died!!\n", data.threadNum); pthread_exit(1);
}

void *thread2 (void *arg){
  // Detatch Thread
  pthread_detach(pthread_self());

  // Interpret arg
  tData data = *(tData*)arg;

  // Thread Purpose - Load threadChar with char from file
  while (1){
    if (feof(data.fp)){ break; }
    // Critical Section
    pthread_mutex_lock(&mutex);
    fscanf(data.fp, "%c", &threadChar);
    if (threadChar != '\n'){ writeF = 1; } usleep(100);
    pthread_mutex_unlock(&mutex); usleep(100);
  }

  flag++;
  printf("-- Thread %d died!!\n", data.threadNum); pthread_exit(1);
}

void *thread3 (void *arg){
  // Detatch Thread
  pthread_detach(pthread_self());

  // Interpret arg
  tData data = *(tData*)arg;

  // Thread Purpose - Load threadChar with char from file
  while (1){
    if (feof(data.fp)){ break; }
    // Critical Section
    pthread_mutex_lock(&mutex);
    fscanf(data.fp, "%c", &threadChar);
    if (threadChar != '\n'){ writeF = 1; } usleep(100);
    pthread_mutex_unlock(&mutex); usleep(100);
  }

  flag++;
  printf("-- Thread %d died!!\n", data.threadNum); pthread_exit(1);
}

void *thread4 (void *arg){
  // Detatch Thread
  pthread_detach(pthread_self());

  // Interpret arg
  tData data = *(tData*)arg;

  // Thread Purpose - Load threadChar with char from file
  while (1){
    if (feof(data.fp)){ break; }
    // Critical Section
    pthread_mutex_lock(&mutex);
    fscanf(data.fp, "%c", &threadChar);
    if (threadChar != '\n'){ writeF = 1; } usleep(100);
    pthread_mutex_unlock(&mutex); usleep(100);
  }

  flag++;
  printf("-- Thread %d died!!\n", data.threadNum); pthread_exit(1);
}

void *thread5 (void *arg){
  // Detatch Thread
  pthread_detach(pthread_self());

  // Interpret arg
  tData data = *(tData*)arg;

  // Thread Purpose - Load threadChar with char from file
  while (1){
    if (feof(data.fp)){ break; }
    // Critical Section
    pthread_mutex_lock(&mutex);
    fscanf(data.fp, "%c", &threadChar);
    if (threadChar != '\n'){ writeF = 1; } usleep(100);
    pthread_mutex_unlock(&mutex); usleep(100);
  }

  flag++;
  printf("-- Thread %d died!!\n", data.threadNum); pthread_exit(1);
}


int main (void){
  printf("\n--- Program Started...\n");
  // Check for all available data files
  tData data[5];
  data[0].fp = fopen("drive1.data", "r"); data[1].fp = fopen("drive2.data", "r");
  data[2].fp = fopen("drive3.data", "r"); data[3].fp = fopen("drive4.data", "r");
  data[4].fp = fopen("drive5.data", "r");
  for (int i = 0; i < 5; i++){
    if (data[i].fp == NULL){ flag++; printf("\n--- Error: File: data%d.in NOT FOUND!!", i + 1); }
  } printf("\n");
  if (flag > 0){ // If Files are Missing Free Opened Files and End Parent Program
    for (int i = 0; i < 5; i++){ if (data[i].fp != NULL){ fclose(data[i].fp); data[i].fp = NULL; } }
    printf("\n"); return 1;
  } flag = 0;

  // Thread Creation
  pthread_t threads[5];
  data[0].threadNum = 1; pthread_create(&threads[0], NULL, thread1, &data[0]);
  data[1].threadNum = 2; pthread_create(&threads[1], NULL, thread2, &data[1]);
  data[2].threadNum = 3; pthread_create(&threads[2], NULL, thread3, &data[2]);
  data[3].threadNum = 4; pthread_create(&threads[3], NULL, thread4, &data[3]);
  data[4].threadNum = 5; pthread_create(&threads[4], NULL, thread5, &data[4]);

  // Main Waits for all threads to terminate
  char array[1000000]; int index = 0;
  while (flag != 5){
    if (writeF == 1){
      // Recieve Char from threads and print to terminal
      array[index] = threadChar; writeF = 0; index++; threadChar = 0;
    }
  } array[index] = '\0'; printf("\n-- Result: %s\n\n", array);

  // Close Files
  for (int i = 0; i < 5; i++){ fclose(data[i].fp); data[i].fp = NULL; }
  printf("--- Program Finished...\n\n"); return 0;
}
