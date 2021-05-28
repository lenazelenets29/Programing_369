#include "data.h"

int getStrNum(char * fname){
    FILE *info;
    if((info = fopen(fname, "r")) == NULL) {
        printf("Cannot open file.\n");
    }
    int N = 0;
    char ch;
    while((ch = getc (info)) != EOF){
        if(ch == '\n') { N++; }
    }
    fclose(info);
    return N;
}

train *readStr(char * fname){
    FILE *info;
    if((info = fopen(fname, "r")) == NULL) {
        printf("Cannot open file.\n");
    }
    int N = getStrNum(fname);
    train * data = (train *) malloc(N * sizeof(train));
    for(int i = 0; i < N; i++){
        fscanf(info, "%s %c %i %s %s %s", (data + i)->number, &(data + i)->repairs, &(data + i)->carts, (data + i)->move.start, (data + i)->move.finish, (data + i)->type);
    }
    fclose(info);
    return data;
}