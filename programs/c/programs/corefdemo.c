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

//These are the same thing
volatile int *port5Register = (int*)(0xFFFFFFF4);
//#define PORT5 *(int*)(0xFFFFFFF4)//todo figure out how to make this volatile

//Main (called after _start)
void main()
{
    *port5Register = convertStringToWord("123c0f32");//"123 CoreF 32"
    
    //Shift ones in from the right, then shift zeroes in to clear the ones (a fun pattern)
    signed int temp = 0x80000000;//Set the top bit
    *port5Register = 0x80000000;
    for (int i = 0; i < 31; ++i)//Shift in ones
    {
        temp = temp >> 1;//Arithmetic shift
        *port5Register = temp;
    }
    
    temp = 0x7fffffff;//Zero the top bit
    *port5Register = 0x7fffffff;
    for (int i = 0; i < 31; ++i)//Shift in zeroes
    {
        temp = temp >> 1;//It no longer matters if this is a logical or arithmetic shift
        *port5Register = temp;
    }
    
    /*Todo need to implement arithmetic functions (I think I will save this for another test program)
    //Now for some intense stuff
    volatile int x = 20, y = 21;
    *port5Register = x * y;//lol
    
    x = 10;
    y = 10;
    *port5Register = x^y;//This will take forever
    
    x = 9999;
    y = 9;
    *port5Register = x / y;//So will this
    
    volatile short xFloat = 1.5;
    y = 100;
    *port5Register = (int)(xFloat*y);//So will this
    */
    
    *port5Register = 0x123c0f32;//"123 CoreF 32"
    
    return;
}
