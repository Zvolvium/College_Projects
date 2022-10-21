// ------------------------------------------------------
// Mason Motschke - CSCI 370
//
// ***Have to link math library -lm for successful run***
//      *** pow() used for hex-decimal conversion***
//
// HW4 - Write C Program that prompts user for a HEX value
//  (Assume 8 alpha-numeric characters at most)
//  , converts HEX to decimal and displays result
//  , then convert decimal to binary and displays result
// -------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long hexToDecimal(char *hex){
  long decimal = 0; int len = strlen(hex), val = 0; len--;
  for (int i = 0; hex[i] != '\0'; i++){
    if (hex[i] >= '0' && hex[i] <= '9'){ val = hex[i] - 48; }
    else if (hex[i] >= 'a' && hex[i] <= 'f'){ val = hex[i] - 97 + 10; }
    else if (hex[i] >= 'A' && hex[i] <= 'F'){ val = hex[i] - 65 + 10; }
    decimal += val * pow(16, len); len--;
   } return decimal;
}

int decimalToBinary(long decimal, int array[]){
  int index = 1, remainder; array[0] = -1;
  if (decimal == 0){ array[1] = 0; return index; }
  while (decimal != 0){
    remainder = decimal % 2; array[index] = remainder;
    index++; decimal = decimal / 2;
  } return index;
}

int main (void){
  char *hexString; hexString = (char*)malloc(8 * sizeof(char));
  long decimal; int array[100];
  printf("\nEnter HEX value: ");
  scanf("%8s", hexString); printf("\n");
  decimal = hexToDecimal(hexString);
  printf("Your Decimal Value: %ld\n\n", decimal);
  int arrayIndex = decimalToBinary(decimal, array);
  printf("Your Binary Value: ");
  for (int i = arrayIndex; array[i] != -1; i--){
    printf("%d", array[i]);
  } printf("\n\n");
  free(hexString); return 0;
}
