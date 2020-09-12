#MIT licensed
#Provides gcc arithmetic functions as well as some nice other ones
#Note: For RV32, long and int are the same size (1 word), so many functions share identical code
.text

/* GCC Integer Routines */

#TODO maybe use shifts like division to speed things up
.global __mulsi3
__mulsi3:#int a, int b
.global __muldi3
__muldi3:#long a, long b
    #Put abs(a) into t0 for testing
    mv t0, a0
    bgez t0, 7f#Don't negate a if it is already positive
    sub t0, zero, t0#Negate a to make it positive
7:#TODO put all numbered labels in order

    #Put abs(b) into t1 testing
    mv t1, a1
    bgez t1, 8f#Don't negate b if it is already positive
    sub t1, zero, t1#Negate b to make it positive
8:#TODO put all numbered labels in order
    
    bge t1, t0, 1f#If abs(b) is bigger than abs(a), it should be the amount that is incremented by, and vice-versa
    
    #We don't need the current values of t0 and t1 anymore
    
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
    
4:  #Multiplication loop
    beq t2, a1, 5f#Check if we have finished multiplying (if we have added t0 to the result register a1 times)
    add a0, a0, t0#Add t0 to the value in the result register
    addi t2, t2, 1#Increment loop iterator
    j 4b#Jump to the beginning of the loop
    
5:  #Change the sign of the result if a1 was negative
    beqz t1, 6f#Check if the negative flag was not set

    sub a0, zero, a0#Negate the result in the case that it is
    
6:  #Return the result
    ret#int/long (__mulsi3/__muldi3)

#Very useful website for division
#http://www.tofla.iconbar.com/tofla/arm/arm02/index.htm
#I used their algorithm (the "To divide 50 (%110010) by 10 (%1010) in binary") to implement this, but I did not copy their code
#TODO speed up even more
.global __udivsi3
__udivsi3:#unsigned int a, unsigned int b
.global __udivdi3
__udivdi3:#unsigned long a, unsigned long b
    beqz a1, 5f#Bail out if b = 0

    mv t0, a0#Move a to t0
    li a0, 0#Clear the result register
    
    bgtu a1, t0, 5f#Return 0 if b is greater than a
    
    li t1, 1#Initialize the bit mask register with 1
    #t0 contains a, a1 contains b

    #Shift b left until it is just under or equal to the value of a
1:  #Initial left shift loop
    slli t2, a1, 1#Shift b by 1 and store in t2
    bgtu t2, t0, 3f#That shift was too much; b would be greater than a, so that means we don't have to shift anymore
    bltu t2, a1, 3f#The shift overflowed so we can't shift anymore
    slli a1, a1, 1#The shift would still make b less than or equal to a and it didn't overflow b, so we actually perform the shift
    slli t1, t1, 1#Shift the bitmask along with b
    j 1b#We need to shift more; repeat the loop
    
    #TODO redo labels

3:  #Actual Division Loop (t0 contains a, a1 contains the shifted b, t1 contains a bit mask)
    blt t0, a1, 4f#b is bigger than a, so we cannot subtract this iteration
    sub t0, t0, a1#Subtract b from a
    or a0, a0, t1#We subtracted so we should set the corresponding bit in the result register (or a0 with the mask t2)
4:  #Second part of loop; preparing for next iteration
    srli a1, a1, 1#Shift b back right 1 position
    srli t1, t1, 1#Shift the bit mask back right 1 position
    bnez t1, 3b#We are not done dividing (shift times != 0 because the bit mask != 0) so keep looping

5:  #Return the result register
    ret#int/long (__udivsi3/__udivdi3)

    
    

