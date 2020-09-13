//Macros for useful instructions not accessible from C/C++
#ifndef JZJCORELIB_INTRINSICS_H
#define JZJCORELIB_INTRINSICS_H

#define __nop() (__asm__ __volatile__("nop"))
#define __halt() (__asm__ __volatile__("ecall"))

//Instruction that are less useful but still here in case
#define __fence() (__asm__ __volatile__("fence"))
#define __ecall() (__asm__ __volatile__("ecall"))
#define __ebreak() (__asm__ __volatile__("ebreak"))

#endif
