//If you want to call emulation routines explicitly rather than letting the compile substitute things, use this header
//Requires linking with JZJCoreLib.S

#ifndef JZJCORELIB_EMULATION_H
#define JZJCORELIB_EMULATION_H

/* GCC Integer Routines */

//Arithmetic functions
extern long long __ashlti3(long long a, int b);//Not implemented

long long __ashrti3 (long long a, int b);//Not implemented

extern int __divsi3(int a, int b);//Not implemented
extern long __divdi3(long a, long b);//Not implemented
extern long long __divti3(long long a, long long b);//Not implemented

extern int __modsi3(int a, int b);//Not implemented
extern long __moddi3(long a, long b);//Not implemented
extern long long __modti3(long long a, long long b);//Not implemented

extern int __mulsi3(int a, int b);
extern long __muldi3(long a, long b);
extern long long __multi3(long long a, long long b);//Not implemented

extern long long __negti2(long long a);//Not implemented

extern unsigned int __udivsi3(unsigned int a, unsigned int b);
extern unsigned long __udivdi3(unsigned long a, unsigned long b);
extern unsigned long long __udivti3(unsigned long long a, unsigned long long b);//Not implemented

extern int __umodsi3(unsigned int a, unsigned int b);
extern unsigned long __umoddi3(unsigned long a, unsigned long b);
extern unsigned long long __umodti3(unsigned long long a, unsigned long long b);//Not implemented

//Comparison functions
//TODO

//Trapping arithmetic functions
//TODO

//Bit operations
//TODO

/* GCC Floating Point Routines */
//TODO

#endif
