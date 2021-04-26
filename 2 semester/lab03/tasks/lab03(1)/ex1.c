#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

struct way{
    char start[15];
    char finish[15];
};

struct  train{
    char number[6];
    char repairs;
    int carts;
    struct way move;
    char type[10];
};

char *insert(char * source, char * insert, int pozition);
bool test_insert();
char *reduce(char * source, int start_poz, int final_poz);
bool test_reduce();
struct train *add_str(struct train *data, int poz, int N);
bool test_add_str();
struct train *del_str(struct train *data, int poz, int N);
bool test_del_str();
struct train *readStr(char * fname);
void writeStr(char * output, struct train * data, int N);
int getStrNum(char * fname);
void run_command();

int main(){
    
    run_command();    

    return 0;
}


bool test_add_str(){
    bool result = true;
    int N = 2;
    int poz = 2;
    struct way w1 = {"Ukraine", "Russia"};
    struct way w2 = {"Poland", "Ukraine"};
    struct train exp[2] = {{"A1000", 'n', 60, w1, "heat"},{"A1001", 'n', 95, w2, "electro"}};
    struct train * act = (struct train *) malloc(N * sizeof(struct train));
    strcpy(act[0].number, "A1000");
    act[0].repairs = 'n';
    act[0].carts = 60;
    strcpy(act[0].move.start, "Ukraine");
    strcpy(act[0].move.finish, "Russia");
    strcpy(act[0].type, "heat");
    act = add_str(act, poz, N);
    int i;
    for(i = 0; i < N; i++){
        if(strcmp(exp[i].number, (act + i)->number) != 0 || exp[i].repairs != (act + i)->repairs || exp[i].carts != (act + i)->carts || strcmp(exp[i].move.start, (act + i)->move.start) != 0 || strcmp(exp[i].move.finish, (act + i)->move.finish) != 0 || strcmp(exp[i].type, (act + i)->type) != 0){
            result = false;
            break;
        }
    }
    if(result){
        printf("Test '%s' passed.\n ... ... ... \n", "test_add_str");
    }else{
        result = false;
        printf("Function `%s` failed: Actual data: %s %c %i %s %s %s expected: %s %c %i %s %s %s \n ... ... ... \n", "test_add_str", act[i].number, act[i].repairs, act[i].carts, act[i].move.start, act[i].move.finish, act[i].type, exp[i].number, exp[i].repairs, exp[i].carts, exp[i].move.start, exp[i].move.finish, exp[i].type);
    }
    free(act);
    return result;
}

struct train *del_str(struct train *data, int poz, int N){
    struct train * temp = (struct train *) malloc(N * sizeof(struct train));
    for(int i = 0; i < poz - 1; i++){
        temp[i] = data[i];
    }
    for(int i = poz; i < N + 1; i++){
        temp[i - 1] = data[i];
    }
    return temp;
}

bool test_del_str(){
    bool result = true;
    int N = 1;
    int poz = 2;
    struct way w1 = {"Ukraine", "Russia"};
    struct train exp[2];
    strcpy(exp[0].number, "A1000");
    exp[0].repairs = 'n';
    exp[0].carts = 60;
    strcpy(exp[0].move.start, "Ukraine");
    strcpy(exp[0].move.finish, "Russia");
    strcpy(exp[0].type, "heat");
    struct train * data = (struct train *) malloc((N + 1) * sizeof(struct train));
    strcpy(data[0].number, "A1000");
    data[0].repairs = 'n';
    data[0].carts = 60;
    strcpy(data[0].move.start, "Ukraine");
    strcpy(data[0].move.finish, "Russia");
    strcpy(data[0].type, "heat");
    strcpy(data[1].number, "A1001");
    data[1].repairs = 'n';
    data[1].carts = 95;
    strcpy(data[1].move.start, "Poland");
    strcpy(data[1].move.finish, "Ukraine");
    strcpy(data[1].type, "electro");
    struct train * act = (struct train *) malloc(N * sizeof(struct train));
    act = del_str(data, poz, N);
    int i;
    for(i = 0; i < N; i++){
        if(strcmp(exp[i].number, (act + i)->number) != 0 || exp[i].repairs != (act + i)->repairs || exp[i].carts != (act + i)->carts || strcmp(exp[i].move.start, (act + i)->move.start) != 0 || strcmp(exp[i].move.finish, (act + i)->move.finish) != 0 || strcmp(exp[i].type, (act + i)->type) != 0){
            result = false;
            break;
        }
    }
    if(result){
        printf("Test '%s' passed.\n ... ... ... \n", "test_del_str");
    }else{
        result = false;
        printf("Function `%s` failed: Actual data: %s %c %i %s %s %s expected: %s %c %i %s %s %s \n ... ... ... \n", "test_del_str", act[i].number, act[i].repairs, act[i].carts, act[i].move.start, act[i].move.finish, act[i].type, exp[i].number, exp[i].repairs, exp[i].carts, exp[i].move.start, exp[i].move.finish, exp[i].type);
    }
    free(data);
    free(act);
    return result;
}

struct train *add_str(struct train *data, int poz, int N){
    struct train * temp = (struct train *) malloc(N * sizeof(struct train));
    int size = 40;
    char name[size], start[size], finish[size], type[size];
    char repairs;
    int carts;
    printf("Enter name:> ");
    scanf("%s", name);
    printf("Enter repairs:> ");
    scanf("\n%c", &repairs);
    printf("Enter carts:> ");
    scanf("%i", &carts);
    printf("Enter start:> ");
    scanf("%s", start);
    printf("Enter finish:> ");
    scanf("%s", finish);
    printf("Enter type:> ");
    scanf("%s", type);
    for(int i = 0; i < poz - 1; i++){
        temp[i] = data[i];
    }
    int i = 0;
    memset(temp[poz - 1].number, '\0', 6);
    while(name[i] != '\0'){
        memset(temp[poz - 1].number, name[i], 1);
        i++;
    }
    memcpy(temp[poz - 1].number, name, 6);
    temp[poz - 1].repairs = repairs;
    temp[poz - 1].carts = carts;
    memcpy(temp[poz - 1].move.start, start, 15);
    memcpy(temp[poz - 1].move.finish, finish, 15);
    memcpy(temp[poz - 1].type, type, 10);
    
