#Random functions for stdlib.h
#Thank you https://en.wikipedia.org/wiki/Xorshift

#Same values as the wikipedia c implementation for 32 bit random xorshift
.equ RAND_SHIFT_VAL_1, 13
.equ RAND_SHIFT_VAL_2, 17
.equ RAND_SHIFT_VAL_3, 5

#Initial seed value (must be nonzero)
.equ INITIAL_SEED, 0x1234abcd

.global rand
rand:
    #Load the current seed
    lw a0, __randomseed
    
    #1st xor and shift
    slli t0, a0, RAND_SHIFT_VAL_1
    xor a0, a0, t0
    
    #2nd xor and shift
    srli t1, a0, RAND_SHIFT_VAL_2
    xor a0, a0, t1
    
    #3rd xor and shift
    srli t2, a0, RAND_SHIFT_VAL_3
    xor a0, a0, t2
    
    #Save the new seed (using t3 as a scratch register)
    sw a0, __randomseed, t3
    
    #Return the new seed as well
    ret#int

.global srand
srand:#unsigned seed
    beqz a0, 1f#Check if the seed is 0
    #Seed was nonzero, so we can use it
    sw a0, __randomseed, t0#Store seed into the __randomseed variable using t0 as a scratch register
1:  #We skip here if the seed was 0
    ret

#Holds the current seed
.data
.align 4
__randomseed: .word INITIAL_SEED

/* Old Implementation (LCG) */
/*
#Random functions for stdlib.h
#Requires linking with libgcc and is slower, so the xorshift implementation is preferred
#Thank you https://en.wikipedia.org/wiki/Linear_congruential_generator
.text

#Constants for random (same values as glibc according to wikipedia)
.equ RAND_M, 0x80000000
.equ RAND_A, 1103414245
.equ RAND_C, 12345

#Initial seed value
.equ INITIAL_SEED, 0x1234abcd

.global rand
rand:
    #Push ra to the stack
    addi sp, sp, -4#Allocate space on the stack
    sw ra, 0(sp)#Save ra to the stack

    #Load terms to be multiplied and use libgcc's __mulsi3 to multiply
    li a0, RAND_A
    lw a1, __randomseed
    call __mulsi3#Product in a0
    
    #Add C to the product
    li t0, RAND_C
    add a0, a0, t0#Sum in a0
    
    #Load term for modulus and use libgcc's __modsi3 to perform modulus
    li a1, RAND_M
    call __modsi3#Modulus in a0
    
    #a0 now contains our new seed, which will will store to __randomseed and also return
    sw a0, __randomseed, t0#Store new seed into the __randomseed variable using t0 as a scratch register
    
    #Pop ra off the stack
    lw ra, 0(sp)#Load ra from the stack
    addi sp, sp, 4#Free space on the stack
    
    #Return the new seed
    ret#int

.global srand
srand:#unsigned seed
    sw a0, __randomseed, t0#Store seed into the __randomseed variable using t0 as a scratch register
    ret 

#Holds the current seed
.data
.align 4
__randomseed: .word INITIAL_SEED
*/
