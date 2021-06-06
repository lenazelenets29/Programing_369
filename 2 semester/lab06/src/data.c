#include "data.h"
#include "stdio.h"

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

train *readStr(char * fname, int N, regex_t regex, int reti){
    FILE *info;
    if((info = fopen(fname, "r")) == NULL) {
        printf("Cannot open file.\n");
    }
    train * data = (train *) malloc(N * sizeof(train));
    for(int i = 0; i < N; i++){
        fscanf(info, "%s %c %i %s", &(data + i)->number, &(data + i)->repairs, &(data + i)->carts, &(data + i)->type);
        fseek(info, sizeof(char), 1);

		char start[128] = {0};
		fgets(start, 128, info);
        size_t size = strlen(start);
        start[size - 1] = ' '; // замена '\n' на ' '

		reti = regexec(&regex, start, 0, NULL, 0);
		if (!reti)
			sprintf((data + i)->move.start, start);
		else if (reti == REG_NOMATCH)
			printf("\nВведенная строка не подходит %s\n", start);


        char finish[128] = {0};
		fgets(finish, 128, info);
        size = strlen(finish);
        finish[size - 1] = ' '; // замена '\n' на ' '
		reti = regexec(&regex, finish, 0, NULL, 0);
		if (!reti)
			sprintf((data + i)->move.finish, finish);
		else if (reti == REG_NOMATCH)
			printf("\nВведенная строка не подходит %s\n", finish);
    }
    fclose(info);
    return data;
}