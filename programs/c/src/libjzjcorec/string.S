#Implements simple string functions for the string.h header (not the more complicated parsing stuff)
#TODO should probably split up into more files
.text

#TODO lots left to implement

/* String Manipulation */

.global strcpy#TODO try to speed things up by using lw instruction instead
strcpy:#char* dest, const char* src
    mv t0, a0#Save original location of dest to t0
    
1:  #Copy Loop
    lbu t1, 0(a1)#Load character currently at current src offset
    sb t1, 0(a0)#Store character to current dest offset
    addi a1, a1, 1#Increment src offset
    addi a0, a0, 1#Increment dest offset
    bnez t1, 1b#Keep looping if the null character was not copied
    
    #dest now contains the same data as src, but we must return the original value of &dest
    mv a0, t0#Restore original location of dest to a0
    ret#char*
    
.global strxfrm
strxfrm:#char* restrict dest, const char* restrict src, size_t count
    #Because no extra locales are supported by this library, this function is super simple because
    #strcoll is the same as strcmp. This means that we don't have to change the strings at all; we just have
    #to return the count parameter
    mv a0, a2#Move count to a0 to be returned
    ret#size_t
    
/* String Examination */

.global strlen#TODO make faster (lw instruction, more efficient looping/counting)
strlen:#const char *str
    li t0, -1#Load the counting variable with -1 to offset the first loop iteration
    
1:  #Counting loop
    lbu t1, 0(a0)#Get the character at the index
    addi a0, a0, 1#Add 1 to the index of the string to access
    addi t0, t0, 1#Add 1 to the count (although this is done before the branch is executed, the extra increment is offset by t0's initial value of -1)
    bnez t1, 1b#Continue looping if the null byte was not encountered
    
    mv a0, t0#Move the count to a0 to be returned
    ret#size_t
    
.global strcmp
strcmp:#const char* lhs, const char* rhs
.global strcoll#Always using the default C locale
strcoll:#const char* lhs, const char* rhs
    mv t0, a0#Move lhs to t0 (makes it easier to return things later)

1:  #Comparison loop
    lbu t1, 0(t0)#Load character at rhs
    
    #TODO
    
    ret#int


/* Character Array Manipulation */

.global memcmp#TODO try to speed things up by using sw instruction instead and other things
memcmp:#const void* lhs, const void* rhs, size_t count
    mv t0, a0#Move lhs to t0 (makes it easier to return things later)
    
1:  #Comparison loop
    lbu t1, 0(t0)#Load character at current lhs to t1
    lbu t2, 0(a1)#Load character at current rhs to t2
    bne t1, t2, 2f#Break from loop if characters were not equal
    #Continue if the lhs[x] == rhs[x]
    addi t0, t0, 1#Increment lhs
    addi a1, a1, 1#Increment rhs
    addi a2, a2, -1#Decrement count (the number of characters we have left to compare)
    bnez a2, 1b#Keep looping until we are done counting (count == 0)

    #All characters were equal
    li a0, 0
    ret#int
    
2:  #lhs[x] != rhs[x]
    bgtu t1, t2, 3f#Determine if lhs[x] > rhs[x]
    #lhs[x] < rhs[x]
    li a0, -1#Return negative value
    ret#int
    
3:  #lhs[x] > rhs[x]
    li a0, 1#Return positive value
    ret#int

.global memset#TODO try to speed things up by using sw instruction instead
memset:#void* dest, int ch, size_t count
    mv t0, a0#Save original location of dest to t0
    
1:  #Write loop
    sb a1, 0(a0)#Store ch to current dest offset
    addi a0, a0, 1#Increment dest offset
    addi a2, a2, -1#Decrement count (the number of characters we have left to fill)
    bnez a2, 1b#Keep looping until we are done counting (count == 0)

    #dest now contains the same data as src, but we must return the original value of &dest
    mv a0, t0#Restore original location of dest to a0
    ret#void*

.global memcpy#TODO try to speed things up by using lw instruction instead
memcpy:#void* dest, const void* src, size_t count
    mv t0, a0#Save original location of dest to t0
    
1:  #Copy loop
    lbu t1, 0(a1)#Load character currently at current src offset
    sb t1, 0(a0)#Store character to current dest offset
    addi a1, a1, 1#Increment src offset
    addi a0, a0, 1#Increment dest offset
    addi a2, a2, -1#Decrement count (the number of characters we have left to copy)
    bnez a2, 1b#Keep looping until we are done counting (count == 0)
    
    #dest now contains the same data as src, but we must return the original value of &dest
    mv a0, t0#Restore original location of dest to a0
    ret#void*
