#Implements simple string functions for the string.h header (not the more complicated parsing stuff) 
.text

#TODO lots left to implement

/* String Manipulation */

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
    
.global strxfrm
strxfrm:#char* restrict dest, const char* restrict src, size_t count
    #Because no extra locales are supported by this library, this function is super simple because
    #strcoll is the same as strcmp. This means that we don't have to change the strings at all; we just have
    #to return the count parameter
    mv a0, a2#Move count to a0 to be returned
    ret#size_t

/* Character Array Manipulation */

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
