#Simple software floating point routines for the math.h c header
.text

.global ilogbf
ilogbf:#float arg
    #The exponent is bits 30:23 of arg
    slli a0, a0, 23#Shift exponent to bits 7:0
    andi a0, a0, 0x000000FF#Get rid of the sign bit
    addi a0, a0, -127#Remove the floating point bias by subtracting 127 from the exponent
    ret#int

.global ilogb
ilogb:#double arg
    #The exponent is bits 30:23 of arg most significant word
    slli a0, a1, 20#Shift exponent from msw to bits 10:0 and store in a0
    andi a0, a0, 0x000007FF#Get rid of the sign bit
    addi a0, a0, -1023#Remove the floating point bias by subtracting 1023 from the exponent
    ret#int

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
