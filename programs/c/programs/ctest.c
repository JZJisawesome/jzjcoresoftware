
void main(void)
{
    asm volatile
    (
        "addi sp, x0, 2000"
    );
    
    int i;
    while (1)
    {
        i = i + 1;
    }
}
