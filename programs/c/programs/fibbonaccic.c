#include "JZJCoreLib/io.h"

void main(void)
{
    //Term n - 2, n -1, and n
    int x = 0, y = 1, z;
    
    PORT5 = x;//Display term 0
    PORT5 = y;//Display term 1
    
    while (1)
    {
        //Calculate next term
        z = x + y;
        
        //Shift terms back
        x = y;
        y = z;
        
        //Update contents of mmio register
        PORT5 = z;
    }
}
 
