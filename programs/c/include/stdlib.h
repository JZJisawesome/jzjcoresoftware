#ifndef STDLIB_H
#define STDLIB_H

//TODO there are still lots left to implement here

//Dynamic Memory Management
//TODO test if these actually work and make them work
#define malloc __builtin_malloc
#define calloc __builtin_calloc
#define realloc __builtin_realloc
#define free __builtin_free
//#define aligned_alloc //TODO

/* Program Utilities*/
//Program Termination
//TODO these might have to be functions rather than macros; check if that is the case
#define abort() (__asm__ __volatile__("ecall"))//For JZJCore, the ecall and ebreak instructions halt the cpu//TODO handle SIGABRT signal handler
//#define exit//TODO will need to shut things down cleanly
//#define quick_exit//TODO will need to shut things down cleanly
#define _Exit(exit_code) (__asm__ __volatile__("ecall"))//For JZJCore, the ecall and ebreak instructions halt the cpu
//#define atexit
//#define at_quick_exit

//Environment Communication
//The values of these don't matter because this is a bare metal environment
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/* String Functions */
//Null Terminated String Parsing
//TODO

//Null Terminated Multibyte String Functions
//TODO

//Null Terminated Wide String Typedef And Macros
typedef signed int wchar_t;
#define WCHAR_MIN 0x80000000
#define WCHAR_MAX 0x7FFFFFFF

/* Pseudo-Random Number Generation */
int rand();//Not Implemented
void srand(unsigned seed);//Not Implemented
#define RAND_MAX 0x7FFFFFFF

#endif
