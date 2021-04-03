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

struct train *readStr(char * fname);
void writeStr(char * output, struct train * data, int N);
struct train *sortStr(struct train * data, int N, char * type_field, char * type_sort);
int sortChar(char * current, char * next, int poz, int len);
void Metod1(struct train * data, char * output, int carts, char repairs, int N);
struct train changeTrain(struct train * data);
void setNewTrain(char * fname);
int get_rand_range_int(const int min, const int max);
void writeBin(char * fname, struct train * data, int N);
struct train *readBin(char * fname);
struct train *findBin(char * number, int N, struct train * data);
int getStrNum(char * fname);
int getStrNumBin(char * fname); // возвращает количество элементов массива сруктур в заданом файле
bool test_get_str_num();
bool test_get_str_num_bin();
bool test_sort_char();
bool test_read_str();
bool test_read_bin();
bool test_sort_str();
bool test_change_train();
bool test_find_bin();

int main(){
    bool result = true;    
    result &= test_get_str_num();
    result &= test_get_str_num_bin();
    result &= test_sort_char();
    result &= test_read_str();
    result &= test_read_bin();
    result &= test_sort_str();
    result &= test_change_train();
    result &= test_find_bin();
    if (result) {        
    printf("All tests passed!\n");   
    } else {        
    printf("… some tests failed… \n");    
    }

    return 0;
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

bool test_read_str(){
    struct way expw1 = {"Poland", "Germany"};
    struct way expw2 = {"Germany", "Poland"};
    struct train exp_train[2] = {{"A1004", 'y', 45, expw1, "heat"}, {"A1005", 'y', 20, expw2, "electro"}};
    struct train *act = (struct train *) malloc(2 * sizeof(struct train));
    act = readStr("in.txt");
    bool result = false;
    int i = 0;
    while(strcmp(exp_train[i].number, (act + i)->number) == 0 && exp_train[i].repairs == (act + i)->repairs && exp_train[i].carts == (act + i)->carts && strcmp(exp_train[i].move.start, (act + i)->move.start) == 0 && strcmp(exp_train[i].move.finish, (act + i)->move.finish) == 0 && strcmp(exp_train[i].type, (act + i)->type) == 0 && i < 2){
        i++;
        result = true;
     }
    if((strcmp(exp_train[i-1].number, (act + i - 1)->number) != 0 || exp_train[i-1].repairs != (act + i - 1)->repairs || exp_train[i-1].carts != (act + i - 1)->carts || strcmp(exp_train[i-1].move.start, (act + i - 1)->move.start) != 0 || strcmp(exp_train[i-1].move.finish, (act + i - 1)->move.finish) != 0 || strcmp(exp_train[i-1].type, (act + i - 1)->type) != 0)){
        result = false;
        printf("Function `%s` failed: Actual data: %d, expected: %d\n", "test_read_str", act[i-1].carts, exp_train[i-1].carts);
     }
    return result;
}

int getStrNum(char * fname){
    FILE *info;
    if((info = fopen(fname, "r")) == NULL) {
        printf("Cannot open file.\n");
    }
    int N = 0;
    char ch;
    while((ch=getc (info)) != EOF){
        if(ch == '\n') { N++; }
    }
    fclose(info);
    return N;
}

bool test_get_str_num(){
    int exp = 2;
    int act = getStrNum("in.txt");
    if(exp == act){ 
        return true;
    } else{
        printf("Function `%s` failed: Actual data: %d, expected: %d\n", "test_get_str_num", act, exp); 
        return false;
    }
}
int getStrNumBin(char * fname){
    FILE * fp;
    char *c;
    int m = sizeof(int);
    int n, i;
 
    // выделяем память для количества данных
    int *pti = (int *)malloc(m);
 
    if ((fp = fopen(fname, "r")) == NULL){
        perror("Error occured while opening file");
    }
    // считываем количество структур
    c = (char *)pti;
    while (m>0){
        i = getc(fp);
        if (i == EOF) break;
        *c = i;
        c++;
        m--;
    }
    //получаем число элементов
    n = *pti;
    fclose(fp);
    return n;
}

bool test_get_str_num_bin(){
    int exp = 2;
    int act = getStrNumBin("in_b.txt");
    if(exp == act){ 
        return true;
    } else{
        printf("Function `%s` failed: Actual data: %d, expected: %d", "test_get_str_num_bin", act, exp); 
        return false;
    }
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

int sortChar(char * current, char * next, int poz, int len){
    int r = 0;
    if(current[poz] > next[poz]){
        return 1;
    }
    if(current[poz] < next[poz]){
        return 0;
    }else{
        poz++;
        if(poz != len){
            r = sortChar(current, next, poz, len);
        }
        return r;
    }
}
bool test_sort_char(){
    int exp = 1;
    int act = sortChar("A1005", "A1004", 3, 5);
    if(exp == act){ 
        return true;
    } else{
        printf("Function `%s` failed: Actual data: %d, expected: %d", "test_sort_char", act, exp); 
        return false;
    }
}

struct train *sortStr(struct train * data, int N, char * type_field, char * type_sort){
    struct train temp;
    if(type_field[0] == 'n'){
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) { 
                int len = 0;
                if(strlen(data[j].number) > strlen(data[j + 1].number)){
                    len = strlen(data[j + 1].number);
                }else{
                    len = strlen(data[j].number);
                } 
                if(sortChar(data[j].number, data[j + 1].number, 0, len)) {           
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp; 
                }
            }
        }
    }
    if(type_field[0] == 'r'){
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) {  
                if(data[j].repairs > data[j + 1].repairs) {           
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp; 
                }
            }
        }
    }
    if(type_field[0] == 'c'){
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) {  
                if(data[j].carts > data[j + 1].carts) {           
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp; 
                }
            }
        }
    }
    if(type_field[0] == 's'){
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) { 
                int len = 0;
                if(strlen(data[j].move.start) > strlen(data[j + 1].move.start)){
                    len = strlen(data[j + 1].move.start);
                }else{
                    len = strlen(data[j].move.start);
                } 
                if(sortChar(data[j].move.start, data[j + 1].move.start, 0, len)) {           
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp; 
                }
            }
        }
    }
    if(type_field[0] == 'f'){
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) { 
                int len = 0;
                if(strlen(data[j].move.finish) > strlen(data[j + 1].move.finish)){
                    len = strlen(data[j + 1].move.finish);
                }else{
                    len = strlen(data[j].move.finish);
                } 
                if(sortChar(data[j].move.finish, data[j + 1].move.finish, 0, len)) {           
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp; 
                }
            }
        }
    }
    if(type_field[0] == 't'){
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) { 
                int len = 0;
                if(strlen(data[j].type) > strlen(data[j + 1].type)){
                    len = strlen(data[j + 1].type);
                }else{
                    len = strlen(data[j].type);
                } 
                if(sortChar(data[j].type, data[j + 1].type, 0, len)) {           
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp; 
                }
            }
        }
    }
    
    if(type_sort[0] == 'd'){
        for(int i = 0; i < N / 2; i++){
            temp = data[i];
            data[i] = data[N - 1 - i];
            data[N - 1 - i] = temp;
        }
    }
    return data;
}
bool test_sort_str(){
    struct way expw1 = {"Poland", "Ukraine"};
    struct way expw2 = {"Poland", "Germany"};
    struct way expw3 = {"Germany", "Poland"};
    struct train exp_train[3] = {{"A1002", 'y', 35, expw1, "electro"},{"A1004", 'y', 45, expw2, "heat"}, {"A1005", 'y', 20, expw3, "electro"}};
    struct train *act = (struct train *) malloc(2 * sizeof(struct train));
    act = readStr("out.txt");
    int N = getStrNum("out.txt");
    act = sortStr(act, N, "number", "up");
    bool result = false;
    int i = 0;
    while(strcmp(exp_train[i].number, (act + i)->number) == 0 && exp_train[i].repairs == (act + i)->repairs && exp_train[i].carts == (act + i)->carts && strcmp(exp_train[i].move.start, (act + i)->move.start) == 0 && strcmp(exp_train[i].move.finish, (act + i)->move.finish) == 0 && strcmp(exp_train[i].type, (act + i)->type) == 0 && i < 3){
        i++;
        result = true;
     }
    if((strcmp(exp_train[i-1].number, (act + i - 1)->number) != 0 || exp_train[i-1].repairs != (act + i - 1)->repairs || exp_train[i-1].carts != (act + i - 1)->carts || strcmp(exp_train[i-1].move.start, (act + i - 1)->move.start) != 0 || strcmp(exp_train[i-1].move.finish, (act + i - 1)->move.finish) != 0 || strcmp(exp_train[i-1].type, (act + i - 1)->type) != 0)){
        result = false;
        printf("Function `%s` failed: Actual data: %d, expected: %d\n", "test_sort_str", act[i-1].carts, exp_train[i-1].carts);
     }
    return result;  
}

