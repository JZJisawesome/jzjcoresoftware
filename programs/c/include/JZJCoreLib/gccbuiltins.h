//Redefines GCC builtin functions with their regular name to make code more readable
//TODO these should probably be moved to their respective proper c headers
#ifndef JZJCORELIB_GCCBUILTINS_H
#define JZJCORELIB_GCCBUILTINS_H

#define memcmp __builtin_memcmp

#endif
