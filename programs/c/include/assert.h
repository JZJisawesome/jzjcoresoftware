#ifndef ASSERT_H
#define ASSERT_H



#ifdef NDEBUG
    #define assert(condition) ((void)0)
#else//Halt cpu if assertion fails
    //asserts just does ecall instead of calling abort becasue abort would just call ecall anyways, so this is faster (this library will never support signals or handling the SIGABRT signal)
    #define assert(condition) \
        do \
        { \
            if (condition == 0) \
                __asm__ __volatile__ ("ecall"); \
        } while (0)
#endif

#define static_assert _Static_assert

#endif
