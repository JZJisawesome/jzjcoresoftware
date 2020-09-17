#Function implementations for the c header ctype.h
#MIT licensed

.text

/* Character Classification */

/* Character Manipulation */

.global tolower
tolower:#int ch
    #Only modify character if it is an uppercase letter
    li t0, 'A'
    bltu a0, t0, 1f#Not uppercase
    li t1, 'Z'
    bgtu a0, t1, 1f#Not uppercase
    
    #Character was uppercase, so we make it lowercase
    addi a0, a0, 32
1:
    ret#int
    
.global toupper
toupper:#int ch
    #Only modify character if it is a lowercase letter
    li t0, 'a'
    bltu a0, t0, 1f#Not lowercase
    li t1, 'z'
    bgtu a0, t1, 1f#Not lowercase
    
    #Character was lowercase, so we make it uppercase
    addi a0, a0, -32
1:
    ret#int
