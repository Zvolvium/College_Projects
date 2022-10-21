// Mason Motschke - CSCI 230
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array { char data; } chars;

struct array *RedoArray(chars *array, int size, int increment){ // Reallocates chars *array to be bigger
  chars *temp = (chars*)malloc(size * sizeof(chars)); memcpy(temp, array, (size - increment));
  free(array); return temp;
}

int FindSpace(chars *array, int size){ // Finds free space in array
  int i; for (i = 0; i < size; i++){ if (array[i].data == 0){ return i; } } return -1;
}

int main(void){
  char a, b; int size = 5, freeSpace; chars *array; array = (chars*)malloc(size * sizeof(chars));
  while (1){
    printf("\nEnter character('~' to quit): "); a = getchar(); b = a;
    while(a != EOF && a != '\n'){ a = getchar(); }
    printf(" - Character Entered: %c\n", b); freeSpace = FindSpace(array, size);
    if (freeSpace == -1){
      size += 5; array = RedoArray(array, size, 5); freeSpace = FindSpace(array, size);
    }
    if (b != '~') array[freeSpace].data = b;
    if (b == '~'){ // Append '\0' Null Char to end of array to make string
      freeSpace = FindSpace(array, size);
      if (freeSpace == -1){ size++; array = RedoArray(array, size, 1); freeSpace = FindSpace(array, size); }
      array[freeSpace].data = '\n'; freeSpace = FindSpace(array, size);
      if (freeSpace == -1){ size++; array = RedoArray(array, size, 1); freeSpace = FindSpace(array, size); }
      array[freeSpace].data = '\0'; printf("\n");
      char string[] = "HW4 Input: "; char *finalString;
      finalString = calloc(strlen(string) + strlen(array), sizeof(char));
      strcat(finalString, string); strcat(finalString, array); printf("%s\n", finalString);
      free(array); free(finalString); return 1;
    }
  }
}
