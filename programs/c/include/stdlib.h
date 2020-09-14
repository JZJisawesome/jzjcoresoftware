#ifndef STDLIB_H
#define STDLIB_H

//TODO there are still lots left to implement here (cppreference is not supper organized on a per header basis)

//Dynamic Memory Management
//TODO include needed headers for size_t
//TODO test if these actually work and make them work
//void* malloc(size_t size);//TODO
//void* calloc(size_t num, size_t size);//TODO
//void* realloc(void* ptr, size_t new_size);//TODO
void free(void* ptr);//TODO
//void* aligned_alloc(size_t alignment, size_t size);//TODO

/* Program Utilities*/
//Program Termination
//TODO these have to be functions rather than macros; fix that
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
//TODO include needed headers for size_t and errno_t

//Null Terminated Wide String Typedef And Macros
typedef signed int wchar_t;
#define WCHAR_MIN 0x80000000
#define WCHAR_MAX 0x7FFFFFFF

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

//TODO implement
//int mblen(const char* s, size_t n);
//int mbtowc(wchar_t* restrict pwc, const char* restrict s, size_t n);
int wctomb(char* s, wchar_t wc);
//errno_t wctomb_s(int* restrict status, char* restrict s, rsize_t ssz, wchar_t wc);
//size_t mbstowcs(wchar_t* restrict dst, const char* restrict src, size_t len);
//errno_t mbstowcs_s(size_t* restrict retval, wchar_t* restrict dst, rsize_t dstsz, const char* restrict src, rsize_t len);
//size_t wcstombs(char* dst, const wchar_t* src, size_t len);
//errno_t wcstombs_s(size_t* restrict retval, char* restrict dst, rsize_t dstsz, const wchar_t* restrict src, rsize_t len);

/* Pseudo-Random Number Generation */
int rand();//TODO
void srand(unsigned seed);//TODO
#define RAND_MAX 0x7FFFFFFF

/* Math Stuff */

//Absolute functions
int abs(int n);//TODO
long labs(long n);//TODO
long long llabs(long long n);//TODO

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
