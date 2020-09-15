#Function implementations for the c header stdlib.h
#MIT licensed
#Thank you https://twilco.github.io/riscv-from-scratch/
.text

#TODO there are still lots left to implement here (cppreference is not supper organized on a per header basis)

/* Division functions */
#Depends on libgcc to do the heavy lifting

.global div
div:#int x, int y
    #__divsi3
    addi sp, sp, -8
    sw s0, 0(sp)
    sw s1, 4(sp)
    ret
