/*****************************************************/
/* MIPS SIMULATOR                                    */
/* Ronald Marsh (C) 2022                             */
/*****************************************************/
/* COMMENTS                                          */
/*  // -> Indicates that anything on that line after */
/*  the // characters is a comment and to be ignored.*/   
/*                                                   */
/*  If the file parser detects a // at the front of a*/
/*  line, that line is replaced with an internal NOOP*/
/*  instruction. This is done to ensure that the line*/
/*  number does not change from that shown in an     */
/*  editor.                                          */
/*---------------------------------------------------*/
/* R TYPE OPERAND CODE:                              */
/*  000000 -> R type                                 */
/*                                                   */
/* R TYPE FUNCTION CODES:                            */
/*  000000 -> AND                                    */
/*  000001 -> OR                                     */
/*  000010 -> XOR                                    */
/*  000101 -> ADD                                    */
/*  000110 -> SUBTRACT                               */
/*  000111 -> SET ON LESS THAN                       */
/*  001000 -> SET ON EQUAL                           */
/*  001001 -> SHIFT LEFT                             */
/*  001010 -> SHIFT RIGHT                            */
/*                                                   */
/* R TYPE COMMAND FORMAT:                            */
/*  000000.SrcR1.SrcR2.DestR.Shift.Function-Code     */
/*  SrcR1 -> Source Register 1 (5 bits)              */
/*  SrcR2 -> Source Register 2 (5 bits)              */
/*  DestR -> Destination Register (5 bits)           */
/*  Shift -> Bit shift amount (if any) (5 bits)      */
/*  000000.5bits.5bits.5bits.5bits.Function-Code     */
/*                                                   */
/* R TYPE EXAMPLE:                                   */
/*  000000.00001.00010.00011.00000.000101            */
/*---------------------------------------------------*/
/* J TYPE OPERAND CODES                              */
/*  000010 -> JUMP (Jump to a line)                  */
/*  000011 -> EXIT (Terminates MIPSsim)              */
/*  Note: There are no J-type function codes.        */
/*                                                   */
/* J TYPE EXAMPLE:                                   */
/*  000010.00000000000000000000000100 -> Jump to 4   */
/*  000011.00000000000000000000000000 -> Terminate   */
/*---------------------------------------------------*/
/* I TYPE OPERAND CODES                              */
/*  010000 -> BRANCH ON EQUAL                        */
/*  010001 -> BRANCH ON NOT EQUAL                    */
/*  010010 -> BRANCH ON LESS THAN                    */
/*  010011 -> BRANCH ON GREATER THAN                 */
/*  010100 -> LOAD A BYTE FROM RAM                   */
/*  010101 -> SAVE A BYTE TO RAM                     */
/*  010110 -> ADD A CONSTANT (ADD IMMEDIATE)         */
/*  010111 -> AND A CONSTANT (AND IMMEDIATE)         */
/*  011000 -> OR A CONSTANT (OR IMMEDIATE)           */
/*  011001 -> XOR A CONSTANT (OR IMMEDIATE)          */
/*  Note: There are no I-type function codes.        */
/*                                                   */
/* I TYPE COMMAND FORMAT:                            */
/*  Operand.SrcR1.SrcR2.Const                        */
/*  SrcR1 -> Source Register 1 (5 bits)              */
/*  SrcR2 -> Source Register 2 (5 bits)              */
/*  Const -> Constant (16 bits)                      */
/*                                                   */
/* I TYPE EXAMPLE:                                   */
/*  010110.00001.00110.0000000001110100 -> ADD 116   */
/*  to the contents of Register 1 and put the result */
/*  in Register 6.                                   */
/*                                                   */
/*  010000.00010.00011.0000000000000010 -> Branch to */
/*  line 2, if the contents of Register 2 are equal  */
/*  to the contents of Register 3.                   */
/*---------------------------------------------------*/
/* REGISTER ADDRESSES                                */
/* 00000  -> REG[0]                                  */
/* 00001  -> REG[1]                                  */
/* 00010  -> REG[2]                                  */
/* 00011  -> REG[3]                                  */
/* 00100  -> REG[4]                                  */
/* 00101  -> REG[5] Reads a byte from keyboard       */
/* 00110  -> REG[6] Writes a byte to screen          */
/*---------------------------------------------------*/
/* RAM ADDRESSES                                     */
/* 00000000 -> Base address (RAM[0])                 */
/* 01100011 -> Max address (RAM[99])                 */
/*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Instruction defines
#define R_Type 0
#define JUMP 2  // J_Type
#define EXIT 3  // J_Type
#define NOOP 4  // J_Type
#define BOEQ 16 // I_Type
#define BONE 17 // I_Type
#define BOLT 18 // I_Type
#define BOGT 19 // I_Type
#define LODB 20 // I_Type
#define SAVB 21 // I_Type
#define ADDI 22 // I_Type
#define ANDI 23 // I_Type
#define ORRI 24 // I_Type
#define XORI 25 // I_Type

// Memory access defines
#define READ 0
#define WRITE 1

//Debug defines and variables
#define ALL      1  // All debugging
#define RTYPE    2  // R-Type debugging only.
#define JTYPE    3  // J-Type debugging only. 
#define ITYPE_B  4  // I-Type BRANCH debugging only.
#define ITYPE_M  5  // I-Type LOAD/SAVE debugging only.
#define ITYPE_I  6  // I-Type IMMEDIATE debugging only.
#define TRACE    7  // Display lines executed.
#define WATCH    10 // Watch a line flag.
#define WATCHREG 11 // Watch a register flag.
#define WATCHMEM 12 // Watch a memory flag.

int Debug = 0;							// Define debugging flag.
int WPC   = -1;						    // Line to watch.

typedef char byte;						// Define data as being of signed bytes.

struct _data {							// Define the register file as a structure.
   char command[33];
} *RegFile;


/****************************************************************/
/* FUNCTION PROTOTYPES											*/
/****************************************************************/
int LOAD(char *filename);
int DEBUG(char *filename);
int BYTE_PARSE(int cnt, int offset, char command[]);
byte ALU(byte DataA, byte DataB, byte shift, byte flag);
byte REGISTER(byte Reg, byte Data, byte flag);
byte MEMORY(int Address, byte Data, byte flag);