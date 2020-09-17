#include <JZJCoreLib/io.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdnoreturn.h>
#include <errno.h>
#include <ctype.h>

void main()
{
    volatile double testd1 = 2, testd2 = 16;
    //PORT5 = (int)(pow(testd1, testd2));
    
    volatile int test1 = 2, test2 = -16;
    
    PORT5 = abs(test1);
    PORT5 = abs(test2);
    //PORT5 = div(test1, test2).quot;
    
    volatile char character = 'j';
    PORT5 = toupper(character);
    character = 'J';
    PORT5 = tolower(character);
    character = '!';
    PORT5 = tolower(character);

    assert(PORT0 == 0);
    assert(errno == 0);
    return;
}
