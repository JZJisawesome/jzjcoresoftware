#ifndef ASSERT_H
#define ASSERT_H

#ifdef NDEBUG
    #define assert(condition) ((void)0)
#else//Halt cpu if assertion fails
    #define assert(condition) \
        do \
        { \
            if ((condition) == 0) \
                __asm__ __volatile__("ecall"); \
        } while (0)
#endif

//TODO implement static_assert

#endif
