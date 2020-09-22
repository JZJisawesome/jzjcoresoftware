#ifndef STRING_H
#define STRING_H

#include <commondefs.h>

//String Manipulation
char* strcpy(char* restrict dest, const char* restrict src);
char* strncpy(char* restrict dest, const char* restrict src, size_t count);//TODO string.S
char* strncat(char* restrict dest, const char* restrict src, size_t count);//TODO string.S
size_t strxfrm(char* restrict dest, const char* restrict src, size_t count);

//String Examination
size_t strlen(const char* str);
int strcmp(const char* lhs, const char* rhs);//TODO String.c
int strncmp(const char* lhs, const char* rhs, size_t count);//TODO String.c
int strcoll(const char* lhs, const char* rhs);//TODO String.c (same implementation as strcmp probably)
char* strchr(const char* str, int ch);//TODO string.S
char* strrchr(const char* str, int ch);//TODO string.S
size_t strspn(const char* dest, const char *src);//TODO String.c
size_t strcspn(const char* dest, const char* src);//TODO String.c
char* strpbrk(const char* dest, const char* breakset);//TODO String.c
char* strstr(const char* str, const char* substr);//TODO String.c
char* strtok(char* restrict str, const char* restrict delim);//TODO String.c

//Character Array/Memory Manipulation
void* memchr(const void* ptr, int ch, size_t count);//TODO string.S
int memcmp(const void* lhs, const void* rhs, size_t count);//TODO String.c
void* memset(void* dest, int ch, size_t count);
void* memcpy(void* dest, const void* src, size_t count);
void* memmove(void* dest, const void* src, size_t count);//TODO String.c

//Errno to string functions
char* strerror(int errnum);

#endif
