.data
msg1: .asciiz "Which Fibonacci number would you like: "

.text
.globl main
main:
    li $v0,  4
    la $a0,  msg1
    syscall             # print msg
    li $v0,  5
    syscall             # read an int
    add $a0, $v0, $zero # move to $a0

    jal fib             # call fib

    add $a0, $v0, $zero
    li  $v0, 1
    syscall

    li $v0, 10
    syscall

fib:


    #save in stack
    addi $sp, $sp, -12 
    sw   $ra, 0($sp)
    sw   $s0, 4($sp)
    sw   $s1, 8($sp)

    add $s0, $a0, $zero
     addi $t1, $zero, 1
    beq  $s0, $zero, return0
    beq  $s0, $t1,   return1

    addi $a0, $s0, -1

    jal fib

    add $s1, $zero, $v0         # $s1 = fib(y - 1)

    addi $a0, $s0, -2

    jal fib                     # $v0 = fib(n - 2)
    

    add $v0, $v0, $s1           # $v0 = fib(n - 2) + $s1
    
   
   
    exitfib:

        lw   $ra, 0($sp)        # read registers from stack
        lw   $s0, 4($sp)
        lw   $s1, 8($sp)
        addi $sp, $sp, 12       # bring back stack pointer
        jr $ra

    return1:
        li $v0,1
        j exitfib

    return0:     
        li $v0,0
        j exitfib
