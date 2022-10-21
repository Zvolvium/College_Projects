/*****************************************************/
/* MIPS SIMULATOR                                    */
/* Ronald Marsh (C) 2022                             */
/*****************************************************/
#include "./MIPSsim.h"

/****************************************************************/
/* SUPPORT FUNCTIONS											*/
/****************************************************************/
/*****************************************************/
/* LOAD                                              */
/*                                                   */
/* Load the register file data.                      */
/*****************************************************/
int LOAD(char *filename) {	
int    i, j, k, size;
size_t chrCount;
char   *text;
FILE   *stream;
   // Open the file and make sure it was opened.
   if ((stream = fopen(filename, "r")) == NULL) {
      printf("ERROR - Could not open %s file.\n", filename);
      exit(0);
   }
   // Read until end of file to get size.
   size = 0;
   while (1) {
      text = NULL;
      getline(&text, &chrCount, stream);	// getline expects 3 pointer arguments.
      free(text);
      if (feof(stream)) break;
      size++;
   }
   size++;
   // Allocate memory for Register File (array of struct).
   if ((RegFile = (struct _data*)calloc(size, sizeof(struct _data))) == NULL) {
      printf("ERROR - Could not allocate memory.\n");
      exit(0);
   }
   // Rewind the file.
   rewind(stream);
   // Load the commands.
   strcpy(RegFile[0].command, "00010000000000000000000000000000"); 		// Replace with a NOOP.
   for (i = 1; i <= size; i++) {
       text  = NULL;
       getline(&text, &chrCount, stream);
       // Remove line comments.
       if (text[0] != '/') {
          // Remove trailing comments.
          for (j = 0; j < strlen(text); j++) {
              if (text[j] == '/') text[j] = '\0';
          }
          // Remove all periods.
          k = 0;
          for (j = 0; j < strlen(text); j++) {
              if (text[j] != '.') {
                 RegFile[i].command[k] = text[j];
                 k++;
              }
          }
        } else {
          strcpy(RegFile[i].command, "00010000000000000000000000000000"); // Replace with a NOOP.
        }
        free(text);
   }
   fclose(stream);
   return size;
}

/*****************************************************/
/* BYTE_PARSE                                        */
/*                                                   */
/* Parse and extract the byte for each N bit string. */
/* To be more general, we return an INT type.        */
/*****************************************************/
int BYTE_PARSE(int cnt, int offset, char command[]) {
int i, sum = 0;
int start = 0;
long multiplier = 1;
    for (i = 0; i < (cnt-1); i++) {
        multiplier *= 2;
    }
    for (i = 0; i < cnt; i++) {
        if (command[start+offset] == '1') sum+=multiplier;
        start++;
        multiplier /= 2;

    }
    return sum;
}

/****************************************************************/
/* CPU FUNCTIONS											    */
/****************************************************************/
/*****************************************************/
/* ALU                                               */
/*                                                   */
/* ALU gets DataA, DataB, and a shift amount. Then,  */
/* based on the flag, ALU will perform the requested */
/* math operation on the 3 inputs and return the     */
/* result.                                           */
/*                                                   */
/* The flags are:                                    */
/* AND 				-> flag = 0                      */
/* OR  				-> flag = 1                      */
/* XOR 				-> flag = 2                      */
/* ADD 				-> flag = 5                      */
/* SUBTRACT 		-> flag = 6                      */
/* SET ON LESS THAN -> flag = 7                      */
/* SET ON EQUAL     -> flag = 8                      */
/* SHIFT LEFT       -> flag = 9                      */
/* SHIFT RIGHT      -> flag = 10                     */
/*****************************************************/
byte ALU(byte DataA, byte DataB, byte shift, byte flag) {
    if (flag ==  0) return (DataA & DataB);
    if (flag ==  1) return (DataA | DataB);
    if (flag ==  2) return (DataA ^ DataB);
    if (flag ==  5) return (DataA + DataB);
    if (flag ==  6) return (DataA - DataB);
    if ((flag == 7) && (DataA <  DataB)) return 1;
    if ((flag == 8) && (DataA == DataB)) return 1;
    if (flag ==  9) return (DataA << shift);
    if (flag == 10) return (DataA >> shift);
    return 0;
}

