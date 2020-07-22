    #Starting address of memory mapped io registers
    li x29, 0xFFFFFFE0
    
    #Set low 4 bits of portA to input mode and higher bits to output
    li x28, 0xFFFFFFF0
    sw x28, 0(x29)
    
loop:
    #Load the value in port a into register 31
    lw x31, 0x10(x29)
    
    #Change some bits in the register
    xori x28, x31, 0x0A0
    
    #Update the port register
    sw x28, 0x10(x29)
    
    #Do this repeatedly
    j loop
