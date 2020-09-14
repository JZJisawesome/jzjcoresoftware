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
//#define atexit//TODO
//#define at_quick_exit//TODO

//Environment Communication
//The values of these don't matter because this is a bare metal environment
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/* String Functions */

//Null Terminated String Parsing
//TODO implement
double atof(const char* str);
int atoi(const char* str);
long atol(const char* str);
long long atoll(const char* str);
long strtol(const char* restrict str, char** str_end, int base);
long long strtoll(const char* restrict str, char** restrict str_end, int base);
unsigned long strtoul(const char* restrict str, char** restrict str_end, int base);
unsigned long long strtoull(const char* restrict str, char** restrict str_end, int base);
float strtof(const char* restrict str, char** restrict str_end);
double strtod(const char* restrict str, char** restrict str_end);
long double strtold(const char* restrict str, char** restrict str_end);

//Null Terminated Multibyte String Functions
//TODO include needed headers for size_t and errno_t
//TODO implement
int mblen(const char* s, size_t n);
int mbtowc(wchar_t* restrict pwc, const char* restrict s, size_t n);
int wctomb(char* s, wchar_t wc);
//errno_t wctomb_s(int* restrict status, char* restrict s, rsize_t ssz, wchar_t wc);
//size_t mbstowcs(wchar_t* restrict dst, const char* restrict src, size_t len);
//errno_t mbstowcs_s(size_t* restrict retval, wchar_t* restrict dst, rsize_t dstsz, const char* restrict src, rsize_t len);
//size_t wcstombs(char* dst, const wchar_t* src, size_t len);
//errno_t wcstombs_s(size_t* restrict retval, char* restrict dst, rsize_t dstsz, const wchar_t* restrict src, rsize_t len);

//Null Terminated Wide String Typedef And Macros
typedef signed int wchar_t;
#define WCHAR_MIN 0x80000000
#define WCHAR_MAX 0x7FFFFFFF

/* Pseudo-Random Number Generation */
int rand();//TODO
void srand(unsigned seed);//TODO
#define RAND_MAX 0x7FFFFFFF

#endif
