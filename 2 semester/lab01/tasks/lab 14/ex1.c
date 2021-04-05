#define _CRT_SECURE_NO_WARNINGS //для работы strcpy
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <dirent.h>
#include <dir.h>

void stop_work();
void read_file();
void write_file();
void change_dir();
void move_up();
char *move_down(char *dir);
void tree(char *path, int N);
int fsize(char *fname);
int get_size(char *path);
void run_command();

int main(){

    run_command();
    
    return 0;
}

void stop_work(){
    exit(1);
}

void read_file(){
    setlocale(LC_ALL, "Rus");
    
    FILE *info;
    char text[100], name[15];
    printf("Enter file name: ");
    scanf("%s", name);
    if((info = fopen(name, "r"))==NULL) {
        printf("Cannot open file.\n");
    }
    int i = 0;
    while((text[i]=getc (info)) != EOF){
        i++;
    }
    text[i] = 0;
    printf("%s\n", text);
    fclose(info);
}

void write_file(){
    setlocale(LC_ALL, "Rus");

    FILE *info;
    FILE *out_f;
    char name[15], text[100];
    printf("Enter read-file name: ");
    scanf("%s", name);
    if((info = fopen(name, "r"))==NULL) {
        printf("Cannot open file.\n");
    }

    int i = 0;
    while((text[i]=getc (info)) != EOF){
        i++;
    }
    text[i] = 0;

    int SIZE = strlen(text);

    printf("Enter write-file name: ");
    scanf("%s", name);
    if((out_f = fopen(name, "w"))==NULL) {
        printf("Cannot open file.\n");
    }

    bool flag = true;
    int count_numb = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if ((int)*(text + i) > 0 && (int)*(text + i) != (int)' ')
            count_numb++; // количество цифр
    }
    char* numb_arr = (char*)malloc(sizeof(char) * count_numb);
    
    for (int i = 0, j = 0; i < SIZE; i++)
    {
        if ((int)*(text + i) > 0 && (int)*(text + i) != (int)' ')
        {
            *(numb_arr + j) = *(text + i);
            j++; // запись в масив символов чисел (numb_arr)
        }
    }
    

    for (int i = 0; i < count_numb; i++){
        printf("%c ",*(numb_arr + i));
        putc(numb_arr[i], out_f);
        if(i != count_numb - 1){
            putc(' ', out_f);
        }
    }
    printf("%c", '\n');
    free(numb_arr);
    fclose(info);
    fclose(out_f);
}

void change_dir(){
    char path[200];
    printf("Set path: ");
    scanf("%s", path);
    chdir(path);
    getcwd(path, 200);
    printf("Current path %s\n", path);
}

void move_up(){
    char path[200];
    getcwd(path, 200);
    int len = strlen(path);
    while(path[len - 1] != '\\'){
        path[len - 1] = 0;
        len--;
    }
    chdir (path);
    getcwd(path, 200);
    printf("Current path %s\n", path);
}

char *move_down(char *dir){
    char *path = malloc(200);
    getcwd(path, 200);
    int len = strlen(path);
    int len_dir = strlen(dir);
    path[len] = '\\';
    for(int i = len + 1; i < len + len_dir + 1; i++){
        path[i] = dir[i - len - 1];
    }
    path[len_dir + len + 1] = 0;
    return path;
}

void tree(char *path, int N){
    chdir(path);
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path)) != NULL) {
        /* print all the files and directories within directory */
        int i = 0;
        while ((ent = readdir (dir)) != NULL) {
            if(i > 1){
                for(int j = 0; j < N; j++){
                    printf("   ");
                }
                printf ("%s %s\n", "└──", ent->d_name);
                if(fsize(move_down(ent->d_name)) == 0){
                    N++;
                    tree(move_down(ent->d_name), N);
                    N--;
                    chdir(path);
                }
            }
            i++;
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        exit;
    }
}

int fsize(char *fname){
    FILE *fp;
    int prev, sz;
    if((fp = fopen(fname, "r"))!=NULL) {
        prev=ftell(fp);
        fseek(fp, 0L, SEEK_END);
        sz=ftell(fp);
        fseek(fp,prev,SEEK_SET); //go back to where we were
    }
    else{
        sz = 0;
    }
    fclose(fp);
    return sz;
}

int get_size(char *path){
    chdir (path);
    int size_dir = 0;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path)) != NULL) {
        /* print all the files and directories within directory */
        int i = 0;
        while ((ent = readdir (dir)) != NULL) {
            if(i > 1){
                char *hpath = move_down(ent->d_name);
                if(fsize(hpath) != 0){
                    size_dir = size_dir + fsize(hpath);
                }else{
                    size_dir = size_dir + get_size(hpath);
                    chdir (path);
                }
            }
            i++;
        }
        closedir (dir);
    } else {
        size_dir = fsize(path);
        /* could not open directory */
        exit;
    }
    return size_dir;
}

void run_command(){
    printf("Set your command:> ");
    char type_com[20];
    scanf("%s", &type_com);
    if(type_com[0] == 'c' && type_com[1] == 'h'){
        change_dir();
        run_command();
    }
    if(type_com[0] == 'c'){
        stop_work();
    }
    if(type_com[0] == 'r'){
        read_file();
    }
    if(type_com[0] == 'w'){
        write_file();
    }
    if(type_com[0] == 't'){
        char path[200];
        getcwd(path, 200);
        printf("%s\n", path);
        tree(path, 1);
    }
    if(type_com[0] == '.'){
        move_up();
    }
    if(type_com[0] == 'm'){
        char dir[40];
        printf("Set directory: ");
        scanf("%s", dir);
        char *path = move_down(dir);
        chdir (path);
        getcwd(path, 200);
        printf("Current path %s\n", path);
    }
    if(type_com[0] == 's'){
        printf("Set path: ");
        char * path = (char *)calloc(200, sizeof(char));
        char buff;
        while (buff = getc(stdin) != '\n')
        {
        }
        fgets(path, 199, stdin);
        
        printf("Path: %s\n", path);
        path[strlen(path) - 1] = '\0';
        float i_size = get_size(path);
        float f_size = i_size;
        char value_size;
        if(i_size > 1024 * 1024 * 1024){
            value_size = 'G';
            f_size = i_size / 1024 / 1024 / 1024;
        }else{
            if(i_size > 1024 * 1024){
            value_size = 'M';
            f_size = i_size / 1024 / 1024;
            }else{
                if(i_size > 1024){
                    value_size = 'K';
                    f_size = i_size / 1024;
                }
            }
        }
        
        printf("Size directory is: %.2f %cb\n", f_size, value_size);
    }
    run_command();
}