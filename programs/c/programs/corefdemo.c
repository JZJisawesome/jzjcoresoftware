#include "JZJCoreLib/io.h"

//Must only contain the characters 0 - 9 and a - f
int convertCharTo4Bit(char character)
{
    if (character < ':')//Numbers
        return (char)(character - 48);
    else if (character < '[')//Capital letters
        return (char)(character - 55);
    else//Lowercase letters
        return (char)(character - 87);
}

//Must be 8 elements and only contain the characters 0 - 9 and a - f (effectively converts a char to a 4 bit value, usefull for 7 seg displays)
int convertStringToWord(const char string[8])
{
    int temp = 0;
    
    char amountToShiftBy = 0;
    for (int i = 7; i >= 0; --i)//Last character in string should be least significant in the hex word
    {
        temp |= convertCharTo4Bit(string[i]) << amountToShiftBy;
        amountToShiftBy += 4;
    }
    
    return temp;
}

//Main (called after _start)
void main()
{
    //We could just use 0x notation, but where's the fun in that?
    PORT5 = convertStringToWord("123c0f32");//"123 CoreF 32"
    PORT5 = convertStringToWord("123abcde");
    PORT5 = convertStringToWord("deadbeef");
    
    //Shift ones in from the right, then shift zeroes in to clear the ones (a fun pattern)
    for (int i = 0; i < 10; ++i)
    {
        signed int temp = 0x80000000;//Set the top bit
        PORT5 = 0x80000000;
        for (int j = 0; j < 31; ++j)//Shift in ones
        {
            temp = temp >> 1;//Arithmetic shift
            PORT5 = temp;
        }
        
        temp = 0x7fffffff;//Zero the top bit
        PORT5 = 0x7fffffff;
        for (int j = 0; j < 31; ++j)//Shift in zeroes
        {
            temp = temp >> 1;//It no longer matters if this is a logical or arithmetic shift
            PORT5 = temp;
        }
    }
    
    /*
    Todo need to implement arithmetic functions (I think I will save this for another test program)
    //Now for some intense stuff
    volatile int x = 20, y = 21;
    PORT5 = x * y;//lol
    
    x = 10;
    y = 10;
    PORT5 = x^y;//This will take forever
    
    x = 9999;
    y = 9;
    PORT5 = x / y;//So will this
    
    volatile short xFloat = 1.5;
    y = 100;
    PORT5 = (int)(xFloat*y);//So will this
    */
    
    PORT5 = convertStringToWord("123c0f32");//"123 CoreF 32"
    
    return;
}