void Metod1(struct train * data, char * output, int carts, char repairs, int N){
    FILE *out_t;
    if((out_t = fopen(output, "w"))==NULL) {
        printf("Cannot open file.\n");
        return;
    }
    for(int i = 0; i < N; i++){
        if(data[i].carts > carts && data[i].repairs == repairs){
            printf("%s %c %i %s %s %s\n", data[i].number, data[i].repairs, data[i].carts, data[i].move.start, data[i].move.finish, data[i].type);
            fprintf(out_t, "%s %c %i %s %s %s\n", data[i].number, data[i].repairs, data[i].carts, data[i].move.start, data[i].move.finish, data[i].type);
        }
    }
    fclose(out_t);
}

struct train changeTrain(struct train * data){
    char change[20];
    printf("Current train:\n%s %c %i %s %s %s\n", data->number, data->repairs, data->carts, data->move.start, data->move.finish, data->type);
    printf("Enter new repairs:> ");
    scanf("%s", change);
    if(change[0] != '-'){
        data->repairs = * change;
    }
    printf("Enter new carts:> ");
    scanf("%s", change);
    if(change[0] != '-'){
        data->carts = atoi(change);
    }
    printf("Enter new start:> ");
    scanf("%s", change);
    if(change[0] != '-'){
        strcpy(data->move.start, change);
    }
    printf("Enter new finish:> ");
    scanf("%s", change);
    if(change[0] != '-'){
        strcpy(data->move.finish, change);
    }
    printf("Enter new type:> ");
    scanf("%s", change);
    if(change[0] != '-'){
        strcpy(data->type, change);
    }
    return * data;
}
bool test_change_train(){
    int N = getStrNum("out.txt");
    struct train * data = (struct train *) malloc(N * sizeof(struct train)); 
    data = readStr("out.txt");
    int k = 0;
    char number[] = "A1005";
    while(strcmp(data[k].number, number)){ k++;}
    struct train act = changeTrain(&data[k]);
    struct way w1 = {"Poland", "Russia"};
    struct train exp = {"A1005", 'y', 60, w1, "heat"};
    bool result = true;
    if(strcmp(act.number, exp.number) !=0 || strcmp(act.move.start, exp.move.start) !=0 ||strcmp(act.move.finish, exp.move.finish) !=0 ||strcmp(act.type, exp.type) !=0 || act.repairs != exp.repairs || act.carts != exp.carts){
        result = false;
        printf("Function `%s` failed: Actual data: %s %c %i %s %s %s expected: %s %c %i %s %s %s\n", "test_change_train", act.number, act.repairs, act.carts, act.move.start, act.move.finish, act.type, exp.number, exp.repairs, exp.carts, exp.move.start, exp.move.finish, exp.type);
    }
    return result;
}

