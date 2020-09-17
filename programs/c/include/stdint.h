#ifndef STDINT_H
#define STDINT_H

/* Types (RV32) */

//Signed
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;

typedef signed int int_fast8_t;//TODO ensure int actually is the fastest
typedef signed int int_fast16_t;//TODO ensure int actually is the fastest
typedef signed int int_fast32_t;
typedef signed long long int_fast64_t;

typedef signed char int_least8_t;
typedef signed short int_least6_t;
typedef signed int int_least2_t;
typedef signed long long int_least64_t;

typedef signed long long intmax_t;

typedef signed int* intptr_t;

//Unsigned
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef unsigned int uint_fast8_t;//TODO ensure int actually is the fastest
typedef unsigned int uint_fast16_t;//TODO ensure int actually is the fastest
typedef unsigned int uint_fast32_t;
typedef unsigned long long uint_fast64_t;

typedef unsigned char uint_least8_t;
typedef unsigned short uint_least6_t;
typedef unsigned int uint_least2_t;
typedef unsigned long long uint_least64_t;

typedef unsigned long long uintmax_t;

typedef unsigned int* uintptr_t;

/* Macro Constants */

//Signed
//Minimum
#define INT8_MIN 0x80
#define INT16_MIN 0x8000
#define INT32_MIN 0x80000000
#define INT64_MIN 0x8000000000000000

#define INT_FAST8_MIN 0x80000000//TODO ensure int actually is the fastest
#define INT_FAST16_MIN 0x80000000//TODO ensure int actually is the fastest
#define INT_FAST32_MIN 0x80000000
#define INT_FAST64_MIN 0x8000000000000000

#define INT_LEAST8_MIN 0x80
#define INT_LEAST16_MIN 0x8000
#define INT_LEAST32_MIN 0x80000000
#define INT_LEAST64_MIN 0x8000000000000000

#define INTPTR_MIN 0x80000000

#define INTMAX_MIN 0x8000000000000000

//Maximum
#define INT8_MAX 0x7F
#define INT16_MAX 0x7FFF
#define INT32_MAX 0x7FFFFFFF
#define INT64_MAX 0x7FFFFFFFFFFFFFFF

#define INT_FAST8_MAX 0x7FFFFFFF//TODO ensure int actually is the fastest
#define INT_FAST16_MAX 0x7FFFFFFF//TODO ensure int actually is the fastest
#define INT_FAST32_MAX 0x7FFFFFFF
#define INT_FAST64_MAX 0x7FFFFFFFFFFFFFFF

#define INT_LEAST8_MAX 0x7F
#define INT_LEAST16_MAX 0x7FFF
#define INT_LEAST32_MAX 0x7FFFFFFF
#define INT_LEAST64_MAX 0x7FFFFFFFFFFFFFFF

#define INTPTR_MAX 0x7FFFFFFF

#define INTMAX_MAX 0x7FFFFFFFFFFFFFFF

//Unsigned
//Minimum
#define UINT8_MIN 0
#define UINT16_MIN 0
#define UINT32_MIN 0
#define UINT64_MIN 0

#define UINT_FAST8_MIN 0
#define UINT_FAST16_MIN 0
#define UINT_FAST32_MIN 0
#define UINT_FAST64_MIN 0

#define UINT_LEAST8_MIN 0
#define UINT_LEAST16_MIN 0
#define UINT_LEAST32_MIN 0
#define UINT_LEAST64_MIN 0

#define UINTPTR_MIN 0

#define UINTMAX_MIN 0

//Maximum
#define UINT8_MAX 0xFF
#define UINT16_MAX 0xFFFF
#define UINT32_MAX 0xFFFFFFFF
#define UINT64_MAX 0xFFFFFFFFFFFFFFFF

#define UINT_FAST8_MAX 0xFFFFFFFF//TODO ensure int actually is the fastest
#define UINT_FAST16_MAX 0xFFFFFFFF//TODO ensure int actually is the fastest
#define UINT_FAST32_MAX 0xFFFFFFFF
#define UINT_FAST64_MAX 0xFFFFFFFFFFFFFFFF

#define UINT_LEAST8_MAX 0xFF
#define UINT_LEAST16_MAX 0xFFFF
#define UINT_LEAST32_MAX 0xFFFFFFFF
#define UINT_LEAST64_MAX 0xFFFFFFFFFFFFFFFF

#define UINTPTR_MAX 0xFFFFFFFF

#define UINTMAX_MAX 0xFFFFFFFFFFFFFFFF

/* Function Macros For Constants */

//Useful for figuring out I can just cast: https://www.nongnu.org/avr-libc/user-manual/group__avr__stdint.html

//Signed
#define INT8_C(constant) (int_least8_t)(constant)
#define INT16_C(constant) (int_least16_t)(constant)
#define INT32_C(constant) (int_least32_t)(constant)
#define INT64_C(constant) (int_least64_t)(constant)

#define INTMAX_C(constant) (intmax_t)(constant)

//Unsigned
#define UINT8_C(constant) (uint_least8_t)(constant)
#define UINT16_C(constant) (uint_least16_t)(constant)
#define UINT32_C(constant) (uint_least32_t)(constant)
#define UINT64_C(constant) (uint_least64_t)(constant)

#define UINTMAX_C(constant) (uintmax_t)(constant)

/* Other Numeric Limits */

#define PTRDIFF_MIN 0x80000000
#define PTRDIFF_MAX 0x7FFFFFFF
#define SIZE_MAX 0xFFFFFFFF
//#define SIG_ATOMIC_MIN//TODO
//#define SIG_ATOMIC_MAX//TODO
#define WINT_MIN 0x00000000
#define WINT_MAX 0xFFFFFFFF

#endif
