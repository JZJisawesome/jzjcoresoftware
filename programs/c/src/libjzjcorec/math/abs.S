#Integer absolute calculation routines
#int and long are the same for RV32, as is long long and intmax_t
.text

.global abs
.global labs
abs:#int n
labs:#long n
    bgez a0, 1f#Only negate if n < 0
    neg a0, a0#Negate n since it is < 0
1:  #Branch here if not negating
    ret#int/long (abs/labs)
    
.global llabs
llabs:#long long n
.global imaxabs
imaxabs:#intmax_t n
    #TODO make faster: __builtin_abs using srai to speed things up; see if that can be used
    li t0, 0x10000000#Load bitmask to get the sign bit
    and t1, a1, t0#Get the sign bit from the most significant word of n and store in t1
    beqz t1, 1f#If the number is positive (sign bit was 0), there is no need to negate it
    
    #Negate n
    seqz t2, a0#Detect if the least significant word will overflow when negating
    neg a0, a0#Negate the least significant word
    not a1, a1#Invert all bits in the most significant word
    add a1, a1, t2#If negating the lsw overflowed it, we must carry a 1 over to the msw
    
1:  #Branch here if not negating
    ret#long long/intmax_t (llabs/imaxabs)
