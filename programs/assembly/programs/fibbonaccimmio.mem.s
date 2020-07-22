    # memory mapped IO setup
    #x28 holds the address of the start of the memory mapped io address region
    addi x28, x0, -32
    
    #Set low 16 bits of port b as outputs
    li x31, 0x0000FFFF
    sw x31, 4(x28)
    
    # x29 is x, x30 is y, x31 is z
    # register setup
    addi x29, x0, 0
    addi x30, x0, 1
    addi x31, x0, 0
    
loop:
    #get next term
    add x31, x29, x30
    
    #Write term to port b
    sw x31, 20(x28)
    
    # shift terms back
    addi x29, x30, 0
    addi x30, x31, 0
    
    #jump to start of loop
    j loop
    
    #invalid code will be displayed if we reach here because jal failed
    addi x31, x0, 4
