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

//TODO finish

//Signed
//Minimum
#define INT8_MIN -128
//#define INT16_MIN 
//#define INT32_MIN 
//#define INT64_MIN 

//#define INT_FAST8_MIN
//#define INT_FAST16_MIN 
//#define INT_FAST32_MIN 
//#define INT_FAST64_MIN 

#define INT_LEAST8_MIN -128
//#define INT_LEAST16_MIN 
//#define INT_LEAST32_MIN 
//#define INT_LEAST64_MIN 

//#define INTPTR_MIN 

//#define INTMAX_MIN 

//Maximum
#define INT8_MAX 127
//#define INT16_MAX 
//#define INT32_MAX 
//#define INT64_MAX 

//#define INT_FAST8_MAX
//#define INT_FAST16_MAX 
//#define INT_FAST32_MAX 
//#define INT_FAST64_MAX 

#define INT_LEAST8_MAX 127
//#define INT_LEAST16_MAX 
//#define INT_LEAST32_MAX 
//#define INT_LEAST64_MAX 

//#define INTPTR_MAX 

//#define INTMAX_MAX 

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
#define UINT8_MAX 255
//#define UINT16_MAX 
//#define UINT32_MAX 
//#define UINT64_MAX 

//#define UINT_FAST8_MAX
//#define UINT_FAST16_MAX 
//#define UINT_FAST32_MAX 
//#define UINT_FAST64_MAX 

#define UINT_LEAST8_MAX 255
//#define UINT_LEAST16_MAX 
//#define UINT_LEAST32_MAX 
//#define UINT_LEAST64_MAX 

//#define INTPTR_MAX 

//#define INTMAX_MAX 

/* Function Macros For Constants */

//TODO

#endif
