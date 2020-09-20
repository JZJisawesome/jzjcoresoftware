#ifndef MATH_H
#define MATH_H

/* Functions */

//Basic Operations
//TODO define and implement
//Exponential functions
//TODO define and implement
//Power functions
//TODO define and implement
//Trigonometric functions
//TODO define and implement
//Hyperbolic functions
//TODO define and implement
//Error and gamma functions
//TODO define and implement
//Nearest integer floating point operations
//TODO define and implement
//Floating point manipulation functions
//TODO there are more that should be here
float copysignf(float x, float y);
double copysign(double x, double y);
long double copysignl(long double x, long double y);//TODO

/* Function Macros */
//Classification And Comparison

#define fpclassify __builtin_fpclassify
#define isfinite __builtin_isfinite
#define isinf __builtin_isinf
#define isnan __builtin_isnan
#define isnormal __builtin_isnormal
#define signbit __builtin_signbit
#define isgreater __builtin_isgreater
#define isgreaterequal __builtin_isgreaterequal
#define isless __builtin_isless
#define islessequal __builtin_islessequal
#define islessgreater __builtin_islessgreater
#define isunordered __builtin_isunordered

/* Macro Constants */

//TODO define and implement

#endif
