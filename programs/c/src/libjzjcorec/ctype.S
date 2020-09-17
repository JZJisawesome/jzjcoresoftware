#Function implementations for the c header ctype.h
#MIT licensed

.text

/* Character Classification */
#To avoid wasting time loading immediates for branches, these functions subtract their input
#to make the desired characters fall into a range between 0 and something
#They then use unsigned set if less than immediate to determine if a character falls into that range
#Should there be multiple ranges to check, the result of each is stored into temporary registers and
#or'ed at the end

#The table at https://en.cppreference.com/w/c/string/byte and the one at http://www.asciitable.com/ helped significantly

.global isalnum#TODO make faster
isalnum:#int ch
    addi a0, a0, -48#Move digits to range between 0 and 9
    sltiu t0, a0, 10#Set t0 if ch was a digit
    addi a0, a0, -17#Now move uppercase letters to range between 0 and 25
    sltiu t1, a0, 26#Set t1 if ch was an uppercase letter
    addi a0, a0, -32#Now move lowercase letters to range between 0 and 25
    sltiu t2, a0, 26#Set t2 if ch was a lowercase letter
    
    or a0, t0, t1#Set a0 if ch was a digit or uppercase letter
    or a0, a0, t2#Set a0 if ch was a digit, uppercase letter, or lowercase letter
    ret#int

.global isalpha#TODO make faster
isalpha:#int ch
    addi a0, a0, -65#Move uppercase letters to range between 0 and 25
    sltiu t0, a0, 26#Set t0 if ch was an uppercase letter
    addi a0, a0, -32#Now move lowercase letters to range between 0 and 25
    sltiu t1, a0, 26#Set t1 if ch was a lowercase letter
    
    or a0, t0, t1#Set a0 if ch was an uppercase or lowercase letter
    ret#int

.global islower
islower:#int ch
    addi a0, a0, -97#Move lowercase letters to a range between 0 and 25
    sltiu a0, a0, 26#Set a0 if ch was a lowercase letter
    ret#int

.global isupper
isupper:#int ch
    addi a0, a0, -65#Move uppercase letters to range between 0 and 25
    sltiu a0, a0, 26#Set a0 if ch was an uppercase letter
    ret#int
    
.global isdigit
isdigit:#int ch
    addi a0, a0, -48#Move digits to range between 0 and 9
    sltiu a0, a0, 10#Set a0 if ch was a digit
    ret#int
    
.global isxdigit#TODO make faster
isxdigit:#int ch
    addi a0, a0, -48#Move digits to range between 0 and 9
    sltiu t0, a0, 10#Set t0 if ch was a digit
    addi a0, a0, -17#Now move uppercase hex digits to range between 0 and 5
    sltiu t1, a0, 6#Set t1 if ch was an uppercase hex digit
    addi a0, a0, -32#Now move lowercase hex digits to range between 0 and 5
    sltiu t2, a0, 6#Set t2 if ch was an lowercase hex digit
    
    or a0, t0, t1#Set a0 if ch was a digit or uppercase hex digit
    or a0, a0, t2#Set a0 if ch was a digit, uppercase hex digit, or lowercase hex digit
    ret

#iscntrl is special. It takes advantage of overflowing to treat the two control groups as one group
#In 7 bit ASCII, DEL is right next to NUL if it overflowed
#Because RV32 registers are 32 bits, it uses andi to only preserve the low 7 bits, emulating 7 bit overflow
#This saves 2 instructions (another subtraction, slt, and a final or would be needed in place of the andi)
.global iscntrl#TODO make faster
iscntrl:#int ch
    addi a0, a0, 1#Move control characters to range between 0 and 32 (overflows DEL which becomes 0)
    andi a0, a0, 0x0000007F#Zero out high 25 bits (overflow as if this was a 7 bit register)
    sltiu a0, a0, 33#Set a0 if ch was a control character
    ret#int
    
.global isgraph
isgraph:#int ch
    addi a0, a0, -33#Move graphical characters to range between 0 and 93
    sltiu a0, a0, 94#Set a0 if ch was a graphical character
    ret#int

.global isspace#TODO make faster
isspace:#int ch
    addi a0, a0, -9#Move whitespace characters other than ' ' to range between 0 and 4
    sltiu t0, a0, 5#Set t0 if ch was a whitespace characters other than ' '
    addi a0, a0, -23#Now move ' ' to value 0
    seqz t1, a0#Set t1 if ch was ' '
    
    or a0, t0, t1#Set a0 if ch was '\t' or ' '
    ret#int

.global isblank#TODO make faster
isblank:#int ch
    addi a0, a0, -9#Move '\t' to value 0
    seqz t0, a0#Set t0 if ch was '\t'
    addi a0, a0, -23#Now move ' ' to value 0
    seqz t1, a0#Set t1 if ch was ' '
    
    or a0, t0, t1#Set a0 if ch was '\t' or ' '
    ret#int

.global isprint
isprint:#int ch
    addi a0, a0, -32#Move printable characters to range between 0 and 94
    sltiu a0, a0, 95#Set a0 if ch was a printable character
    ret#int
    
.global ispunct#TODO make faster
ispunct:#int ch
    addi a0, a0, -33#Move first group of punctuation characters to range between 0 and 14
    sltiu t0, a0, 15#Set t0 if ch was in the first group of punctuation characters
    addi a0, a0, -25#Move second group of punctuation characters to range between 0 and 6
    sltiu t1, a0, 7#Set t1 if ch was in the second group of punctuation characters
    addi a0, a0, -33#Move third group of punctuation characters to range between 0 and 5
    sltiu t2, a0, 6#Set t2 if ch was in the third group of punctuation characters
    addi a0, a0, -32#Move forth group of punctuation characters to range between 0 and 3
    sltiu t3, a0, 4#Set t3 if ch was in the forth group of punctuation characters
    
    or t0, t0, t1#Set t0 if ch was in the first or second group of punctuation characters
    or t2, t2, t3#Set t2 if ch was in the third or forth group of punctuation characters
    or a0, t0, t2#Set a0 if ch was in the first, second, third, or forth group of punctuation characters
    ret
    
/* Character Manipulation */

.global tolower#TODO make faster
tolower:#int ch
    #Only modify character if it is an uppercase letter
    addi t0, a0, -65#Move uppercase letters to range between 0 and 25 and store in t0
    li t1, 25
    bgtu t0, t1, 1f#Not uppercase
    
    #ch was uppercase, so we make it lowercase
    addi a0, a0, 32
1:
    ret#int
    
.global toupper#TODO make faster
toupper:#int ch
    #Only modify character if it is a lowercase letter
    addi t0, a0, -97#Move lowercase letters to range between 0 and 25 and store in t0
    li t1, 25
    bgtu t0, t1, 1f#Not lowercase
    
    #ch was lowercase, so we make it uppercase
    addi a0, a0, -32
1:
    ret#int
