// Mason Motschke - CSCI_451 - program0
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

#define KEY1 2001
#define KEY2 2002

int main (void){
  
  // Create Semephores
  sem_t *sem1; sem_t *sem2;
  sem1 = sem_open("sem1", O_CREAT, 0666, 0);
  sem2 = sem_open("sem2", O_CREAT, 0666, 0);

  // Create Pipe between prog1 and prog2
  int pipe1[2]; pipe(pipe1);
  printf("Pipe r: %d; Pipe w: %d\n", pipe1[0], pipe1[1]);

  // Pipe between prog2 and prog3
  int pipe2[2]; pipe(pipe2);
  printf("Pipe r: %d; Pipe w: %d\n", pipe2[0], pipe2[1]);
  //close(pipe1[0]); close(pipe1[1]); close(pipe2[0]); close(pipe2[1]);

  // Fork Program1 and Program 2
  // Need to fork() then exec()

  char write1[10], read1[10], write2[10], read2[10];
  sprintf(write1, "%d", pipe1[1]); sprintf(read1, "%d", pipe1[0]);
  sprintf(write2, "%d", pipe2[1]); sprintf(read2, "%d", pipe2[0]);
  char* arg1[] = {"./program1", write1, "sem1",  NULL}; char* arg2[] = {"./program2", read1, write2, "sem1", "sem2", NULL};
  char* arg3[] = {"./program3", "sem2", read2, NULL};

  pid_t pid[3]; int wstatus;
  if ((pid[0] = fork()) == 0){
    // Child
    execvp("./program1", arg1);
  }
  else if ((pid[1] = fork()) == 0){
    // Child
    execvp("./program2", arg2);
  } else if ((pid[2] = fork()) == 0){
    // Child
    execvp("./program3", arg3);
  }

  // Wait for Children
  wait(&wstatus); wait(&wstatus);

  // Destroy Semaphore
  sem_unlink("sem1");
  sem_unlink("sem2");

  return 0;
}