int get_rand_range_int(const int min, const int max) {
    return rand() % (max - min + 1) + min;
}

void setNewTrain(char * fname){
    int N = getStrNum(fname);
    struct train * data = (struct train *) malloc(N * sizeof(struct train)); 
    data = readStr(fname);
    struct train temp;
    char ch, number[6];
    char num_ch[5] = "";
    strcpy(number, data[N - 1].number);
    ch = number[0];
    strcpy(num_ch, number + 1);
    int num = atoi(num_ch) + 1;
    if(num == 10000){
        ch = ch + 1;
        num = 1000;
    }
    number[0] = ch;
    strcpy(number + 1, itoa(num, num_ch, 10));
    strcpy(temp.number, number);
    int r = get_rand_range_int(0, 1);
    if(r == 0){
        temp.repairs = 'y';
    }else{
        temp.repairs = 'n';
    }
    temp.carts = get_rand_range_int(10, 110);
    r = get_rand_range_int(1, 4);
    if(r == 1){
        strcpy(temp.move.start, "Ukraine");
    }if(r == 2){
        strcpy(temp.move.start, "Russia");
    }if(r == 3){
        strcpy(temp.move.start, "Poland");
    }if(r == 4){
        strcpy(temp.move.start, "Germany");
    }
    int r1 = get_rand_range_int(1, 4);
    while (r1 == r){ r1 = get_rand_range_int(1, 4);}
    if(r1 == 1){
        strcpy(temp.move.finish, "Ukraine");
    }if(r1 == 2){
        strcpy(temp.move.finish, "Russia");
    }if(r1 == 3){
        strcpy(temp.move.finish, "Poland");
    }if(r1 == 4){
        strcpy(temp.move.finish, "Germany");
    }
    r = get_rand_range_int(1, 3);
    if(r == 1){
        strcpy(temp.type, "heat");
    }if(r == 2){
        strcpy(temp.type, "steam");
    }if(r == 3){
        strcpy(temp.type, "electro");
    }
    FILE *info;
    if((info = fopen(fname, "a"))==NULL) {
        printf("Cannot open file.\n");
        return;
    }
    fprintf(info, "%s %c %i %s %s %s\n", temp.number, temp.repairs, temp.carts, temp.move.start, temp.move.finish, temp.type);
    free(data);
    fclose(info);
}

