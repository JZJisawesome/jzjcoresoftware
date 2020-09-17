#Function implementations for the c header ctype.h
#MIT licensed

.text

/* Character Classification */

#TODO

#.global isalnum
#isalnum:#int ch






.global islower
islower:#int ch
    addi a0, a0, -97#Move lowercase letters to a range between 0 and 25
    sltiu a0, a0, 26#Set if a lowercase letter
    ret

.global isupper
isupper:#int ch
    addi a0, a0, -65#Move uppercase letters to range between 0 and 25
    sltiu a0, a0, 26#Set if a lowercase letter
    ret

.global iscntrl
iscntrl:#int ch
    addi a0, a0, 1#Move control characters to range between 0 and 32 (overflows DEL which becomes 0)
    andi a0, a0, 0x0000007F#Zero out high 25 bits (overflow as if this was a 7 bit register)
    sltiu a0, a0, 33#Set if a control character
    ret

.global isgraph
isgraph:#int ch
    addi a0, a0, -33#Move graphical characters to range between 0 and 93
    sltiu a0, a0, 94#Set if a graphical character
    ret

.global isprint
isprint:#int ch
    addi a0, a0, -32#Move printable characters to range between 0 and 94
    sltiu a0, a0, 95#Set if a printable character
    ret
    
/* Character Manipulation */

#TODO make faster

.global tolower
tolower:#int ch
    #Only modify character if it is an uppercase letter
    addi t0, a0, -65#Move uppercase letters to range between 0 and 25 and store in t0
    li t1, 25
    bgtu t0, t1, 1f#Not uppercase
    
    #Character was uppercase, so we make it lowercase
    addi a0, a0, 32
1:
    ret#int
    
.global toupper
toupper:#int ch
    #Only modify character if it is a lowercase letter
    addi t0, a0, -97#Move lowercase letters to range between 0 and 25 and store in t0
    li t1, 25
    bgtu t0, t1, 1f#Not lowercase
    
    #Character was lowercase, so we make it uppercase
    addi a0, a0, -32
1:
    ret#int
