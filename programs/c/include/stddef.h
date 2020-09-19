#ifndef STDDEF_H
#define STDDEF_H

#include <commondefs.h>

typedef signed int* ptrdiff_t;
#define NULL 0
typedef long double max_align_t;
#define offsetof(st, m) __builtin_offsetof(st, m)//Thank you https://en.wikipedia.org/wiki/Offsetof for showing how to use gcc's builtin
typedef unsigned short wchar_t;

#endif