/*****************************************************/
/* REGISTER                                          */
/*                                                   */
/* REGISTER gets Reg, Data, and a flag. Then, based  */
/* on the flag, REGISTER will return (read) the value*/
/* in the specified register (Reg) or write the data */
/* value (Data) into the specified register (Reg).   */
/*                                                   */
/* Notes:                                            */
/* 1) There are only 6 registers.                    */
/* 2) Register 0 is the Program Counter.             */
/* 3) Register 5 calls scanf to read a byte from the */
/*    keyboard.                                      */
/* 4) Register 6 calls printf to write a byte to the */
/*    screen.                                        */
/*                                                   */
/* The flags are:                                    */
/* Read from register -> flag = 0                    */
/* Write to register  -> flag = 1                    */
/*****************************************************/
byte REGISTER(byte Reg, byte Data, byte flag) {
static byte REG[7];		// Define registers as local static (like private).
    // Read flag.
    if (flag == READ) {
       if (Reg == 5) scanf("%s", &REG[Reg]);
       return REG[Reg];
    }
    // Write flag
    if (flag == WRITE) {
       REG[Reg] = Data;
       if (Reg == 6) printf("%c", REG[Reg]);
       return 0;
    }
}

/*****************************************************/
/* MEMORY                                            */
/*                                                   */
/* MEMORY gets Address, Data, and a flag. Then,      */
/* based on the flag, MEMORY will return (read) the  */
/* value in the specified memory (Address) or write  */
/* the data value (Data) into the specified memory   */
/* (Address).                                        */
/*                                                   */
/* Notes:                                            */
/* 1) There are only 100 bytes of memory.            */
/*                                                   */
/* The flags are:                                    */
/* Read from memory -> flag = 0                      */
/* Write to memory  -> flag = 1                      */
/*****************************************************/
byte MEMORY(int Address, byte Data, byte flag){
static byte RAM[100];	// Define RAM as local static (like private).
    // Read flag.
    if (flag == READ) {
       return RAM[Address];
    }
    // Write flag
    if (flag == WRITE) {
       RAM[Address] = Data;
       return 0;
    }
}

