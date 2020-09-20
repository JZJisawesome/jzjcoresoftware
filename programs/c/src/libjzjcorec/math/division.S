#Software integer division routines for stdlib.h
#Depends on libgcc to do the heavy lifting
#TODO actually, just implement division yourself (take from old code folder) instead of depending on libgcc; could be faster (but more complex and take up more room)
.text

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
