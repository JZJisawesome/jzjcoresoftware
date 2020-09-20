#Miscellaneous Function implementations for the c header stdlib.h
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
