//MIT licensed
//Provides gcc arithmetic functions as well as some nice other ones

//Note: This is a c header; the include for this may need to be wrapped in a extern "C" {} if being used from C++
#ifndef JZJCORELIB_H
#define JZJCORELIB_H

//JZJCoreLib custom functions

//todo

//GCC Integer Routines
extern int __divsi3(int a, int b);//Not implemented
extern long __divdi3(long a, long b);//Not implemented
extern long long __divti3(long long a, long long b);//Not implemented

extern __modsi3(int a, int b);//Not implemented
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
