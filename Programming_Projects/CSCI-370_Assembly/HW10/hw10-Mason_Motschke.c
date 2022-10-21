// Mason Motschke - CSCI_370 - HW10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cache { int Tag; int Index; int Value; } CACHE;
typedef struct cache2 { int Tag; int Index; int Value[16]; } CACHEW;
typedef struct dircache { struct cache Cache; } DIRECT;
typedef struct twoWay { struct cache2 Cache[2]; } TWO;
typedef struct fourWay { struct cache2 Cache[4]; } FOUR;

int decimalToBinary(int decimal, int array[]){
  int index = 1, remainder; array[0] = -1;
  if (decimal == 0){ array[1] = 0; return index; }
  while (decimal != 0){
    remainder = decimal % 2; array[index] = remainder;
    index++; decimal = decimal / 2;
  } return index;
}

void getMemLocations(int array[]){ // Updates original Array
  int memoryLocation;
  for (int i = 0; i < 500; i++){
    memoryLocation = (rand() % 65536);
    array[i] = memoryLocation;
  }
}

int main(void){
  // Initialize Vars
  int binary[100], decimal = 0, Miss = 0, memLocal[500], memoryLocation; srand(2001);
  for (int i = 0; i < 100; i++){ binary[i] = 0; } // Initialize binary array

  // --------------------------- Begin Program -----------------------------------------
  printf("\n -- Starting Fully Associative CACHE -- \n");

  // Creates 500 random memory locations using personal seed
  getMemLocations(memLocal);
  //for (int i = 0; i < 500; i++){ printf("Memory Location: %d\n", memLocal[i]); }

  // Convert memLocations to binary
  for (int i = 0; i < 500; i++){
    int index = decimalToBinary(memLocal[i], binary); //printf("Mem: %5d; Binary: ", memLocal[i]);
    for (int j = index; binary[j] != -1; j--){ /*printf("%d", binary[j]);*/ } //printf("\n");
    for (int j = 0; j < 100; j++){ binary[j] = 0; }
  }

  int FullAss[128][32] = {-1}; // Creates simulated cache of 128 lines w/ 32 words each
  int value = 0, breakFlag = 0;
  for (int i = 0; i < 500; i++){
    value = memLocal[i] % 69; breakFlag = 0;
    // Search FullAssoc
    for (int j = 0; j < 128; j++){
      for (int x = 0; x < 32; x++){
        if (value == FullAss[j][x]){ breakFlag = 1; break; }
      }
      if (breakFlag == 1){ break; }
    }
    if (breakFlag == 0){
      Miss++;
      for (int y = 0; y < 128; y++){ // Insert Value into cache slot
        for (int z = 0; z < 32; z++){
          if (FullAss[y][z] == -1){ FullAss[y][z] = value; breakFlag = 1; break; }
        }
        if (breakFlag == 1){ break; }
      }
    }
  }

/*
  // Test for Decimal to Binary conversion
  printf(" - Decimal to Binary Test\n");
  for (int i = 0; i < 500; i++){
    for (int x = 0; x < 100; x++){ binary[x] = 0; }
    int index = decimalToBinary(decimal, binary);
    for (int j = index; binary[j] != -1; j--){
      printf("%d", binary[j]);
    } printf("\n"); decimal++;
  }
*/
  printf("  - Fully Associative Miss Ratio (percent): %0.5f\n", 100.0*((float)Miss/500.0));
  printf(" -- Ending Fully Associative -- \n\n");

  printf(" -- Starting Direct Mapped CACHE -- \n"); Miss = 0;

  getMemLocations(memLocal);
  // Convert memLocations to binary
  for (int i = 0; i < 500; i++){
    int index = decimalToBinary(memLocal[i], binary); //printf("Mem: %5d; Binary: ", memLocal[i]);
    for (int j = index; binary[j] != -1; j--){ /*printf("%d", binary[j]);*/ } //printf("\n");
    for (int j = 0; j < 100; j++){ binary[j] = 0; }
  }

  value = 0; breakFlag = 0; DIRECT DirectMap[128][32] = {-1};
  for (int i = 0; i < 500; i++){
    value = memLocal[i] % 69; breakFlag = 0;
    // Search DirectMapped
    for (int j = 0; j < 128; j++){
      for (int x = 0; x < 32; x++){
        if (value == DirectMap[j][x].Cache.Value){ breakFlag = 1; break; }
      }
      if (breakFlag == 1){ break; }
    }
    if (breakFlag == 0){
      Miss++;
      for (int y = 0; y < 128; y++){ // Insert Value into cache slot
        for (int z = 0; z < 32; z++){
          if (DirectMap[y][z].Cache.Tag == -1){
            DirectMap[y][z].Cache.Value = value; breakFlag = 1;
            DirectMap[y][z].Cache.Tag = 1; DirectMap[y][z].Cache.Index = y;
            break;
          }
        }
        if (breakFlag == 1){ break; }
      }
    }
  }

  printf("  - Direct Mapped Miss Ratio (percent): %0.5f\n", 100.0*((float)Miss/500.0));
  printf(" -- Ending Direct Mapped -- \n\n");

  printf(" -- Starting 2-way Set Associative CACHE -- \n"); Miss = 0;
  getMemLocations(memLocal);
  for (int i = 0; i < 500; i++){
    int index = decimalToBinary(memLocal[i], binary); //printf("Mem: %5d; Binary: ", memLocal[i]);
    for (int j = index; binary[j] != -1; j--){ /*printf("%d", binary[j]);*/ } //printf("\n");
    for (int j = 0; j < 100; j++){ binary[j] = 0; }
  }

  value = 0; breakFlag = 0; TWO TwoWay[128] = {-1};
  for (int i = 0; i < 500; i++){
    value = memLocal[i] % 69; breakFlag = 0;
    // Search 2 Way
    for (int j = 0; j < 128; j++){
      for (int x = 0; x < 2; x++){
        for (int r = 0; r < 16; r++){
          if (value == TwoWay[j].Cache[x].Value[r]){ breakFlag = 1; break; }
        }
      }
      if (breakFlag == 1){ break; }
    }
    if (breakFlag == 0){
      Miss++;
      for (int y = 0; y < 128; y++){ // Insert Value into cache slot
        for (int z = 0; z < 2; z++){
          for (int w = 0; w < 16; w++){
            if (TwoWay[y].Cache[z].Value[w] == -1){
              TwoWay[y].Cache[z].Value[w] = value; breakFlag = 1;
              TwoWay[y].Cache[z].Tag = 1; TwoWay[y].Cache[z].Index = y;
              break;
            }
          }
          if (breakFlag == 1){ break; }
        }
        if (breakFlag == 1){ break; }
      }
      if (breakFlag == 1){ break; }
    }
  }

  printf("  - 2-way Set Associative Miss Ratio (percent): %0.5f\n", 100.0*((float)Miss/500.0));
  printf(" -- Ending 2-way -- \n\n");

  printf(" -- Starting 4-way Set Associative CACHE --  \n"); Miss = 0;
  getMemLocations(memLocal);
  for (int i = 0; i < 500; i++){
    int index = decimalToBinary(memLocal[i], binary); //printf("Mem: %5d; Binary: ", memLocal[i]);
    for (int j = index; binary[j] != -1; j--){ /*printf("%d", binary[j]);*/ } //printf("\n");
    for (int j = 0; j < 100; j++){ binary[j] = 0; }
  }

  value = 0; breakFlag = 0; FOUR FourWay[64] = {-1};
  for (int i = 0; i < 500; i++){
    value = memLocal[i] % 69; breakFlag = 0;
    // Search 4 Way
    for (int j = 0; j < 64; j++){
      for (int x = 0; x < 4; x++){
        for (int r = 0; r < 16; r++){
          if (value == FourWay[j].Cache[x].Value[r]){ breakFlag = 1; break; }
        }
      }
      if (breakFlag == 1){ break; }
    }
    if (breakFlag == 0){
      Miss++;
      for (int y = 0; y < 64; y++){ // Insert Value into cache slot
        for (int z = 0; z < 4; z++){
          for (int w = 0; w < 16; w++){
            if (TwoWay[y].Cache[z].Value[w] == -1){
              TwoWay[y].Cache[z].Value[w] = value; breakFlag = 1;
              TwoWay[y].Cache[z].Tag = 1; TwoWay[y].Cache[z].Index = y;
              break;
            }
          }
          if (breakFlag == 1){ break; }
        }
        if (breakFlag == 1){ break; }
      }
      if (breakFlag == 1){ break; }
    }
  }

  printf("  - 4-way Set Associative Miss Ratio (percent): %0.5f\n", 100.0*((float)Miss/500.0));
  printf(" -- Ending 4-way -- \n\n");

  return 0;
}