/*****************************************************/
/* MAIN_CONTROL                                      */
/*****************************************************/
void MAIN_CONTROL(void) {
int  i, j, k;
byte optype, Funct;
byte SrcR1, SrcR2, DestR, Shift;
byte temp1, temp2, temp3;
int  Const;
int  PC = 0;													// Set Program Counter (PC) to 0.
    while (1) {
        if (Debug == TRACE) printf("\nTrace line: %d\n", PC);
        if (Debug == WATCHREG) {
          // printf("\n");
           printf("\nCurrent line: %d\n", PC);
           printf("Register [values]:\n");
           for (i = 0; i < 5; i++) {
               printf("%1d->[%3d]  ", i, REGISTER(i, 0, READ));
           }
           printf("\n");
        }
        if (Debug == WATCHMEM) {
           printf("\nCurrent line: %d\n", PC);
           printf("Memory [values]:\n");
           k = 0;
           for (j = 0; j < 10; j++) {
               for (i = 0; i < 10; i++) {
                   printf("%2d->[%3d]  ", k, MEMORY(k, 0, READ));
                   k++;
               }
               printf("\n");
           }
           printf("\n");
        }
        optype = (byte)BYTE_PARSE(6, 0, RegFile[PC].command);	// Determine Operand Type.
        /************************************************/
        /* Trap R-Type                                  */
        /************************************************/
        if (optype == R_Type) {									// Tested
           SrcR1 = (byte)BYTE_PARSE(5,  6, RegFile[PC].command);// Get source register 1.
           SrcR2 = (byte)BYTE_PARSE(5, 11, RegFile[PC].command);// Get source register 2.
           DestR = (byte)BYTE_PARSE(5, 16, RegFile[PC].command);// Get destination register.
           Shift = (byte)BYTE_PARSE(5, 21, RegFile[PC].command);// Get any shift value.
           Funct = (byte)BYTE_PARSE(6, 26, RegFile[PC].command);// Determine what function to do.
           temp1 = REGISTER(SrcR1, 0, READ);					// Read data from register.
           temp2 = REGISTER(SrcR2, 0, READ);					// Read data from register.
           temp3 = ALU(temp1, temp2, Shift, Funct);				// Do arithmetic.
           REGISTER(DestR, temp3, WRITE);						// Write result to destination register.
           if (Debug == ALL || Debug == RTYPE || (Debug == WATCH && WPC == PC)) {
              printf("\nR_TYPE:\n");
              printf("Line number %d [%s]\n", PC, RegFile[PC].command);
              printf("Source Register %d \tvalue %d\n", SrcR1, temp1);
              printf("Source Register %d \tvalue %d\n", SrcR2, temp2);
              printf("Shift amount %d\n", Shift);
              printf("Math operation ");
              if (Funct == 0) printf("AND\n");
              if (Funct == 1) printf("OR\n");
              if (Funct == 2) printf("XOR\n");
              if (Funct == 5) printf("ADD\n");
              if (Funct == 6) printf("SUBTRACT\n");
              if (Funct == 7) printf("SET ON LESS THAN\n");
              if (Funct == 8) printf("SET ON EQUAL\n");
              if (Funct == 9) printf("SHIFT LEFT\n");
              if (Funct ==10) printf("SHIFT RIGHT\n");
              printf("Destination Register %d \tvalue %d\n", DestR, temp3);
           }
           PC++;                                                // Increment PC.
        }
        /************************************************/
        /* Trap J-Type                                  */
        /************************************************/
        if (optype == JUMP) {
           PC = BYTE_PARSE(26,  6, RegFile[PC].command);		// Update Program Counter.
           if (Debug == ALL || Debug == JTYPE || (Debug == WATCH && WPC == PC)) {
              printf("Jump to line %d.\n", PC);
           }
        }
        if (optype == EXIT) {									// Tested
           return;												// Exit program.
        }
        if (optype == NOOP) {									// Tested
           PC++;												// NOOP (Must be a comment)
        }
        /************************************************/
        /* Trap I-Type                                  */
        /************************************************/
        // Branch On Equal.
        if (optype == BOEQ) {
           SrcR1 = (byte)BYTE_PARSE(5,  6, RegFile[PC].command);// Get source register 1.
           SrcR2 = (byte)BYTE_PARSE(5, 11, RegFile[PC].command);// Get source register 2.
           Const = BYTE_PARSE(16,16, RegFile[PC].command);		// Get target line number.
           temp1 = REGISTER(SrcR1, 0, READ);					// Read data from register.
           temp2 = REGISTER(SrcR2, 0, READ);					// Read data from register.
           temp3 = ALU(temp2, temp1, 0, 8);						// Compare register 1 and 2.
           if (Debug == ALL || Debug == ITYPE_B || (Debug == WATCH && WPC == PC)) {
              printf("\nBRANCH ON EQUAL:\n");
              printf("Line number %d [%s]\n", PC, RegFile[PC].command);
              printf("Source Register %d \tvalue %d\n", SrcR1, temp1);
              printf("Source Register %d \tvalue %d\n", SrcR2, temp2);
              printf("Target line %d\n", Const);
              printf("Equal test result %d\n", temp3);
           }
           if (temp3 == 1) {
              PC = Const;										// Adjust PC.
           } else {
              PC++;                                             // Increment PC.
           }
        }
        // Branch on Not Equal.
        if (optype == BONE) {
           SrcR1 = (byte)BYTE_PARSE(5,  6, RegFile[PC].command);// Get source register 1.
           SrcR2 = (byte)BYTE_PARSE(5, 11, RegFile[PC].command);// Get source register 2.
           Const = BYTE_PARSE(16,16, RegFile[PC].command);		// Get target line number.
           temp1 = REGISTER(SrcR1, 0, READ);					// Read data from register.
           temp2 = REGISTER(SrcR2, 0, READ);					// Read data from register.
           temp3 = ALU(temp2, temp1, 0, 8);						// Compare register 1 and 2.
           if (Debug == ALL || Debug == ITYPE_B || (Debug == WATCH && WPC == PC)) {
              printf("\nBRANCH ON NOT EQUAL:\n");
              printf("Line number %d [%s]\n", PC, RegFile[PC].command);
              printf("Source Register %d \tvalue %d\n", SrcR1, temp1);
              printf("Source Register %d \tvalue %d\n", SrcR2, temp2);
              printf("Target line %d\n", Const);
              printf("Equal test result %d\n", temp3);
           }
           if (temp3 != 1) {
              PC = Const;										// Adjust PC.
           } else {
              PC++;                                             // Increment PC.
           }
        }
        // Branch on Less Than.
        if (optype == BOLT) {
           SrcR1 = (byte)BYTE_PARSE(5,  6, RegFile[PC].command);// Get source register.
           SrcR2 = (byte)BYTE_PARSE(5, 11, RegFile[PC].command);// Get destination register.
           Const = BYTE_PARSE(16,16, RegFile[PC].command);		// Get target line number.
           temp1 = REGISTER(SrcR1, 0, READ);					// Read data from register.
           temp2 = REGISTER(SrcR2, 0, READ);					// Read data from register.
           temp3 = ALU(temp2, temp1, 0, 7);	 					// Compare register 1 and 2.
           if (Debug == ALL || Debug == ITYPE_B || (Debug == WATCH && WPC == PC)) {
              printf("\nBRANCH ON LESS THAN:\n");
              printf("Line number %d [%s]\n", PC, RegFile[PC].command);
              printf("Source Register %d \tvalue %d\n", SrcR1, temp1);
              printf("Source Register %d \tvalue %d\n", SrcR2, temp2);
              printf("Target line %d\n", Const);
              printf("Equal test result %d\n", temp3);
           }
           if (temp3 == 1) {
              PC = Const;										// Adjust PC.
           } else {
              PC++;                                             // Increment PC.
           }
        }
        // Branch on Greater Than.
        if (optype == BOGT) {
           SrcR1 = (byte)BYTE_PARSE(5,  6, RegFile[PC].command);// Get source register.
           SrcR2 = (byte)BYTE_PARSE(5, 11, RegFile[PC].command);// Get destination register.
           Const = BYTE_PARSE(16,16, RegFile[PC].command);		// Get target line number.
           temp1 = REGISTER(SrcR1, 0, READ);					// Read data from register.
           temp2 = REGISTER(SrcR2, 0, READ);					// Read data from register.
           temp3 = ALU(temp2, temp1, 0, 7);	 					// Compare register 1 and 2.
           if (Debug == ALL || Debug == ITYPE_B || (Debug == WATCH && WPC == PC)) {
              printf("\nBRANCH ON GREATER THAN:\n");
              printf("Line number %d [%s]\n", PC, RegFile[PC].command);
              printf("Source Register %d \tvalue %d\n", SrcR1, temp1);
              printf("Source Register %d \tvalue %d\n", SrcR2, temp2);
              printf("Target line %d\n", Const);
              printf("Equal test result %d\n", temp3);
           }
           if (temp3 != 1) {
              PC = Const;										// Adjust PC.
           } else {
              PC++;                                             // Increment PC.
           }
        }
        // Load a byte from RAM.
        if (optype == LODB) {									// Tested
           SrcR1 = (byte)BYTE_PARSE(5,  6, RegFile[PC].command);// Get source register.
           DestR = (byte)BYTE_PARSE(5, 11, RegFile[PC].command);// Get destination register.
           Const = BYTE_PARSE(16,16, RegFile[PC].command);		// Get constant/literal.
           temp1 = REGISTER(SrcR1, 0, READ);					// Read data from register.
           temp2 = ALU(temp1, Const, 0, 5);						// Calculate RAM address.
           temp3 = MEMORY(temp2, 0, READ);						// Get data from RAM.
           REGISTER(DestR, temp3, WRITE);						// Write data to register.
           if (Debug == ALL || Debug == ITYPE_M || (Debug == WATCH && WPC == PC)) {
              printf("\nLOAD BYTE FROM MEMORY:\n");
              printf("Line number %d [%s]\n", PC, RegFile[PC].command);
              printf("Source Register %d \tvalue %d\n", SrcR1, temp1);
              printf("Constant %d\n", Const);
              printf("Memory location %d\n", temp2);
              printf("Destination Register %d \tvalue %d\n", DestR, temp3);
           }
           PC++;                                                // Increment PC.
        }
        // Save a byte to RAM.
        if (optype == SAVB) {									// Tested
           SrcR1 = (byte)BYTE_PARSE(5,  6, RegFile[PC].command);// Get source register.
           SrcR2 = (byte)BYTE_PARSE(5, 11, RegFile[PC].command);// Get destination register.
           Const = BYTE_PARSE(16,16, RegFile[PC].command);		// Get RAM offset.
           temp1 = REGISTER(SrcR1, 0, READ);					// Read data from register.
           temp2 = ALU(temp1, Const, 0, 5);						// Calculate RAM address.
           temp3 = REGISTER(SrcR2, 0, READ);					// Read data from register.
           MEMORY(temp2, temp3, WRITE);							// Write data to RAM.
           if (Debug == ALL || Debug == ITYPE_M || (Debug == WATCH && WPC == PC)) {
              printf("\nSAVE BYTE TO MEMORY:\n");
              printf("Line number %d [%s]\n", PC, RegFile[PC].command);
              printf("Source Register %d \tvalue %d\n", SrcR1, temp1);
              printf("Constant %d\n", Const);
              printf("Source Register %d \tvalue %d\n", SrcR2, temp3);
              printf("Destination Memory %d \tvalue %d\n", temp2, temp3);
           }
           PC++;                                                // Increment PC.
        }

        // AND a constant.
        if (optype == ANDI) {									// Tested
           SrcR1 = (byte)BYTE_PARSE(5,  6, RegFile[PC].command);// Get source register.
           DestR = (byte)BYTE_PARSE(5, 11, RegFile[PC].command);// Get destination register.
           Const = BYTE_PARSE(16,16, RegFile[PC].command);		// Get constant/literal.
           temp1 = REGISTER(SrcR1, 0, READ);					// Read data from register.
           temp2 = ALU(temp1, Const, 0, 0);						// AND constant to source register.
           REGISTER(DestR, temp2, WRITE);						// Write result to register.
           if (Debug == ALL || Debug == ITYPE_I || (Debug == WATCH && WPC == PC)) {
              printf("\nAND IMMEDIATE:\n");
              printf("Line number %d [%s]\n", PC, RegFile[PC].command);
              printf("Source Register=%d \tvalue=%d\n", SrcR1, temp1);
              printf("Constant=%d\n", Const);
              printf("Destination Register=%d value=%d\n", DestR, temp2);
           }
           PC++;                                                // Increment PC.
        }
        // OR a constant.
        if (optype == ORRI) {									// Tested
           SrcR1 = (byte)BYTE_PARSE(5,  6, RegFile[PC].command);// Get source register.
           DestR = (byte)BYTE_PARSE(5, 11, RegFile[PC].command);// Get destination register.
           Const = BYTE_PARSE(16,16, RegFile[PC].command);		// Get constant/literal.
           temp1 = REGISTER(SrcR1, 0, READ);					// Read data from register.
           temp2 = ALU(temp1, Const, 0, 1);						// OR constant to source register.
           REGISTER(DestR, temp2, WRITE);						// Write result to register.
           if (Debug == ALL || Debug == ITYPE_I || (Debug == WATCH && WPC == PC)) {
              printf("\nOR IMMEDIATE:\n");
              printf("Line number %d [%s]\n", PC, RegFile[PC].command);
              printf("Source Register=%d \tvalue=%d\n", SrcR1, temp1);
              printf("Constant=%d\n", Const);
              printf("Destination Register=%d value=%d\n", DestR, temp2);
           }
           PC++;                                                // Increment PC.
        }
        if (optype == XORI) {									// Tested
           SrcR1 = (byte)BYTE_PARSE(5,  6, RegFile[PC].command);// Get source register.
           DestR = (byte)BYTE_PARSE(5, 11, RegFile[PC].command);// Get destination register.
           Const = BYTE_PARSE(16,16, RegFile[PC].command);		// Get constant/literal.
           temp1 = REGISTER(SrcR1, 0, READ);					// Read data from register.
           temp2 = ALU(temp1, Const, 0, 2);						// XOR constant to source register.
           REGISTER(DestR, temp2, WRITE);						// Write result to register.
           if (Debug == ALL || Debug == ITYPE_I || (Debug == WATCH && WPC == PC)) {
              printf("\nXOR IMMEDIATE:\n");
              printf("Line number %d [%s]\n", PC, RegFile[PC].command);
              printf("Source Register=%d \tvalue=%d\n", SrcR1, temp1);
              printf("Constant=%d\n", Const);
              printf("Destination Register=%d value=%d\n", DestR, temp2);
           }
           PC++;                                                // Increment PC.
        }
        // Add a constant.
        if (optype == ADDI) {									// Tested
           SrcR1 = (byte)BYTE_PARSE(5,  6, RegFile[PC].command);// Get source register.
           DestR = (byte)BYTE_PARSE(5, 11, RegFile[PC].command);// Get destination register.
           Const = BYTE_PARSE(16,16, RegFile[PC].command);		// Get constant/literal.
           temp1 = REGISTER(SrcR1, 0, READ);					// Read data from register.
           temp2 = ALU(temp1, Const, 0, 5);						// Add constant to source register.
           REGISTER(DestR, temp2, WRITE);						// Write result to register.
           if (Debug == ALL || Debug == ITYPE_I || (Debug == WATCH && WPC == PC)) {
              printf("\nADD IMMEDIATE:\n");
              printf("Line number %d [%s]\n", PC, RegFile[PC].command);
              printf("Source Register=%d \tvalue=%d\n", SrcR1, temp1);
              printf("Constant=%d\n", Const);
              printf("Destination Register=%d value=%d\n", DestR, temp2);
           }
           PC++;                                                // Increment PC.
        }
    }
}

