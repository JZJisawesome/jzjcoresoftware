#ifndef STDLIB_H
#define STDLIB_H

#include <commondefs.h>

//TODO there are still lots left to implement here (cppreference is not supper organized on a per header basis)
//Note: I will not be implementing unicode/wide character strings

//Dynamic Memory Management
//TODO implement these (will be very difficult)
void* malloc(size_t size);//TODO
void* calloc(size_t num, size_t size);//TODO
void* realloc(void* ptr, size_t new_size);//TODO
void free(void* ptr);//TODO
void* aligned_alloc(size_t alignment, size_t size);//TODO

/* Program Utilities */
//Program Termination
_Noreturn void abort(void);
_Noreturn void exit(int exit_code);//TODO will need to shut things down cleanly
_Noreturn void quick_exit(int exit_code);//TODO will need to shut things down cleanly
_Noreturn void _Exit(int exit_code);
int atexit(void (*func)(void));//TODO
int at_quick_exit(void (*func)(void));//TODO

//Environment Communication
//The values of these don't matter because this is a bare metal environment
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 0//Using 0 for both might allow the compiler to use x0 instead of needing a li instruction

/* String Functions */

//Null Terminated String Parsing
double atof(const char* str);//TODO
int atoi(const char* str);//TODO
long atol(const char* str);//TODO
long long atoll(const char* str);//TODO
long strtol(const char* restrict str, char** str_end, int base);//TODO
long long strtoll(const char* restrict str, char** restrict str_end, int base);//TODO
unsigned long strtoul(const char* restrict str, char** restrict str_end, int base);//TODO
unsigned long long strtoull(const char* restrict str, char** restrict str_end, int base);//TODO
float strtof(const char* restrict str, char** restrict str_end);//TODO
double strtod(const char* restrict str, char** restrict str_end);//TODO
long double strtold(const char* restrict str, char** restrict str_end);//TODO

/* Pseudo-Random Number Generation */
int rand();
void srand(unsigned seed);
#define RAND_MAX 0x7FFFFFFF

/* Math Stuff */

//Absolute functions
int abs(int n);
long labs(long n);
long long llabs(long long n);

//Division structs
typedef struct
{
    int quot;
    int rem;
} div_t;

typedef struct
{
    long quot;
    long rem;
} ldiv_t;

typedef struct
{
    long long quot;
    long long rem;
} lldiv_t;

//Division functions
div_t div(int x, int y);//TODO
ldiv_t ldiv(long x, long y);//TODO
lldiv_t lldiv(long long x, long long y);//TODO

#endif
