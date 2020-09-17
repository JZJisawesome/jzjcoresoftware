#Function implementations for the c header ctype.h
#MIT licensed

.text

/* Character Classification */

#TODO

.global isalnum#TODO make faster
isalnum:#int ch
    addi a0, a0, -48#Move digits to range between 0 and 9
    sltiu t0, a0, 10#Set t0 if a digit
    addi a0, a0, -17#Move uppercase letters to range between 0 and 25
    sltiu t1, a0, 26#Set t1 if an uppercase letter
    addi a0, a0, -32#Now move lowercase letters to range between 0 and 25
    sltiu t2, a0, 26#Set t2 if a lowercase letter
    or a0, t0, t1#Set a0 if a digit or uppercase letter
    or a0, a0, t2#Set a0 if a digit, uppercase letter, or lowercase letter
    ret#int

.global isalpha#TODO make faster
isalpha:#int ch
    addi a0, a0, -65#Move uppercase letters to range between 0 and 25
    sltiu t0, a0, 26#Set t0 if an uppercase letter
    addi a0, a0, -32#Now move lowercase letters to range between 0 and 25
    sltiu t1, a0, 26#Set t1 if a lowercase letter
    or a0, t0, t1#Set a0 if an uppercase or lowercase letter
    ret#int

.global islower
islower:#int ch
    addi a0, a0, -97#Move lowercase letters to a range between 0 and 25
    sltiu a0, a0, 26#Set if a lowercase letter
    ret#int

.global isupper
isupper:#int ch
    addi a0, a0, -65#Move uppercase letters to range between 0 and 25
    sltiu a0, a0, 26#Set if an uppercase letter
    ret#int
    
.global isdigit
isdigit:#int ch
    addi a0, a0, -48#Move digits to range between 0 and 9
    sltiu a0, a0, 10#Set if a digit
    ret#int
    
.global isxdigit
isxdigit:#int ch
    #TODO
    ret

.global iscntrl#TODO make faster
iscntrl:#int ch
    addi a0, a0, 1#Move control characters to range between 0 and 32 (overflows DEL which becomes 0)
    andi a0, a0, 0x0000007F#Zero out high 25 bits (overflow as if this was a 7 bit register)
    sltiu a0, a0, 33#Set if a control character
    ret#int
    
.global isgraph
isgraph:#int ch
    addi a0, a0, -33#Move graphical characters to range between 0 and 93
    sltiu a0, a0, 94#Set if a graphical character
    ret#int

.global isspace#TODO make faster
isspace:#int ch
    addi a0, a0, -9#Move whitespace characters other than ' ' to range between 0 and 4
    sltiu t0, a0, 5#Set t0 if a0 was a whitespace characters other than ' '
    addi a0, a0, -23#Move ' ' to value 0
    seqz t1, a0#Set t1 if a0 was ' '
    or a0, t0, t1#Set a0 if '\t' or ' '
    ret#int

.global isblank#TODO make faster
isblank:#int ch
    addi a0, a0, -9#Move '\t' to value 0
    seqz t0, a0#Set t0 if a0 was '\t'
    addi a0, a0, -23#Move ' ' to value 0
    seqz t1, a0#Set t1 if a0 was ' '
    or a0, t0, t1#Set a0 if '\t' or ' '
    ret#int

.global isprint
isprint:#int ch
    addi a0, a0, -32#Move printable characters to range between 0 and 94
    sltiu a0, a0, 95#Set if a printable character
    ret#int
    
.global ispunct
ispunct:#int ch
    #TODO
    ret
    
/* Character Manipulation */

.global tolower#TODO make faster
tolower:#int ch
    #Only modify character if it is an uppercase letter
    addi t0, a0, -65#Move uppercase letters to range between 0 and 25 and store in t0
    li t1, 25
    bgtu t0, t1, 1f#Not uppercase
    
    #Character was uppercase, so we make it lowercase
    addi a0, a0, 32
1:
    ret#int
    
.global toupper#TODO make faster
toupper:#int ch
    #Only modify character if it is a lowercase letter
    addi t0, a0, -97#Move lowercase letters to range between 0 and 25 and store in t0
    li t1, 25
    bgtu t0, t1, 1f#Not lowercase
    
    #Character was lowercase, so we make it uppercase
    addi a0, a0, -32
1:
    ret#int
