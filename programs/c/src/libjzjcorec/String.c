//Implements complicated string functions for the following c headers
#include <string.h>
#include <stdlib.h>

//Other headers (used to implement some functions)
#include <ctype.h>
#include <stdint.h>

//TODO lots left to implement

/* Parsing Functions For stdlib.h */

//TODO lots left to implement

int atoi(const char* str)//TODO make faster
{
    while (isspace(str[0]))
        ++str;//Get rid of leading whitespace
        
    //str[0] now points to the first non-whitespace character
    if (isdigit(str[0]))//Check if there is a number to parse
    {
        uint8_t numbersOfDigit[10];
        
        //TODO
    }
    else
        return 0;//Not a number
}

/* Manipulation and Comparison Functions For string.h */

//TODO lots left to implement
