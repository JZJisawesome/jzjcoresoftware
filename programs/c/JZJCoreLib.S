#MIT licensed
#Provides gcc arithmetic functions as well as some nice other ones
#Note: For RV32, long and int are the same size (1 word), so many functions share identical code
.text

/* GCC Integer Routines */

#Usefull sources:
#https://stackoverflow.com/questions/2751583/multiply-with-negative-integer-just-by-shifting
#https://stackoverflow.com/questions/37440394/left-shift-multiplication-assembly
.global __mulsi3
__mulsi3:#int a, int b
.global __muldi3
__muldi3:#long a, long b
    #Clear negate result flag
    li t1, 0

    #Put abs(a) into t0 and set t1 to 1 if a was negative
    mv t0, a0
    bgez a0, 1f#Don't negate t0 if a was already positive
    sub t0, zero, t0#Negate t0 to make it positive a
    li t1, 1#Set t1 to 1 because a was negative
    
1:  #Put abs(b) into a1 and invert t1 if b was negative
    bgez a1, 2f#Don't negate b if it is already positive
    sub a1, zero, a1#Negate b to make it positive
    seqz t1, t1#Invert t1 because b was negative

2:  #Setup things for the multiplication loop
    li t2, 0x00000001#Setup the bit mask
    li a0, 0#Clear the result register
    
    #Begin the initial iteration of loop
    j 4f#Don't shift the bit mask the first time around
    
3:  #Multiplication loop
    slli t2, t2, 1#Shift the bit mask left for the next loop iteration
    slli t0, t0, 1#Shift t0 left for the next loop iteration
    beqz t2, 5f#We have gone through all the bits because the bitmask is now 0, so we end the multiplication loop here
4:  #Skipping bitmask and t0 shift initially
    and t3, a1, t2#Check the bit specified by the bit mask in b
    beqz t3, 3b#If the bit was not set, go to the next iteration
    add a0, a0, t0#Add a to a0
    j 3b
    
5:  #Negate the result if t1 was set
    beqz t1, 6f#Check if the negative flag was not set
    sub a0, zero, a0#Negate the result in the case that it is
    
6:  #Return the result
    ret#int/long (__mulsi3/__muldi3)

#Very useful website for division
#http://www.tofla.iconbar.com/tofla/arm/arm02/index.htm
#I used their algorithm (the "To divide 50 (%110010) by 10 (%1010) in binary") to implement this, but I did not copy their code (just referenced it when debugging)
#TODO speed up even more
.global __udivsi3
__udivsi3:#unsigned int a, unsigned int b
.global __udivdi3
__udivdi3:#unsigned long a, unsigned long b
    beqz a1, 5f#Bail out if b = 0

    mv t0, a0#Move a to t0
    li a0, 0#Clear the result register
    
    bgtu a1, t0, 5f#Return 0 if b is greater than a
    
    li t1, 0x00000001#Initialize the bit mask register
    #t0 contains a, a1 contains b

    #Shift b left until it is just under or equal to the value of a
1:  #Initial left shift loop
    slli t2, a1, 1#Shift b by 1 and store in t2
    bgtu t2, t0, 3f#That shift was too much; b would be greater than a, so that means we don't have to shift anymore
    bltu t2, a1, 3f#The shift overflowed so we can't shift anymore
    slli a1, a1, 1#The shift would still make b less than or equal to a and it didn't overflow b, so we actually perform the shift
    slli t1, t1, 1#Shift the bitmask along with b
    j 1b#We need to shift more; repeat the loop
    
    #TODO redo label numbers

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

    
    

