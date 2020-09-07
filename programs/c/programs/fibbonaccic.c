volatile int *port5Register = (int*)(0xFFFFFFF4);

void main(void)
{
    //Term n - 2, n -1, and n
    int x = 0, y = 1, z;
    
    *port5Register = x;//Display term 0
    *port5Register = y;//Display term 1
    
    while (1)
    {
        //Calculate next term
        z = x + y;
        
        //Shift terms back
        x = y;
        y = z;
        
        //Update contents of mmio register
        *port5Register = z;
    }
    
    return;
}
 
