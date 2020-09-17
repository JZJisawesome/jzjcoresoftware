#ifndef ERRNO_H
#define ERRNO_H

int __errno = 0;//Only one, global errno variable
#define errno __errno

#endif
