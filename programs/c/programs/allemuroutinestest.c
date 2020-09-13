#include "JZJCoreLib/io.h"
#include "JZJCoreLib/emulation.h"

//TODO call emulation routines directly to ensure they are used

//This file is used to test JZJCoreLib integer and floating point emulation routines
void main()
{
    //Declare variables as volatile so the emulation routines are used
    volatile int a = 20, b = 21, c = -99, d = -4200000;
    volatile unsigned int ua = 20, ub = 21, uc = 1000000000, ud = 0xFFFFFFFF;
    volatile long long la = 20, lb = 21, lc = -99, ld = -4200000;
    volatile unsigned long long ula = 20, ulb = 21, ulc = 1000000000000000, uld = 0xFFFFFFFFF;
    volatile float fa = 20, fb = 21, fc = 1.5, fd = -17.12345;
    volatile double da = 20, db = 21, dc = 1.500000001, dd = -123456789.87654321;
    volatile long double qa = 20, qb = 21, qc = 1.50000000000000000001, dqd = -8765432123456789.87654321012345678;
    
    //Result variables (because PORT5 is only 1 int)
    volatile long long lresult;
    volatile unsigned long long ulresult;
    volatile float fresult;
    volatile double dresult;
    volatile long double qresult;
    
    //todo floating point
    
    //Multiplication
    //int
    PORT5 = a * b;//420 (0x1A4)
    PORT5 = a * c;//-1980 (0xFFFFF844)
    PORT5 = d * b;//-88200000 (0xFABE2CC0)
    PORT5 = c * d;//415800000 (0x18C89AC0)
    //unsigned int
    PORT5 = ua * ub;//420 (0x1A4)
    PORT5 = ua * uc;//2x10^10 (0x4A817C800), which cannot fit in a word, so it becomes 2820130816 (0xA817C800)
    PORT5 = ud * ub;//90194313195 (0x14FFFFFFEB), which cannot fit in a word, so it becomes 4294967275 (0xFFFFFFEB)
    PORT5 = uc * ud;//0x3B9AC9FFC4653600, which cannot fit in a word, so it becomes 0xC4653600
    //long long
    /*lresult = la * lb;
    PORT5 = (int)(lresult);
    lresult = la * lc;
    PORT5 = (int)(lresult);
    lresult = ld * lb;
    PORT5 = (int)(lresult);
    lresult = lc * ld;
    PORT5 = (int)(lresult);
    //unsigned long long
    ulresult = ula * ulb;
    PORT5 = (int)(ulresult);
    ulresult = ula * ulc;
    PORT5 = (int)(ulresult);
    ulresult = uld * ulb;
    PORT5 = (int)(ulresult);
    ulresult = ulc * uld;
    PORT5 = (int)(ulresult);*///Todo implement functions in JZJCoreLib
    
    //Unsigned Division
    //int
    //todo
    //unsigned int
    PORT5 = ua / ub;//0 (0x0)
    PORT5 = uc / ua;//50000000 (0x2FAF080)
    PORT5 = ud / ub;//204522252 (0xC30C30C)
    PORT5 = uc / ud;//0 (0x0)
    //todo other types
    
    //Unsigned Modulus
    //int
    //todo
    //unsigned int
    PORT5 = ua % ub;//20 (0x14)
    PORT5 = uc % ua;//0 (0x0)
    PORT5 = ud % ub;//3 (0x3)
    PORT5 = uc % ud;//1000000000 (0x3B9ACA00)
    //todo other types
    
    //todo other operations
    
    return;
}
