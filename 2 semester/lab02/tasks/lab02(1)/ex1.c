#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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

void run_command();
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
struct train *findBin(char * number, char * fname, struct train * data);
int getStrNum(char * fname);
int getStrNumBin(char * fname); // возвращает количество элементов массива сруктур в заданом файле

int main(){
    
    run_command();

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

struct train *findBin(char * number, char * fname, struct train * data){
    int n = getStrNumBin(fname);
    struct train * temp;
 
    for (int k = 0; k < n; k++){
        if(strcmp((data + k)->number, number) == 0){
            temp = (data + k);
        }
    }
    return temp;
}

void run_command(){
    char type_com[10];
    printf("Set command:> ");
    scanf("%s", type_com);
    if(type_com[0] == 'c' && type_com[1] == 'h'){
        FILE *info;
        char fname[15], number[6];
        printf("Enter input filename:> ");
        scanf("%s", fname);
        printf("Enter train's number:> ");
        scanf("%s", number);
        int N = getStrNum(fname);
        struct train * data = (struct train *) malloc(N * sizeof(struct train)); 
        data = readStr(fname);
        int k = 0;
        while(strcmp(data[k].number, number)){ k++;}
        struct train temp = changeTrain(&data[k]);
        data[k] = temp;
        if((info = fopen(fname, "w"))==NULL) {
            printf("Cannot open file.\n");
            return;
        }
        for(int i = 0; i < N; i++){
            fprintf(info, "%s %c %i %s %s %s\n", data[i].number, data[i].repairs, data[i].carts, data[i].move.start, data[i].move.finish, data[i].type);
        }
        free(data);
        fclose(info);
        run_command();
    }
    if(type_com[0] == 'c'){
        exit(0);
    }
    if(type_com[0] == 'r' && type_com[1] == 'b'){
        char fname[15];
        printf("Enter filename:> ");
        scanf("%s", fname);
        int N = getStrNumBin(fname);
        struct train * data = (struct train *) malloc(N * sizeof(struct train)); 
        data = readBin(fname);
        // перебор загруженных элементов и вывод на консоль
 
        for (int k = 0; k < N; k++){
            printf("%s %c %i %s %s %s\n", (data + k)->number, (data + k)->repairs, (data + k)->carts, (data + k)->move.start, (data + k)->move.finish, (data + k)->type);
        }
        free(data);
        run_command();
    }
    if(type_com[0] == 'r'){
        char fname[15];
        printf("Enter filename:> ");
        scanf("%s", fname);
        int N = getStrNum(fname);
        struct train * data = (struct train *) malloc(N * sizeof(struct train)); 
        data = readStr(fname);
        for(int i = 0; i < N; i++){
            printf("%s %c %i %s %s %s\n", (data + i)->number, (data + i)->repairs, (data + i)->carts, (data + i)->move.start, (data + i)->move.finish, (data + i)->type);
        }
        free(data);
    }
    if(type_com[0] == 'w' && type_com[1] == 'b'){
        char fname[15], output[15];
        printf("Enter input filename:> ");
        scanf("%s", fname);
        int N = getStrNum(fname);
        struct train * data = (struct train *) malloc(N * sizeof(struct train)); 
        data = readStr(fname);
        printf("Enter output filename:> ");
        scanf("%s", output);
        writeBin(output, data, N);
        free(data);
        run_command();
    }
    if(type_com[0] == 'w'){
        char input[15], output[15];
        printf("Enter input filename:> ");
        scanf("%s", input);
        int N = getStrNum(input);
        struct train * data = (struct train *) malloc(N * sizeof(struct train)); 
        data = readStr(input);
        printf("Enter output filename:> ");
        scanf("%s", output);
        writeStr(output, data, N);
    }
    if(type_com[0] == 's'){
        char input[15], output[15], type_field[10], type_sort[5];
        printf("Enter input filename:> ");
        scanf("%s", input);
        printf("Enter output filename:> ");
        scanf("%s", output);
        printf("Enter field for sort:> ");
        scanf("%s", type_field);
        printf("Enter type of sort:> ");
        scanf("%s", type_sort);
        int N = getStrNum(input);
        struct train * data = (struct train *) malloc(N * sizeof(struct train)); 
        data = readStr(output);
        struct train * sort_data = (struct train *) malloc(N * sizeof(struct train));
        sort_data = sortStr(data, N, type_field, type_sort);
        writeStr(output, sort_data, N);
        for(int i = 0; i < N; i++){
            printf("%s %c %i %s %s %s\n", (sort_data + i)->number, (sort_data + i)->repairs, (sort_data + i)->carts, (sort_data + i)->move.start, (sort_data + i)->move.finish, (sort_data + i)->type);
        }
        free(data);
    }
    if(type_com[0] == 'm' && type_com[1] == '1'){
        char input[15], output[15];
        char repairs;
        int carts;
        printf("Enter input filename:> ");
        scanf("%s", input);
        printf("Enter output filename:> ");
        scanf("%s", output);
        printf("Enter carts:> ");
        scanf("%i", &carts);
        printf("Enter repairs:> ");
        scanf("\n%c", &repairs);
        int N = getStrNum(input);
        struct train * data = (struct train *) malloc(N * sizeof(struct train));
        data = readStr(input);
        Metod1(data, output, carts, repairs, N);
        free(data);
    }
    if(type_com[0] == 'n'){
        char fname[15];
        printf("Enter input filename:> ");
        scanf("%s", fname);
        setNewTrain(fname);
    }
    if(type_com[0] == 'f'){
        char number[6], fname[15];
        printf("Enter filename:> ");
        scanf("%s", fname);
        printf("Enter train's number:> ");
        scanf("%s", number);
        int N = getStrNumBin(fname);
        struct train * data = (struct train *) malloc(N * sizeof(struct train)); 
        data = readBin(fname);
        struct train *temp;
        temp = findBin(number, fname, data);
        printf("%s %c %i %s %s %s\n", temp->number, temp->repairs, temp->carts, temp->move.start, temp->move.finish, temp->type);
        free(data);
    }
    run_command();
}