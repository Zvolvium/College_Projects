//Mason Motschke - CSCI 230

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char cmd[100];
  strcpy(cmd, "cat american0.txt american1.txt american2.txt | sort > words.txt");
  system(cmd);
}
