    #Starting address of memory mapped io registers
    li x29, 0xFFFFFFE0
    
    #Set portA to input mode
    sw x0, 0(x29)
loop:
    #Load the value in port a into register 31
    lw x31, 0x10(x29)
    
    #Do this repeatedly
    j loop