/*****************************************************/
/* Main                                              */
/*****************************************************/
int main(int argv, char **argc) {
int  i, size;
    if (argv == 1) {
       printf("*******************************************\n");
       printf("* MIPSsim                                 *\n");
       printf("* -------                                 *\n");
       printf("* You must include a file name to load.   *\n");
       printf("* For example: ./MIPSsim test.mips        *\n");
       printf("*                                         *\n");
       printf("* You can also include a debug code.      *\n");
       printf("* For example: ./MIPSsim test.mips ALL    *\n");
       printf("*                                         *\n");
       printf("* Instruction debug codes:                *\n");
       printf("* ALL - All debugging.                    *\n");
       printf("* R --- R-Type debugging only.            *\n");
       printf("* J --- J-Type debugging only.            *\n");
       printf("* IB -- I-Type BRANCH debugging only.     *\n");
       printf("* IM -- I-Type LOAD/SAVE debugging only.  *\n");
       printf("* II -- I-Type IMMEDIATE debugging only.  *\n");
       printf("*                                         *\n");
       printf("* Line and memory debug codes:            *\n");
       printf("* TRACE   - Display all lines executed.   *\n");
       printf("* WATCH N - Watch/debug line N (integer). *\n");
       printf("* WATCH R - Watch/debug registers.        *\n");
       printf("* WATCH M - Watch/debug memory.           *\n");
       printf("*******************************************\n");
       return 1;
    }
    if (argv == 2) {
       size = LOAD(argc[1]);				// Load/build register file.
       MAIN_CONTROL();						// Start program.
    }
    if (argv == 3) {						// Turn on debugging.
       if (!strcmp("ALL", argc[2])) Debug = ALL;
       if (!strcmp("R",   argc[2])) Debug = RTYPE;
       if (!strcmp("J",   argc[2])) Debug = JTYPE;
       if (!strcmp("IB",  argc[2])) Debug = ITYPE_B;
       if (!strcmp("IM",  argc[2])) Debug = ITYPE_M;
       if (!strcmp("II",  argc[2])) Debug = ITYPE_I;
       if (!strcmp("TRACE", argc[2])) Debug = TRACE;
       size = LOAD(argc[1]);				// Load/build register file.
       MAIN_CONTROL();						// Start program.
    }
    if (argv == 4) {						// Turn on watching.
       if (!strcmp("WATCH",   argc[2])) {
          Debug = WATCH;
          WPC = atoi(argc[3]);
          if (!strcmp("R",  argc[3])) Debug = WATCHREG;
          if (!strcmp("M",  argc[3])) Debug = WATCHMEM;
       }
       size = LOAD(argc[1]);				// Load/build register file.
       MAIN_CONTROL();						// Start program.
    }
    return 1;
}