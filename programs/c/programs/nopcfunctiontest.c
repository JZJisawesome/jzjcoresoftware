//#include "../crt0.h"
void nop();

void main(void)
{
    int *portADirectionRegister = (int*)(0xFFFFFFE0);
    int *portARegister = (int*)(0xFFFFFFF0);
    
    *portADirectionRegister = 0xFFFFFFF0;
    
    while (1)
    {
        *portARegister = (*portARegister) ^ 0x0000000F0;
        nop();
        nop();
        nop();
        nop();
    }
    
    return;
}

