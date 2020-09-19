#ifndef STRING_H
#define STRING_H

//TODO lots of definitions left here

//Type definitions also in other headers
typedef unsigned int size_t;//TODO ensure this is right

//String manipulation
char* strcpy(char* dest, const char* src);

//Character array manipulation
void* memset(void* dest, int ch, size_t count);
void* memcpy(void* dest, const void* src, size_t count);

#endif
