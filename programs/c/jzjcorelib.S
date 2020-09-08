.text

.global __muldi3
__muldi3:#long a, long b
.global __mulsi3
__mulsi3:#int a, int b
    #Note: For RV32, long and int are the same size (1 word)
    
    bge a1, a0, 1f#If b is bigger that a, it should be the amount that is incremented by, and vice-versa
    
    #a was bigger than b
    mv t0, a0#Move a to register t0
    #b is already in a1
    j 2f#Move onto next step

1:  #b was bigger than a
    mv t0, a1#Move b to register t0
    mv a1, a0#Move a to register a1

2:  #a1 negative handling (t0 now contains the bigger number, a1 contains the smaller number)
    #Since we add t0 a1 times, a1 must be positive
    sltz t1, a1#Set the was negative flag appropriately
    bgez a1, 3f#a1 is positive so we dont have to do anything
    
    sub a1, zero, a1#Make a1 positive if it was negative
    
3:  #Setup things for the loop
    li t2, 0#Initialize loop iterator to 0; TODO ensure an int sized iterator is big enough
    li a0, 0#Initialize result register to 0
    
4:  #Multiplication Loop
    beq t2, a1, 5f#Check if we have finished multiplying (if we have added t0 to the result register a1 times)
    add a0, a0, t0#Add t0 to the value in the result register
    addi t2, t2, 1#Increment loop iterator
    j 4b#Jump to the beginning of the loop
    
5:  #Change the sign of the result if a1 was negative
    beqz t1, 6f#Check if the negative flag was not set

    sub a0, zero, a0#Negate the result in the case that it is
    
6:  #Return the result
    ret#long or int for __muldi3 or __mulsi3
