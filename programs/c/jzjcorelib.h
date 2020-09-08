//MIT licensed
//Provides gcc arithmetic functions as well as some nice other ones

//Note: This is a c header; the include for this may need to be wrapped in a extern "C" {} if being used from C++
#ifndef JZJCORELIB_H
#define JZJCORELIB_H

//JZJCoreLib custom functions

//Needed by gcc
extern int __mulsi3(int a, int b);
extern long __muldi3(long a, long b);
extern long long __multi3(long a, long b);//Not implemented

#endif
