	.globl main
	.text

main:
	li $t0, 2
	li $t1, 29
	li $t2, 2020
	li $t3, 11
	li $t4, 0
	
	la  $t0, list
        sw  $s1, 0($t0)
        sw  $s2, 4($t1)
        sw  $s3, 8($t2)
        sw  $s4, 12($t3)
        sw  $s5, 16($t4)
        
        la  $t0, array1
        sw  $t1, 0($t0)
        
        	# Exit the program by means of a syscall.
	# There are many syscalls - pick the desired one
	# by placing its code in $v0. The code for exit is "10"
exit:   li $v0, 10 # Sets $v0 to "10" to select exit syscall
	syscall # Exit

	# All memory structures are placed after the
	# .data assembler directive
	.data

	# The .word assembler directive reserves space
	# in memory for a single 4-byte word (or multiple 4-byte words)
	# and assigns that memory location an initial value
	# (or a comma separated list of initial values)
list:	.space	12		#  declare 12 bytes of storage to hold array of 3 integers
list: .word 3, 2, 1, 0, 1, 2