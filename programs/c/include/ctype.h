#ifndef CTYPE_H
#define CTYPE_H

//Character Classification
int isalnum(int ch);
int isalpha(int ch);
int islower(int ch);
int isupper(int ch);
int isdigit(int ch);
int isxdigit(int ch);
int iscntrl(int ch);
int isgraph(int ch);
int isspace(int ch);
int isblank(int ch);
int isprint(int ch);
int ispunct(int ch);

//Character Manipulation
int tolower(int ch);
int toupper(int ch);

#endif
