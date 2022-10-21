// Mason Motschke - CSCI_451 - HW3
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

FILE *fpOut; pthread_mutex_t read, write; int global, flag = 0;

void *Read (void *arg){
  // Read data in and store in global var
  pthread_mutex_lock(&write); FILE *in; in = fopen("hw3.in", "r");
  if (in == NULL){ printf("\n--- Error: Failed to open file: 'hw3.in'!!"); pthread_exit(-1); }

  while (1){
    if (feof(in)){ flag = 1; break; }
    // Mutex Lock
    pthread_mutex_lock(&read);
    fscanf(in, "%d", &global); //printf("Read %d\n", global);
    // Mutex Unlock
    pthread_mutex_unlock(&read); pthread_mutex_unlock(&write);
    pthread_mutex_lock(&read);
  } fclose(in); pthread_exit(1);
}

void *Write (void *arg){
  // Write out to file | hw3.out
  while (1){
    if (flag == 1){ break; }
    // Mutex Lock
    pthread_mutex_lock(&write);
    if (global % 2 == 0){ for (int i = 0; i < 2; i++){ fprintf(fpOut, "%d\n", global); } } // IF EVEN print * 2
    else { fprintf(fpOut, "%d\n", global); } // IF ODD print //printf("Checked %d\n", global);
    // Mutex Unlock
    pthread_mutex_unlock(&write); pthread_mutex_unlock(&read);
    pthread_mutex_lock(&write);
  } pthread_exit(1);
}

int main (void){
  fpOut = fopen("hw3.out", "w"); printf("\n--- Program Started...\n");

  pthread_t thread[2];
  pthread_create(&thread[0], NULL, Read, NULL); pthread_create(&thread[1], NULL, Write, NULL);

  for (int z = 0; z < 2; z++){ pthread_join(thread[z], NULL); }
  fclose(fpOut); printf(" - Program Finished\n\n"); return 1;
}
