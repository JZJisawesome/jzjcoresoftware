#note this file is also mit licenced

#Thank you:
#https://twilco.github.io/riscv-from-scratch/2019/04/27/riscv-from-scratch-2.html
#https://stackoverflow.com/questions/50214840/risc-v-startup-code-for-stack-pointer-initalization
#https://gnu-mcu-eclipse.github.io/arch/riscv/programmer/
#https://embarc.org/man-pages/as/RISC_002dV_002dDirectives.html
#https://www.reddit.com/r/RISCV/comments/enmqdz/linker_script_fault/
#https://github.com/deadsy/rvemu/blob/master/test/test1/emu.ld
#https://stackoverflow.com/questions/57021029/how-to-link-math-library-when-building-bare-metal-application-with-custom-linker

#My failed first attempt
#_start: 
#todo init global pointer and stack pointer and call main
#    #Set the global pointer to the location of the __global_pointer$ symbol
#    la gp, __global_pointer$
    
    #Set stack point to the end of physical memory
#    la sp, 16384
    
    #Jump to main
#    jal x1, main
    
    #halt cpu after returning from main
#    ecall

#Practically identical to https://twilco.github.io/riscv-from-scratch/2019/04/27/riscv-from-scratch-2.html
#include "crt0.h"
.section .init, "ax"
.global _start
_start:
    #Hint to assembler about start of function
    .cfi_startproc
    .cfi_undefined ra
    
    #Setup global pointer
    .option push
    .option norelax
    la gp, __global_pointer$
    .option pop
    
    #Setup stack pointer based on linker script symbol
    la sp, __stack_top
    #Also set s0 to the value in the stack pointer
    #addi s0, sp, 0
    
    #Jump to main
    jal x1, main
    
    #Halt cpu if we ever return from main
    ecall
    
    #Hint to the assembler about the end of the function
    .cfi_endproc
    
    #Hint to assembler about end of file
    .end
