// Mason Motschke - CSCI_451 - HW2
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

typedef struct fileData { char *string; } arr;
typedef struct threadData { int threadNum, fSize; char word[100]; arr *fData; } tdata;

int ScanFile (void){
  FILE *fp; fp = fopen("hw3-data.txt", "r");
  if (fp == NULL){ printf("\n - Error: Failed to Read File\n"); return -1; }
  int num = 0; char temp[1000000];
  while (1){
    fscanf(fp, "%s", temp);
    if (feof(fp)){ break; } num++;
  } fclose(fp); return num;
}

void ReadFile (arr data[], int size){
  FILE *fp; fp = fopen("hw3-data.txt", "r");
  if (fp == NULL){ printf("\n - Error: Failed to Read File\n"); return; }
  printf("\n--- Reading File...\n");

  char temp[1000000]; int len = 0;
  for (int i = 0; i < size; i++){
    fscanf(fp, "%s", temp); len = strlen(temp);

    // Convert to lowercase
    for (int j = 0; j < len; j++){ temp[j] = tolower(temp[j]); }

    // Store in word array
    data[i].string = (char*)malloc(sizeof(++len)); strcpy(data[i].string, temp);
  } fclose(fp); printf(" - File Read\n\n"); return;
}

void FreeAll (arr data[], int size){
  printf("\n--- Freeing Memory...\n");
  for (int i = 0; i < size; i++){ free(data[i].string); data[i].string = NULL; }
  printf(" - Memory Freed\n\n"); return;
}

void *ThreadFunc (void *arg){
  tdata data = *(tdata*)arg; int wordCnt = 0;
  printf("\nHi, My name is thread%d.\nMy Word to search for is %s\n", data.threadNum, data.word);
  //printf("ThreadData[2] = %s\n", data.fData[2].string);         # Test for data Transfer

  // Search for Word
  for (int i = 0; i < data.fSize; i++){
    if (strcmp(data.fData[i].string, data.word) == 0){ wordCnt++; } // 0 is equal
  } printf("\n - pthread: Occurances of the word %s: %d\n", data.word, wordCnt);

  // Exit thread
  pthread_exit(1);
}

int main (void){
  // Download File
  printf("\n--- Downloading File...\n");
  system("wget -q http://undcemcs01.und.edu/~ronald.marsh/CLASS/CS451/hw3-data.txt");
  printf(" - File Downloaded\n");

  // Load File & Parse into dynamic char arr
  int dataNum = ScanFile(); if (dataNum == -1){ return 0; }
  arr Data[dataNum]; ReadFile(Data, dataNum);//for (int i = 0; i < dataNum; i++){ printf("Words: %s\n", Data[i].string); }

  // Spawn Threads to find words | "easy" and "polar"
  tdata threadData[2]; //                                             # Data Loading
  threadData[0].threadNum = 1; strcpy(threadData[0].word, "easy");
  threadData[1].threadNum = 2; strcpy(threadData[1].word, "polar");
  threadData[0].fSize = threadData[1].fSize = dataNum;
  threadData[0].fData = threadData[1].fData = Data;

  pthread_t thread1, thread2;
  pthread_create(&thread1, NULL, ThreadFunc, &threadData[0]);
  pthread_create(&thread2, NULL, ThreadFunc, &threadData[1]);

  pthread_join(thread1, NULL); pthread_join(thread2, NULL);
  threadData[0].fData = threadData[1].fData = NULL;
/*                                                  # Check original array in main against pthread search
  int easyCnt = 0, polarCnt = 0;
  for (int i = 0; i < dataNum; i++){
    if (strcmp("easy", Data[i].string) == 0){ easyCnt++; }
    if (strcmp("polar", Data[i].string) == 0){ polarCnt++; }
  } printf("\n# of polar: %d\n# of easy: %d\n", polarCnt, easyCnt);*/
  FreeAll(Data, dataNum); return 1;
}
