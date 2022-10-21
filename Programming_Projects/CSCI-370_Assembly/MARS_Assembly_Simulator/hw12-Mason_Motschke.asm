# Mason Motschke - CSCI_370 - HW12

# Fibonacci Routine
      .data 
fibs: .word   0 : 1000        # "array" of 12 words to contain fib values
size: .word  12             # size of "array" 
prompt: .asciiz "Enter the Fibonacci sequence size: "
      .text

# Prompt
      la $a0, prompt # Address of string to print
      li $v0, 4 # Loads syscall for printing string
      syscall # Execute $v0
      li $v0, 5 # Get int Input
      syscall # Execute $v0
      sw $v0, size # arrSize = Input
      #li $v0, 1   # Print size -----\/
      #lw $a0, size
      #syscall     # ---------------/\

      la   $t0, fibs        # load address of array
      la   $t5, size        # load address of size variable
      lw   $t5, 0($t5)      # load array size
      li   $t2, 1           # 1 is first and second Fib. number
      add.d $f0, $f2, $f4
      sw   $t2, 0($t0)      # F[0] = 1
      sw   $t2, 4($t0)      # F[1] = F[0] = 1
      addi $t1, $t5, -2     # Counter for loop, will execute (size-2) times
loop: lw   $t3, 0($t0)      # Get value from array F[n] 
      lw   $t4, 4($t0)      # Get value from array F[n+1]
      add  $t2, $t3, $t4    # $t2 = F[n] + F[n+1]
      sw   $t2, 8($t0)      # Store F[n+2] = F[n] + F[n+1] in array
      addi $t0, $t0, 4      # increment address of Fib. number source
      addi $t1, $t1, -1     # decrement loop counter
      bgtz $t1, loop        # repeat if not finished yet.
      la   $a0, fibs        # first argument for print (array)
      add  $a1, $zero, $t5  # second argument for print (size)
      jal  print            # call print routine. 
      
      # Call Function
      jal parity # call parity routine
      
      li   $v0, 10          # system call for exit
      syscall               # we are out of here.

      .data
prompt2: .asciiz "\n\nEnter a binary string: "
prompt3: .asciiz "Parity Bit: "
prompt4: .asciiz "\nString Entered: "
string: .space 9
      .text
parity:
      la $a0, prompt2 # Load Address of prompt2
      li $v0, 4 # Loads syscall to print string
      syscall # Execute $v0
      li $v0, 8 # Load syscall to input string
      la $a0, string # Loads Address of string buffer
      li $a1, 9 # Loads 9 into max chars to read
      syscall
      li $v0, 11 # Load syscall
      li $a0, '\n' # Load char
      syscall # Execute print '\n' char
      li $v0, 4
      la $a0, prompt4
      syscall # Execute print 'String Entered: '
      li $v0, 4
      la $a0, string
      syscall # Execute print var 'string'
      li $v0, 11 # Load syscall
      li $a0, '\n' # Load char
      syscall # Execute print '\n' char

      # Check chars
      la $t7, string # Address of String
      lb $t6, 0($t7) # Load first byte of string
      #li $v0, 11 # Load syscall
      #la $a0, ($t6) # Load char
      #syscall # Execute print first byte of string
      li $t0, '5' # Set parity bit to '5'
      la $t3, ($zero)
      
      li $t1, '1' # Compare bit 
      beq $t1, $t6, line84 # IF bit = '1'
      j a
line84: addi $t3, $t3, 1 #                      0
a:    lb $t6, 1($t7) # Load next byte 
      beq $t1, $t6, line87 # IF bit = '1'
      j c
line87: addi $t3, $t3, 1 #                      1
c:    lb $t6, 2($t7) # Load next byte 
      beq $t1, $t6, line90 # IF bit = '1'
      j d
line90: addi $t3, $t3, 1 #                      2
d:    lb $t6, 3($t7) # Load next byte 
      beq $t1, $t6, line93 # IF bit = '1'
      j e
line93: addi $t3, $t3, 1 #                      3
e:    lb $t6, 4($t7) # Load next byte 
      beq $t1, $t6, line96 # IF bit = '1'
      j f
line96: addi $t3, $t3, 1 #                      4
f:    lb $t6, 5($t7) # Load next byte 
      beq $t1, $t6, line99 # IF bit = '1'
      j g
line99: addi $t3, $t3, 1 #                      5
g:    lb $t6, 6($t7) # Load next byte 
      beq $t1, $t6, line102 # IF bit = '1'
      j h
line102: addi $t3, $t3, 1 #                     6
h:    lb $t6, 7($t7) # Load next byte 
      beq $t1, $t6, line105 # IF bit = '1'
      j continue
line105: addi $t3, $t3, 1 #                     7
      j continue

      # Continue After Loop
continue:
      #move $a0, $t3
      #li $v0, 1
      #syscall # Execute print counter $t3
      
      # How many 1's
      la $t4, ($zero) # number counter $t4 = 0
      beq $t3, $t4, even # IF 0
      addi $t4, $t4, 1 # Increment $t0
      beq $t3, $t4, odd # IF 1
      addi $t4, $t4, 1 # Increment $t0
      beq $t3, $t4, even # IF 2
      addi $t4, $t4, 1 # Increment $t0
      beq $t3, $t4, odd # IF 3
      addi $t4, $t4, 1 # Increment $t0
      beq $t3, $t4, even # IF 4
      addi $t4, $t4, 1 # Increment $t0
      beq $t3, $t4, odd # IF 5
      addi $t4, $t4, 1 # Increment $t0
      beq $t3, $t4, even # IF 6
      addi $t4, $t4, 1 # Increment $t0
      beq $t3, $t4, odd # IF 7
      addi $t4, $t4, 1 # Increment $t0
      beq $t3, $t4, even # IF 8
even:
     li $t0, '1'
     j done
odd:
     li $t0, '0'
     j done
done:
      la $a0, prompt3
      li $v0, 4
      syscall
      la $a0, ($t0)
      li $v0, 11
      syscall # Execute print paritybit
      li $v0, 11 # Load syscall
      li $a0, '\n' # Load char
      syscall # Execute print '\n' char
      jr $ra

      .data
space:.asciiz  " "          # space to insert between numbers
head: .asciiz  "The Fibonacci numbers are:\n"
      .text
print:add  $t0, $zero, $a0  # starting address of array
      add  $t1, $zero, $a1  # initialize loop counter to array size
      la   $a0, head        # load address of print heading
      li   $v0, 4           # specify Print String service
      syscall               # print heading
out:  lw   $a0, 0($t0)      # load fibonacci number for syscall
      li   $v0, 1           # specify Print Integer service
      syscall               # print fibonacci number
      la   $a0, space       # load address of spacer for syscall
      li   $v0, 4           # specify Print String service
      syscall               # output string
      addi $t0, $t0, 4      # increment address
      addi $t1, $t1, -1     # decrement loop counter
      bgtz $t1, out         # repeat if not finished
      jr   $ra              # return
