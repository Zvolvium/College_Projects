; Mason Motschke CSCI-370
; ---------------------
; Prints text on the screen via the C library (printf)
;
; Compile: nasm -f elf64 -l hw2-filename.lst hw2-filename.asm
; Link: gcc -m64 -no-pie -fno-pie hw2-filename.o -o hw2-filename
; Run: ./hw2-filename
; ---------------------

    extern printf               ;the C function, to be called

      section .data             ;Data section, initialized variables
msg:  db "Mason Motschke", 0       ;C string needs 0
fmt:  db "%s", 10, 0            ;the frinf format, "\n",'0'

      section .text             ;code section

      global main               ;standard gcc entry point
main:                           ;program label for the entry point
      push rbp                  ;set up stack frame, must be alligned

      mov rdi,fmt
      mov rsi,msg
      mov rax,0                 ;or can be  xor   rax,rax
      call printf               ;call C function

      pop rbp                   ;restore stack

      mov rax,0                 ;normal, no error, return value
      ret                       ;return
