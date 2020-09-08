.text
 
.global __mulsi3#TODO work on speeding up
__mulsi3:#int a, int b
    mv t0, a0#Move int a to register t0

    li t1, 0#Initialize loop iterator to 0
    li a0, 0#Initialize result register to 0
    
    #Multiplication Loop
.__mulsi3_loop_begin:
    beq t1, a1, .__mulsi3_multiply_done#Check if we have finished multiplying
    add a0, a0, t0#Add int a to the result register
    addi t1, t1, 1#Increment loop iterator
    j .__mulsi3_loop_begin#Jump to the beginning of the loop
    
.__mulsi3_multiply_done:
    ret
