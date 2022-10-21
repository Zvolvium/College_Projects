// ----------------------------------------------
// Basic Math using C with embeded assembly
//
// Compile: gcc hw3-filename.c
// ----------------------------------------------
// Mason Motschke CSCI-370 hw3
#include <stdio.h>

int main (void){

  int arg1, arg2, add, sub, mul, quo, rem;

  printf("Enter two Integer numbers: ");
  scanf("%d %d", &arg1, &arg2);

  // Perform Addition, Subtraction, Multiplication & Division
  asm("addl %%ebx, %%eax;" : "=a" (add) : "a" (arg1) , "b" (arg2));
  asm("subl %%ebx, %%eax;" : "=a" (sub) : "a" (arg1) , "b" (arg2));
  asm("imull %%ebx, %%eax;" : "=a" (mul) : "a" (arg1) , "b" (arg2));

  // Display results
  printf("%d + %d = %d\n", arg1, arg2, add);
  printf("%d - %d = %d\n", arg1, arg2, sub);
  printf("%d * %d = %d\n", arg1, arg2, mul);

  return 0;
}
