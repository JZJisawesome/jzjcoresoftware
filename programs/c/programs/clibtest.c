#include <JZJCoreLib/io.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

void main()
{
    volatile double testd1 = 2, testd2 = 16;
    //PORT5 = (int)(pow(testd1, testd2));

    assert(PORT0 == 0);
    return;
}
