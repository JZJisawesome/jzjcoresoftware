#include "JZJCoreLib/io.h"

//Volatile so they are not calculated at compile time
volatile int a = 20;
volatile int b = 21;
volatile unsigned int ua = 420;
volatile unsigned int ub = 21;

void main()
{
    int result = a * b;//JZJCoreLib __mulsi3 function should return 420 (lol) which is 0x1a4 in hex
    PORT5 = result;
    
    a = 100;
    b = -100;
    result = a * b;//-10000 (0xffffd8f0 in hex)
    PORT5 = result;
    
    //Testing unsigned division too
    result = ua / ub;
    PORT5 = result;//Should return 20 (0x14)
    
    return;
}
