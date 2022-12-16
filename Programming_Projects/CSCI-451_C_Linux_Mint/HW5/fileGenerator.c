// To generate test files for HW4.c
#include <stdlib.h>
#include <stdio.h>

typedef struct files { FILE *fp; } f;

int main (void){
  // Open Files for Overwrite
  f files[5];
  files[0].fp = fopen("data1.in", "w"); files[1].fp = fopen("data2.in", "w");
  files[2].fp = fopen("data3.in", "w"); files[3].fp = fopen("data4.in", "w");
  files[4].fp = fopen("data5.in", "w");

  // File Size's
  int fileSizes[5], crit = 0, random = 0;;
  fileSizes[0] = 600; fileSizes[1] = 600; fileSizes[2] = 600;
  fileSizes[3] = 600; fileSizes[4] = 600;

  srand(atoi("Wally Wackos Wild World"));
  for (int i = 0; i < 5; i++){
    FILE *fp = files[i].fp;
    for (int j = 0; j < fileSizes[i]; j++){
      if (crit == 0){ crit++; fprintf(fp, "%s\n", "R"); }
      else if (crit == 9){ crit = 0; fprintf(fp, "%s\n", "W"); }
      else {
        crit++; random = rand();
        if (random > 0){ fprintf(fp, "+%d\n", random); }
        else { fprintf(fp, "%d\n", random); }
      }
    }
  } for (int i = 0; i < 5; i++){ fclose(files[i].fp); files[i].fp = NULL; } return 0;
}
