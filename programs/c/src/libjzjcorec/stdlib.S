#Function implementations for the c header stdlib.h
#MIT licensed
#Thank you https://twilco.github.io/riscv-from-scratch/
.text

#TODO there are still lots left to implement here (cppreference is not supper organized on a per header basis)

/* Division functions */
#Depends on libgcc to do the heavy lifting

.global div
div:#int x, int y
    #TODO

    /*
    addi sp, sp, -8
    sw s0, 0(sp)
    sw s1, 4(sp)
    
    mv s0, a0
    mv s1, a1
    
    
    lw s0, 0(sp)
    lw s1, 4(sp)
    addi sp, sp, 8
    */
    #jal __divsi3
    ret
