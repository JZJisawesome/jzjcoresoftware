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
    
#TODO implement
.global llabs
llabs:#long long n
.global imaxabs
imaxabs:#intmax_t n
    li t0, 0x10000000#Load bitmask to get the sign bit
    and t1, a1, t0#Get the sign bit from the most significant word of n and store in t1
    beqz t1, 4f#If the number is positive (sign bit was 0), there is no need to negate it
    
    #Negate n
    mv a0, t2#Store a copy of the original lest significant word of n in order to be able to detect overflow
    #TODO
    
4:  #Branch here if not negating
    ret#long long/intmax_t (llabs/imaxabs)
