volatile int *port5Register = (int*)(0xFFFFFFF4);
volatile int a = 20;
volatile int b = 21;

void main()
{
    *port5Register = a * b;//JZJCoreLib __mulsi3 function should return 420 (lol)
    return;
}

/*
int __mulsi3(int a, int b)
{
    int temp = 0;
    
    for (int i = 0; i < b; ++i)
        temp += a;
    
    return temp;
}
*/
