//Memory Mapped IO Port Pointer Macros
#ifndef JZJCORELIB_IO_H
#define JZJCORELIB_IO_H

#ifdef JZJCORELIB_LONG_NAMES
    #define JZJCORE_PORT0 (*(volatile int*)(0xFFFFFFE0))
    #define JZJCORE_PORT1 (*(volatile int*)(0xFFFFFFE4))
    #define JZJCORE_PORT2 (*(volatile int*)(0xFFFFFFE8))
    #define JZJCORE_PORT3 (*(volatile int*)(0xFFFFFFEC))
    #define JZJCORE_PORT4 (*(volatile int*)(0xFFFFFFF0))
    #define JZJCORE_PORT5 (*(volatile int*)(0xFFFFFFF4))
    #define JZJCORE_PORT6 (*(volatile int*)(0xFFFFFFF8))
    #define JZJCORE_PORT7 (*(volatile int*)(0xFFFFFFFC))
#else
    #define PORT0 (*(volatile int*)(0xFFFFFFE0))
    #define PORT1 (*(volatile int*)(0xFFFFFFE4))
    #define PORT2 (*(volatile int*)(0xFFFFFFE8))
    #define PORT3 (*(volatile int*)(0xFFFFFFEC))
    #define PORT4 (*(volatile int*)(0xFFFFFFF0))
    #define PORT5 (*(volatile int*)(0xFFFFFFF4))
    #define PORT6 (*(volatile int*)(0xFFFFFFF8))
    #define PORT7 (*(volatile int*)(0xFFFFFFFC))
#endif

#endif
