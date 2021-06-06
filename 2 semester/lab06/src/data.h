/* File file.h */
#ifndef DATA_H
#define DATA_H

#include "stdio.h"
#include "stdlib.h"
#include "regex.h"

typedef struct _way{
    char start[150];
    char finish[150];
} way;

typedef struct _train{
    char number[6];
    char repairs;
    int carts;
    way move;
    char type[10];
} train;

int getStrNum(char * fname);
train *readStr(char * fname, int N, regex_t regex, int reti);

#endif /* DATA_H */