//avr-libc implements this using a define to __builtin_alloca, so we might as well do it here too
//https://www.nongnu.org/avr-libc/user-manual/group__alloca.html
//Didn't actually copy the implementation, just their idea

#ifndef ALLOCA_H
#define ALLOCA_H

#define alloca __builtin_alloca

#endif
