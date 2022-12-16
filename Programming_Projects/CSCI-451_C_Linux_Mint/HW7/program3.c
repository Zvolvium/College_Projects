// Mason Motschke - CSCI_451 - program3
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main (int argc, char *argv[]){

  char *a = argv[2]; int pipeOut = atoi(a); //printf("Prog1 Out: %s %d\n", a, pipeOut);

  char *name1 = argv[1];
  sem_t *sem; sem_close(sem);
  sem = sem_open(name1, O_CREAT, 0666, 0);
  sem_wait(sem);

  FILE *in1, *in2, *out;
  in1 = fopen("shared1.dat", "r"); in2 = fopen("shared2.dat", "r");
  out = fopen("output.data", "w");
  int type1, type2;
  fscanf(in1, "%d", &type1); fscanf(in2, "%d", &type2);
  printf("Type1 : %d\nType2 : %d\n", type1, type2);
  fclose(in1); fclose(in2);

  while (1){
    sleep(10);
    sem_wait(sem); char buff[100];
    if (read(pipeOut, buff, 100) == 0){ break; }

    // Reverse
    int len = strlen(buff); char newWord[1];
    if (buff[len-3] == 'r' && buff[len-2] == 'a' && buff[len-1] == 'y' && (buff[len-4] == 'a' || buff[len-4] == 'e' || buff[len-4] == 'i' || buff[len-4] == 'o' || buff[len-4] == 'u' || buff[len-4] == 'y' || buff[len-4] == 'A' || buff[len-4] == 'E' || buff[len-4] == 'I' || buff[len-4] == 'O' || buff[len-4] == 'U' || buff[len-4] == 'Y')){
      char newWord[len-3];
      for (int i = 0; i < len-3; i++){ newWord[i] = buff[i]; }
    }
    else {
      char newWord[len-3]; newWord[0] = buff[len-4];
      for (int i = 0; i < len-4; i++){ newWord[i] = buff[i]; }
    }
    fprintf(out, "%s", newWord);
  } close(pipeOut);

  fclose(out); exit(0);

}