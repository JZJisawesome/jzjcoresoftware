//Implements complicated string functions for the following c headers
#include <string.h>
#include <stdlib.h>

//Other headers (used to implement some functions)
#include <stdint.h>

//TODO lots left to implement

/* Inline Functions */
//Much faster than having to call ctype.h functions

inline static int isspace_inline(int ch)
{
    return (ch == ' ') || (ch == '\t');
}

inline static int isdigit_inline(int ch)
{
    return (ch - '0') < 10;//Digits 0 to 9
}

/* Parsing Functions For stdlib.h */

//TODO lots left to implement

//I came up with other ideas (including checking if characters are digits and parsing them in the same loop) myself
int atoi(const char* str)//TODO make faster//TODO support sign before number
{
    //Get rid of leading whitespace
    while (isspace_inline(str[0]))
        ++str;//Shift the position of the string to access
        
    //str[0] now points to the first non-whitespace character
    //We parse 1 digit at a time from this point on until we run out of digits
    int returnValue = 0;//Default value if numberLength == 0
    
    //Idea of multiplying by 10 each time rather than needing an exponent function, using a char instead of an int literal
    //for parsing (more readable), and idea to parse without determining the length of the digits in str first
    //thanks to: https://www.geeksforgeeks.org/write-your-own-atoi/
    while (isdigit_inline(str[0]))
    {
        //Multiply existing decimal digits in returnValue by 10 to shift them left
        //Shifting _decimal_ places left rather than bits after each addition of a digit
        returnValue *= 10;//The compiler will translate this to (returnValue << 3) + (returnValue << 1)
        
        int parsedCharacterValue = str[0] - '0';//Parse digit to a number
        returnValue += parsedCharacterValue;//Add the next decimal digit to the value to be returned
        
        ++str;//Go to the next character
    }
    
    return returnValue;
}

//long is the same as int for RV32I
long atol(const char* str) __attribute__ ((alias("atoi")));

/* Manipulation and Comparison Functions For string.h */

//TODO lots left to implement

/* Errno To String Functions For string.h */

char* strerror(int errnum)
{
    return "An error occured";//No custom string
}
