// Mason Motschke - CSCI_451 - program1
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main (int argc, char* argv[]){

  char *a = argv[1]; int pipeIn = atoi(a); //printf("Prog1 IN: %s %d\n", a, pipeIn);

  char *name = argv[2];
  sem_t *sem; sem_close(sem);
  sem = sem_open(name, O_CREAT, 0666, 0);

  FILE *fp; fp = fopen("input.data", "r");
  if (fp == NULL){ printf("\n - Error: Failed to Read File\n"); return -1; }
  char *temp;

  while (1){
    sleep(10);
    sem_wait(sem);
    fscanf(fp, "%s", temp);
    write(pipeIn, temp, 100);
    sem_post(sem);
    if (feof(fp)){ break; }
  } fclose(fp); close(pipeIn);

  sem_close(sem); exit(0);
}