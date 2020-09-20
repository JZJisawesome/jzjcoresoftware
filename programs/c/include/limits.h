#ifndef LIMITS_H
#define LIMITS_H

//https://en.cppreference.com/w/c/types/limits
#define CHAR_BIT 8
#define CHAR_MIN 0
#define CHAR_MAX 0xFF

#define SCHAR_MIN 0x80
#define SHRT_MIN 0x8000
#define INT_MIN 0x80000000
#define LONG_MIN 0x80000000
#define LLONG_MIN 0x8000000000000000

#define SCHAR_MAX 0x7F
#define SHRT_MAX 0x7FFF
#define INT_MAX 0x7FFFFFFF
#define LONG_MAX 0x7FFFFFFF
#define LLONG_MAX 0x7FFFFFFFFFFFFFFF

#define UCHAR_MAX 0xFF
#define USHRT_MAX 0xFF
#define UINT_MAX 0xFFFFFFFF
#define ULONG_MAX 0xFFFFFFFF
#define ULLONG_MAX 0xFFFFFFFFFFFFFFFF

#endif
