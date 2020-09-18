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

int state = 1;

//I'm using GTK wave to debug
//Output is PORT5
//So I know where things are, current stage is PORT6

void randTest();
void ctypeTest();

void main()
{
    /*
    PORT6 = state++;
    volatile double testd1 = 2, testd2 = 16;
    //PORT5 = (int)(pow(testd1, testd2));
    
    volatile int test1 = 2, test2 = -16;
    
    //TODO figure way around builtins to test these (maybe disable temporarily)
    PORT5 = abs(test1);
    PORT5 = abs(test2);
    PORT5 = labs(test1);
    PORT5 = labs(test2);
    PORT5 = llabs(test1);
    PORT5 = llabs(test2);
    //PORT5 = div(test1, test2).quot;
    */
    
    //TODO organize the above tests better
    
    /* More Organized Section */
    
    PORT6 = state++;
    randTest();
    
    PORT6 = state++;
    ctypeTest();

    assert(PORT0 == 0);
    assert(errno == 0);
    return;
}

void randTest()
{
    for (int i = 0; i < 10; ++i)
        PORT5 = rand();
}

void ctypeTest()
{
    //ctype.h
    volatile char character = 'j';
    PORT5 = toupper(character);//J (0x4A)
    character = 'J';
    PORT5 = tolower(character);//j (0x6A)
    character = '!';
    PORT5 = tolower(character);//! (0x21)
    PORT6 = state++;
    PORT5 = islower('z');//true
    PORT5 = islower('{');//false
    PORT5 = isupper('J');//true
    PORT5 = isupper('j');//false
    PORT5 = isgraph(' ');//false
    PORT5 = isgraph('a');//true
    PORT5 = isprint(' ');//true
    PORT5 = isprint(127);//false
    
    PORT6 = state++;
    
    PORT5 = iscntrl('a');//false
    PORT5 = iscntrl(127);//true
    PORT5 = iscntrl(31);// true
    PORT5 = iscntrl(' ');//false
    PORT5 = isalpha('j');//true
    PORT5 = isalpha('J');//true
    PORT5 = isalpha('7');//false
    PORT5 = isblank(' ');//true
    PORT5 = isblank('\t');//true
    PORT5 = isblank('\n');//false
    
    PORT6 = state++;
    
    PORT5 = isspace(' ');//true
    PORT5 = isspace('\t');//true
    PORT5 = isspace('\n');//true
    PORT5 = isalnum('j');//true
    PORT5 = isalnum('J');//true
    PORT5 = isalnum('7');//true
    PORT5 = isalnum('\t');//false
    
    PORT6 = state++;
    
    PORT5 = isxdigit('f');//true
    PORT5 = isxdigit('G');//false
    PORT5 = ispunct('\'');//true
    PORT5 = ispunct(')');//true
    PORT5 = ispunct(' ');//false
    
    PORT6 = state++;
}
