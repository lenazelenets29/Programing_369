/* File file.h */
#ifndef DATA_H
#define DATA_H

#include "stdio.h"
#include "stdlib.h"

typedef struct _way{
    char start[15];
    char finish[15];
} way;

typedef struct _train{
    char number[6];
    char repairs;
    int carts;
    way move;
    char type[10];
} train;

int getStrNum(char * fname);
train *readStr(char * fname);

#endif /* DATA_H */