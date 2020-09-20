#Integer math routines for various c standard headers
#todo separate out into more headers (abs.S and division.S)

/* Absolute functions */
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
    
    ret#long long/intmax_t (llabs/imaxabs)

/* Division functions */
#Depends on libgcc to do the heavy lifting
#TODO probably should make a separate compilation unit for this because of its dependence on libgcc
#TODO actually, just implement division yourself (take from old code folder)

#TODO implement
.global div
div:#int x, int y
.global ldiv
ldiv:#long x, long y

    ret#div_t/ldiv_t (div/ldiv)
    
#TODO implement
.global lldiv
lldiv:#long long x, long long y
.global imaxdiv
imaxdiv:#intmax_t x, intmax_t y

    ret#lldiv_t/imaxdiv_t (lldiv/imaxdiv)
