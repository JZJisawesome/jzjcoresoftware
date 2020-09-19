#ifndef STRING_H
#define STRING_H

#include <commondefs.h>

//String Manipulation
char* strcpy(char* restrict dest, const char* restrict src);
errno_t strcpy_s(char* restrict dest, rsize_t destsz, const char* restrict src);
char* strncpy(char* restrict dest, const char* restrict src, size_t count);//TODO
errno_t strncpy_s(char* restrict dest, rsize_t destsz, const char* restrict src, rsize_t count);//TODO
char* strncat(char* restrict dest, const char* restrict src, size_t count);//TODO
errno_t strncat_s(char* restrict dest, rsize_t destsz, const char* restrict src, rsize_t count);//TODO
size_t strxfrm(char* restrict dest, const char* restrict src, size_t count);//TODO

//String Examination
size_t strlen(const char* str);//TODO
size_t strnlen_s(const char* str, size_t strsz);//TODO
int strcmp(const char* lhs, const char* rhs);//TODO
int strncmp(const char* lhs, const char* rhs, size_t count);//TODO
int strcoll(const char* lhs, const char* rhs);//TODO
char* strchr(const char* str, int ch);//TODO
char* strrchr(const char* str, int ch);//TODO
size_t strspn(const char* dest, const char *src);//TODO
size_t strcspn(const char* dest, const char* src);//TODO
char* strpbrk(const char* dest, const char* breakset);//TODO
char* strstr(const char* str, const char* substr);//TODO
char* strtok(char* restrict str, const char* restrict delim);//TODO
char* strtok_s(char* restrict str, rsize_t* restrict strmax, const char* restrict delim, char** restrict ptr);//TODO

//Character Array/Memory Manipulation
void* memchr(const void* ptr, int ch, size_t count);//TODO
int memcmp(const void* lhs, const void* rhs, size_t count);//TODO
void* memset(void* dest, int ch, size_t count);
errno_t memset_s(void* dest, rsize_t destsz, int ch, rsize_t count);//TODO
void* memcpy(void* dest, const void* src, size_t count);
errno_t memcpy_s(void* restrict dest, rsize_t destsz, const void* restrict src, rsize_t count);//TODO
void* memmove(void* dest, const void* src, size_t count);//TODO
errno_t memmove_s(void* dest, rsize_t destsz, const void* src, rsize_t count);//TODO

//Errno to string functions
char* strerror(int errnum);//TODO
errno_t strerror_s(char* buf, rsize_t bufsz, errno_t errnum);//TODO
size_t strerrorlen_s(errno_t errnum);//TODO

#endif
