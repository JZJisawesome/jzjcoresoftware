//MIT licensed
//Provides gcc arithmetic functions as well as some nice other ones

//Note: This is a c header; the include for this may need to be wrapped in a extern "C" {} if being used from C++
#ifndef JZJCORELIB_H
#define JZJCORELIB_H

//JZJCoreLib Custom Functions and Macros

//Instruction Macros
#ifdef JZJCORELIB_LONG_NAMES
    #define jzjcore_nop() (__asm__ __volatile__("nop"))
    #define jzjcore_jzjCoreHalt() (__asm__ __volatile__("ecall"))
#else
    #define nop() (__asm__ __volatile__("nop"))
    #define jzjCoreHalt() (__asm__ __volatile__("ecall"))
#endif

//Memory Mapped IO Port Pointer Macros
#ifdef JZJCORELIB_LONG_NAMES
    #define JZJCORE_PORT0 (*(volatile int*)(0xFFFFFFE0))
    #define JZJCORE_PORT1 (*(volatile int*)(0xFFFFFFE4))
    #define JZJCORE_PORT2 (*(volatile int*)(0xFFFFFFE8))
    #define JZJCORE_PORT3 (*(volatile int*)(0xFFFFFFEC))
    #define JZJCORE_PORT4 (*(volatile int*)(0xFFFFFFF0))
    #define JZJCORE_PORT5 (*(volatile int*)(0xFFFFFFF4))
    #define JZJCORE_PORT6 (*(volatile int*)(0xFFFFFFF8))
    #define JZJCORE_PORT7 (*(volatile int*)(0xFFFFFFFC))
#else
    #define PORT0 (*(volatile int*)(0xFFFFFFE0))
    #define PORT1 (*(volatile int*)(0xFFFFFFE4))
    #define PORT2 (*(volatile int*)(0xFFFFFFE8))
    #define PORT3 (*(volatile int*)(0xFFFFFFEC))
    #define PORT4 (*(volatile int*)(0xFFFFFFF0))
    #define PORT5 (*(volatile int*)(0xFFFFFFF4))
    #define PORT6 (*(volatile int*)(0xFFFFFFF8))
    #define PORT7 (*(volatile int*)(0xFFFFFFFC))
#endif

//todo

//GCC Integer Routines
extern int __divsi3(int a, int b);//Not implemented
extern long __divdi3(long a, long b);//Not implemented
extern long long __divti3(long long a, long long b);//Not implemented

extern int __modsi3(int a, int b);//Not implemented
extern long __moddi3(long a, long b);//Not implemented
extern long long __modti3(long long a, long long b);//Not implemented

extern int __mulsi3(int a, int b);
extern long __muldi3(long a, long b);
extern long long __multi3(long long a, long long b);//Not implemented

extern unsigned int __udivsi3(unsigned int a, unsigned int b);//Not implemented
extern unsigned long __udivdi3(unsigned long a, unsigned long b);//Not implemented
extern unsigned long long __udivti3(unsigned long long a, unsigned long long b);//Not implemented

extern int __umodsi3(unsigned int a, unsigned int b);//Not implemented
extern unsigned long __umoddi3(unsigned long a, unsigned long b);//Not implemented
extern unsigned long long __umodti3(unsigned long long a, unsigned long long b);//Not implemented

#endif
