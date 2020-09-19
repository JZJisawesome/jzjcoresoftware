#Implements some simple string functions (not the more complicated parsing stuff) 
.text

#TODO lots left to implement

/* String manipulation */

.global strcpy#TODO try to speed things up by using lw instruction instead
strcpy:#char* dest, const char* src
    mv t0, a0#Save original location of dest to t0
    
1:  #Copy Loop
    lb t1, 0(a1)#Load character currently at current src offset
    sb t1, 0(a0)#Store character to current dest offset
    addi a1, a1, 1#Increment src offset
    addi a0, a0, 1#Increment dest offset
    bnez t1, 1b#Keep looping if the null character was not copied
    
    #dest now contains the same data as src, but we must return the original value of &dest
    mv a0, t0#Restore original location of dest to a0
    ret#char*

/* Character array manipulation */

.global memset#TODO try to speed things up by using sw instruction instead
memset:#void* dest, int ch, size_t count
    mv t0, a0#Save original location of dest to t0
    
1:  #Write loop
    sb a1, 0(a0)#Store ch to current dest offset
    addi a0, a0, 1#Increment dest offset
    addi a2, a2, -1#Decrement count (the number of characters we have left fill)
    bnez a2, 1b#Keep looping until we are done counting (count == 0)

    #dest now contains the same data as src, but we must return the original value of &dest
    mv a0, t0#Restore original location of dest to a0
    ret#void*

.global memcpy#TODO try to speed things up by using lw instruction instead
memcpy:#void* dest, const void* src, size_t count
    mv t0, a0#Save original location of dest to t0
    
1:  #Copy loop
    lb t1, 0(a1)#Load character currently at current src offset
    sb t1, 0(a0)#Store character to current dest offset
    addi a1, a1, 1#Increment src offset
    addi a0, a0, 1#Increment dest offset
    addi a2, a2, -1#Decrement count (the number of characters we have left to copy)
    bnez a2, 1b#Keep looping until we are done counting (count == 0)
    
    #dest now contains the same data as src, but we must return the original value of &dest
    mv a0, t0#Restore original location of dest to a0
    ret#void*
