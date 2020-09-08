volatile int *port5Register = (int*)(0xFFFFFFF4);
volatile int a = 20;//Volatile so it is not done at compile time
volatile int b = 21;//Volatile so it is not done at compile time

void main()
{
    *port5Register = a * b;//JZJCoreLib __mulsi3 function should return 420 (lol)
    return;
}
