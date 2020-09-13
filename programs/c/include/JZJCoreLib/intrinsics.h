//Macros for useful instructions not accessible from C/C++
#ifndef JZJCORELIB_INTRINSICS_H
#define JZJCORELIB_INTRINSICS_H

#ifdef JZJCORELIB_LONG_NAMES
    #define jzjcore_nop() (__asm__ __volatile__("nop"))
    #define jzjcore_jzjCoreHalt() (__asm__ __volatile__("ecall"))
#else
    #define nop() (__asm__ __volatile__("nop"))
    #define jzjCoreHalt() (__asm__ __volatile__("ecall"))
#endif 

#endif
