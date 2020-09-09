#include "JZJCoreLib.h"

volatile int a = 20;//Volatile so it is not done at compile time
volatile int b = 21;//Volatile so it is not done at compile time
volatile unsigned int ua = 420;//Volatile so it is not done at compile time
volatile unsigned int ub = 21;//Volatile so it is not done at compile time

void main()
{
    int result = a * b;//JZJCoreLib __mulsi3 function should return 420 (lol) which is 0x1a4 in hex
    PORT5 = result;
    
    a = 100;
    b = -100;
    result = a * b;//-10000 (0xffffd8f0 in hex)
    PORT5 = result;
    
    //Testing unsigned division too
    volatile unsigned int ua = 420;
    result = ua / ub;
    PORT5 = result;//Should return 20 (0x14)
    
    return;
}
