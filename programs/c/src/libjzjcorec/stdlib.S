#Function implementations for the c header stdlib.h
#MIT licensed
#Thank you https://twilco.github.io/riscv-from-scratch/
.text

#TODO there are still lots left to implement here (cppreference is not supper organized on a per header basis)

/* Program Utilities */

#Program Termination

.global abort#Note: does not do signal handling
abort:
.global _Exit
_Exit:#int
    ecall#Halts JZJCore cpu

/* Pseudo-Random Number Generation */
#Seperated into a different compilation unit: random.S

/* Math Stuff */

#Absolute functions
.global abs
.global labs
abs:#int n
labs:#long n
    bgez a0, 1f#Only negate if n < 0
    neg a0, a0#Negate n since it is < 0
1:
    ret#int/long (abs/labs)
    
#TODO
/*
.global llabs
llabs:#long long
    
    ret#long long
*/

#Division functions
#Depends on libgcc to do the heavy lifting
#TODO probably should make a seperate compilation unit for this because of its dependence on libgcc

#TODO
/*
.global div
div:#int x, int y
    

    #jal __divsi3
    ret
*/
