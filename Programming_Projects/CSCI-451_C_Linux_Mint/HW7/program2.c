// Mason Motschke - CSCI_451 - program2
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[]){

  char *a = argv[1]; int pipeOut = atoi(a); //printf("Prog1 Out: %s %d\n", a, pipeOut);

  char *b = argv[2]; int pipeIn = atoi(b); //printf("Prog2 IN: %s %d\n", b, pipeIn);

  char *name1 = argv[3], *name2 = argv[4];
  sem_t *sem1, *sem2; sem_close(sem1); sem_close(sem2);
  sem1 = sem_open(name1, O_CREAT, 0666, 0);
  sem2 = sem_open(name2, O_CREAT, 0666, 0);

  char *buff; int type1 = 0, type2 = 0;

  while (1){
    sleep(10);
    sem_wait(sem1);
    if (read(pipeOut, buff, 100) == 0){ break; }

    if (buff[0] == 'a' || buff[0] == 'e' || buff[0] == 'i' || buff[0] == 'o' || buff[0] == 'u' || buff[0] == 'y' || buff[0] == 'A' || buff[0] == 'E' || buff[0] == 'I' || buff[0] == 'O' || buff[0] == 'U' || buff[0] == 'Y'){
      // If first is vowel add 'ray' to the end
      int len = strlen(buff); char punc = '_';
      for (int i = 0; i < len; i++){ if (buff[i] == '.' || buff[i] == ','){ punc = buff[i]; break; } else { punc = '_'; } }
      char newWord[len+5];
      for (int i = 0; i < len; i++){ newWord[i] = buff[i]; }
      newWord[len] = 'r'; newWord[len+1] = 'a'; newWord[len+2] = 'y';
      if (punc != '_'){ newWord[len+3] = punc; } type1++;
    }
    else {
      int len = strlen(buff);
      char newWord[len+5], punc;
      for (int i = 1; i < len; i++){ newWord[i-1] = buff[i]; }
      newWord[len-1] = buff[0]; newWord[len] = 'a'; newWord[len+1] = 'y';
      for (int i = 0; i < len; i++){ if (buff[i] == '.' || buff[i] == ','){ punc = buff[i]; break; } else { punc = '_'; } }
      if (punc != '_'){ newWord[len+2] = punc; } type2++;
    }

    sem_post(sem1);
  } close(pipeOut);

  FILE *out1, *out2; out1 = fopen("shared1.dat", "w"); out2 = fopen("shared2.dat", "w");
  fprintf(out1, "%d", type1); fprintf(out2, "%d", type2);
  fclose(out1); fclose(out2);

  close(pipeIn); sem_close(sem1); sem_close(sem2); exit(0);
}