#Simple software floating point routines for the math.h c header
.text

.global copysignf
copysignf:#float x, float y
    #Sign bit is bit 31
    li t0, 0x7FFFFFFF#Bit mask to remove sign bit in x
    and a0, a0, t0#Set sign bit of x to 0
    addi t0, t0, 1#Change bitmask to 0x80000000 to extract sign bit from y
    and a1, a1, t0#Extract sign bit of y
    or a0, a0, a1#Copy sign bit of y to x
    ret#float
    
.global copysign
copysign:#double x, double y
    #Sign bit is bit 63 (bit 31 of most significant word of a double)
    li t0, 0x7FFFFFFF#Bit mask to remove sign bit in x msw
    and a1, a1, t0#Set sign bit of x msw to 0
    addi t0, t0, 1#Change bitmask to 0x80000000 to extract sign bit from y msw
    and a3, a3, t0#Extract sign bit of y msw
    or a1, a1, a3#Copy sign bit of y msw to x msw
    ret#double
