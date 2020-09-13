#ifndef STDLIB_H
#define STDLIB_H

//TODO there are still some left to implement here
#define abort() (__asm__ __volatile__("ecall"))//For JZJCore, the ecall and ebreak instructions halt the cpu//TODO handle SIGABRT handler
#define _Exit(exit_code) (__asm__ __volatile__("ecall"))//For JZJCore, the ecall and ebreak instructions halt the cpu 

#endif
