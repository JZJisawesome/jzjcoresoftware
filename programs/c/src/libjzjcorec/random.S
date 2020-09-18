#Random functions for stdlib.h
#Requires linking with libgcc
#Thank you https://en.wikipedia.org/wiki/Linear_congruential_generator
#TODO look into https://en.wikipedia.org/wiki/Xorshift
.text

#Constants for random (same values as glibc according to wikipedia)
.equ RAND_M, 0x80000000
.equ RAND_A, 1103414245
.equ RAND_C, 12345

#Initial seed value
.equ INITIAL_SEED, 0x1234abcd

.global rand#TODO create an implementation that does not depend on libgcc (it might even make sense to put back into stdlib.S again)
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

#TODO FIX rand() IS NOT WORKING PROPERLY
