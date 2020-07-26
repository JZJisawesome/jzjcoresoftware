
void main(void)
{
    volatile int *portADirectionRegister = (int*)(0xFFFFFFE0);
    volatile int *portARegister = (int*)(0xFFFFFFF0);
    
    *portADirectionRegister = 0xFFFFFFF0;
    
    while (1)
    {
        *portARegister = (*portARegister) ^ 0x0000000F0;
    }
    
    return;
}