void writeBin(char * fname, struct train * data, int N){
    FILE * fp;
    char *c;
 
    // число записываемых байтов
    int size = N * sizeof(struct train);
     
    if ((fp = fopen(fname, "wb")) == NULL){
        perror("Error occured while opening file");
        return;
    }
    // записываем количество структур
    c = (char *)&N;
    for (int i = 0; i<sizeof(int); i++){
        putc(*c++, fp);
    }
 
    // посимвольно записываем в файл все структуры
    c = (char *)data;
    for (int i = 0; i < size; i++){
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return;
}

struct train *readBin(char * fname){
    FILE * fp;
    char *c;
    int m = sizeof(int);
    int n, i;
 
    // выделяем память для количества данных
    int *pti = (int *)malloc(m);
 
    if ((fp = fopen(fname, "r")) == NULL){
        perror("Error occured while opening file");
    }
    // считываем количество структур
    c = (char *)pti;
    while (m>0){
        i = getc(fp);
        if (i == EOF) break;
        *c = i;
        c++;
        m--;
    }
    //получаем число элементов
    n = *pti;
 
    // выделяем память для считанного массива структур
    struct train * ptr = (struct train *) malloc(n * sizeof(struct train));
    c = (char *)ptr;
    // после записи считываем посимвольно из файла
    while ((i = getc(fp))!=EOF){
        *c = i;
        c++;
    }
    
    fclose(fp);
    return ptr;
}
bool test_read_bin(){
    struct way expw1 = {"Poland", "Germany"};
    struct way expw2 = {"Germany", "Poland"};
    struct train exp_train[2] = {{"A1004", 'y', 45, expw1, "heat"}, {"A1005", 'y', 20, expw2, "electro"}};
    struct train *act = (struct train *) malloc(2 * sizeof(struct train));
    act = readBin("in_b.txt");
    bool result = false;
    int i = 0;
    while(strcmp(exp_train[i].number, (act + i)->number) == 0 && exp_train[i].repairs == (act + i)->repairs && exp_train[i].carts == (act + i)->carts && strcmp(exp_train[i].move.start, (act + i)->move.start) == 0 && strcmp(exp_train[i].move.finish, (act + i)->move.finish) == 0 && strcmp(exp_train[i].type, (act + i)->type) == 0 && i < 2){
        i++;
        result = true;
     }
    if((strcmp(exp_train[i-1].number, (act + i - 1)->number) != 0 || exp_train[i-1].repairs != (act + i - 1)->repairs || exp_train[i-1].carts != (act + i - 1)->carts || strcmp(exp_train[i-1].move.start, (act + i - 1)->move.start) != 0 || strcmp(exp_train[i-1].move.finish, (act + i - 1)->move.finish) != 0 || strcmp(exp_train[i-1].type, (act + i - 1)->type) != 0)){
        result = false;
        printf("Function `%s` failed: Actual data: %d, expected: %d\n", "test_read_str", act[i-1].carts, exp_train[i-1].carts);
     }
    return result;
}

struct train *findBin(char * number, int N, struct train * data){
    struct train * temp;
 
    for (int k = 0; k < N; k++){
        if(strcmp((data + k)->number, number) == 0){
            temp = (data + k);
        }
    }
    return temp;
}
bool test_find_bin(){
    int N = getStrNumBin("out_b.txt");
    struct train * data = (struct train *) malloc(N * sizeof(struct train)); 
    data = readBin("out_b.txt");
    char number[] = "A1004";
    struct train * act = findBin(number, N, data);
    struct way w1 = {"Poland", "Germany"};
    struct train exp = {"A1004", 'y', 45, w1, "heat"};
    bool result = true;
    if(strcmp(act->number, exp.number) !=0 || strcmp(act->move.start, exp.move.start) !=0 ||strcmp(act->move.finish, exp.move.finish) !=0 ||strcmp(act->type, exp.type) !=0 || act->repairs != exp.repairs || act->carts != exp.carts){
        result = false;
        printf("Function `%s` failed: Actual data: %s %c %i %s %s %s expected: %s %c %i %s %s %s\n", "test_find_bin", act->number, act->repairs, act->carts, act->move.start, act->move.finish, act->type, exp.number, exp.repairs, exp.carts, exp.move.start, exp.move.finish, exp.type);
    }
    return result;
}