    for(int i = poz - 1; i < N - 1; i++){
        temp[i + 1] = data[i];
    }
    return temp;
}

bool test_insert(){
    bool result = true;
    char source[] = "abrakadabra";
    char ins[] = "TEXT2";
    int pozition = 4;
    char exp[] = "abraTEXT2kadabra";
    char act[40];
    strcpy(act, insert(source, ins, pozition));
    if(strcmp(act, exp)){
        result = false;
        printf("Function `%s` failed: Actual data: %s expected: %s \n ... ... ... \n", "test_insert", act, exp);
    }else{
        printf("Test '%s' passed.\n ... ... ... \n", "test_insert");
    }
    return result;
}

char *insert(char * source, char * ins, int pozition){
    int lenSource = strlen(source);
    int lenIns = strlen(ins);
    int lenNewStr = lenSource + lenIns + 1;
    char * newStr = (char *) malloc(lenNewStr * sizeof(char));
    strcpy(newStr, source);
    strcpy(newStr + pozition, ins);
    strcpy(newStr + pozition + lenIns, source + pozition);
    return newStr;
}
bool test_reduce(){
    bool result = true;
    char source[] = "abrakadabra";
    int start_poz = 4;
    int final_poz = 8;
    char exp[] = "abrara";
    char act[40];
    strcpy(act, reduce(source, start_poz, final_poz));
    if(strcmp(act, exp)){
        result = false;
        printf("Function `%s` failed: Actual data: %s expected: %s \n ... ... ... \n", "test_reduce", act, exp);
    }else{
        printf("Test '%s' passed.\n ... ... ... \n", "test_reduce");
    }
    return result;

}

char *reduce(char * source, int start_poz, int final_poz){
    int lenSource = strlen(source);
    int lenNewStr = lenSource - final_poz + start_poz;
    char * newStr = (char *) malloc(lenNewStr * sizeof(char));
    strcpy(newStr, source);
    strcpy(newStr + start_poz, source + final_poz + 1);
    return newStr;
}

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

struct train *readStr(char * fname){
    FILE *info;
    if((info = fopen(fname, "r")) == NULL) {
        printf("Cannot open file.\n");
    }
    int N = getStrNum(fname);
    struct train * data = (struct train *) malloc(N * sizeof(struct train));
    for(int i = 0; i < N; i++){
        fscanf(info, "%s %c %i %s %s %s", (data + i)->number, &(data + i)->repairs, &(data + i)->carts, (data + i)->move.start, (data + i)->move.finish, (data + i)->type);
    }
    fclose(info);
    return data;
}

void writeStr(char * output, struct train * data, int N){
    FILE *out_t;
    if((out_t = fopen(output, "w"))==NULL) {
        printf("Cannot open file.\n");
        return;
    }
    for(int i = 0; i < N; i++){
        fprintf(out_t, "%s %c %i %s %s %s\n", data[i].number, data[i].repairs, data[i].carts, data[i].move.start, data[i].move.finish, data[i].type);
    }
    fclose(out_t);
}

void run_command(){
    char type_com[15];
    printf("Set command:> ");
    scanf("%s", type_com);
    if(type_com[0] == 'c'){
        exit(1);
    }
    if(type_com[0] == 'i'){
        char source[40], ins[40], str[80];
        int pozition;
        printf("Set source string:> ");
        scanf("%s", source);
        printf("Set insert string:> ");
        scanf("%s", ins);
        printf("Set pozition for insert:> ");
        scanf("%i", &pozition);
        strcpy(str, insert(source, ins, pozition));
        printf("New string:\n%s\n", str);
    }
    if(type_com[0] == 'r'){
        char source[40], str[40];
        int start_poz, final_poz;
        printf("Set source string:> ");
        scanf("%s", source);
        printf("Set start pozition:> ");
        scanf("%i", &start_poz);
        printf("Set final pozition:> ");
        scanf("%i", &final_poz);
        strcpy(str, reduce(source, start_poz, final_poz));
        printf("New string:\n%s\n", str);
    }
    if(type_com[0] == 'n'){
        char fname[40];
        int poz;
        printf("Enter filename:> ");
        scanf("%s", fname);
        printf("Enter pozition:> ");
        scanf("%i", &poz);
        int N = getStrNum(fname) + 1;
        struct train * data = (struct train *) malloc(N * sizeof(struct train));
        data = readStr(fname);
        data = add_str(data, poz, N);
        writeStr(fname, data, N);
        free(data);
    }
    if(type_com[0] == 'd'){
        char fname[40];
        int poz;
        printf("Enter filename:> ");
        scanf("%s", fname);
        printf("Enter pozition:> ");
        scanf("%i", &poz);
        int N = getStrNum(fname);
        struct train * data = (struct train *) malloc(N * sizeof(struct train));
        data = readStr(fname);
        struct train * temp = (struct train *) malloc((N - 1) * sizeof(struct train));
        temp = del_str(data, poz, N - 1);
        writeStr(fname, temp, N - 1);
        free(temp);
        free(data);
    }
    if(type_com[0] == 't'){
        bool result = true;
        result &= test_add_str();
        result &= test_insert();
        result &= test_reduce();
        result &= test_del_str();
        if(result){
            printf("All test passed.\n");
        }
    }
    run_command();
}