#include <stdlib.h>
#include <stdio.h>

typedef struct files { FILE *fp; }f;

int main (void){
  // Files to rewrite / overwrite
  f files[5];
  files[0].fp = fopen("drive1.data", "w"); files[1].fp = fopen("drive2.data", "w");
  files[2].fp = fopen("drive3.data", "w"); files[3].fp = fopen("drive4.data", "w");
  files[4].fp = fopen("drive5.data", "w");

  // File Size's
  int fileSizes[5], crit = 0, random = 0;
  fileSizes[0] = 10; fileSizes[1] = 10; fileSizes[2] = 10;
  fileSizes[3] = 10; fileSizes[4] = 10;

  srand(atoi("Lets Play Ball")); char c; int chr, ran, cnt = 0;
  for (int i = 0; i < 5; i++){
    FILE *fp = files[i].fp; cnt = 0;
    while (cnt != fileSizes[i]){
      ran = rand(); if (ran < 0){ ran *= -1; } chr = ran % 127;
      if (chr > 32){ fprintf(fp, "%c", chr); cnt++; }
    }
  }
  for (int i = 0; i < 5; i++){ fclose(files[i].fp); files[i].fp = NULL; } return 0;
}
