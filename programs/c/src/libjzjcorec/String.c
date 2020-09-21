//Implements complicated string functions for the following c headers
#include <string.h>
#include <stdlib.h>

//Other headers (used to implement some functions)
#include <ctype.h>
#include <stdint.h>

//TODO lots left to implement

/* Parsing Functions For stdlib.h */

//TODO lots left to implement

//Idea of multiplying by 10 each time rather than an exponent function, using a char instead of an int literal for parsing (more readable), and reminder to stop if null is encountered thanks to: https://www.geeksforgeeks.org/write-your-own-atoi/
int atoi(const char* str)//TODO make faster
{
    //Get rid of leading whitespace
    while (isspace(str[0]))
        ++str;//Shift the position of the string to access
        
    //str[0] now points to the first non-whitespace character
    //Now we must find the number of characters the digit makes up
    uint_fast8_t numberLength = 0;//Maximum of 10 decimal digits fit in an int
    while (isdigit(str[numberLength]))//Stop if we run out of digits
        ++numberLength;//Add 1 for each digit we find
        
    //Now we now the length of digits to parse and the starting position (numberLength and str[0])
    int returnValue = 0;//Default value if numberLength == 0
    
    for(uint_fast8_t i = 0; i < numberLength; ++i)//Count up to numberLength to parse each character
    {
        //Multiply existing decimal digits in returnValue by 10
        //Effectively shifting decimal places left rather than bits after each addition of a digit
        int returnValueTimesTwo = returnValue << 1;
        returnValue <<= 3;//Multiply returnValue by 8
        returnValue += returnValueTimesTwo;//Add returnValue to itself 2 more times to effectively multiply by 10
        
        int parsedCharacterValue = str[i] - '0';//Parse digit to a number
        returnValue += parsedCharacterValue;//Add the next decimal digit to the value to be returned
    }
    
    return returnValue;
}

/* Manipulation and Comparison Functions For string.h */

//TODO lots left to implement
