volatile int *port5Register = (int*)(0xFFFFFFF4);
volatile int a = 20;//Volatile so it is not done at compile time
volatile int b = 21;//Volatile so it is not done at compile time
volatile unsigned int ua = 420;//Volatile so it is not done at compile time
volatile unsigned int ub = 21;//Volatile so it is not done at compile time

void main()
{
    int result = a * b;//JZJCoreLib __mulsi3 function should return 420 (lol)
    *port5Register = result;
    
    a = 100;
    b = -100;
    result = a * b;//-10000
    *port5Register = result;
    
    //Testing unsigned division too
    volatile unsigned int ua = 420;
    result = ua / ub;
    *port5Register = result;
    
    return;
}
