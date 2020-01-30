.data
	a: .space 20
	b: .space 16
.text
	addi $s0, $zero, 2
	addi $s1, $zero, 29
	addi $s2, $zero, 2020
	addi $s3, $zero, 11
	addi $s4, $zero, 0
#index is t0, storing content in a[i]
	addi $t0, $zero, 0
	
	sw $s0, a($t0)
	    addi $t0, $t0, 4
	sw $s1, a($t0)
	    addi $t0, $t0, 4
	sw $s2, a($t0)
	    addi $t0, $t0, 4
	sw $s3, a($t0)
	    addi $t0, $t0, 4
	sw $s4, a($t0)
	    addi $t0, $t0, 4
	
#storing the a[i]+a[i+1] in b[i]
	addi $t0, $zero, 0
        lw $t1, a($t0)
	addi $t0, $zero, 4
        lw $t2, a($t0)
        addi $t0, $zero, 8
        lw $t3, a($t0)
        addi $t0, $zero, 12
        lw $t4, a($t0)
        addi $t0, $zero, 16
        lw $t5, a($t0)  
        
        add $s5, $t1, $t2
        add $s6, $t3, $t2
        add $s7, $t3, $t4
        add $t8, $t4, $t5
                
        addi $t0, $zero, 0               
        sw $s5, b($t0)
	    addi $t0, $t0, 4
	sw $s6, b($t0)
	    addi $t0, $t0, 4
	sw $s7, b($t0)
	    addi $t0, $t0, 4
	sw $t8, b($t0)
	    addi $t0, $t0, 4
		
	
