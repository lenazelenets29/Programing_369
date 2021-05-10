#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[]) {
    FILE *in_t;
    FILE *out_t; 
    char c_N[2]; // переменная для указания размера матрицы
    if((in_t = fopen("in.txt", "r"))==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    } 
    for(int i = 0; i < 2; i++){
        c_N[i] = getc(in_t);
    } // функция принимает размер матрицы с входного файла
    int N = atoi(&c_N[0]); 
    char mat[2*N*N + 1]; // обьявляем матрицу
    for(int i = 0; i < 2*N*N; i++){
        mat[i] = getc(in_t);
    } // функция принимает матрицу с входного файла
    mat[2*N*N-1] = '\n'; 
    mat[2*N*N] = 0;
    if((out_t = fopen("out.txt", "w"))==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    } 

    for(int i = 0; i < 2*N*N; i++){
        putc(mat[i], out_t);
    } // выводим в выходной файл матрицу
    printf(mat); 
    int arr[N][N];
    for (int i = 0; i < N; i++){
        int k = 2 * i * N;
        for( int j = 0; j < 2 * N; j = j + 2){
            arr[i][j / 2] = mat[j + k] - '0';
        }
    } // преобразовуем матрицу в int для расчетов

    int a[N];
    for(int i = 0; i < N; i++){
        a[i] = arr[i][i]; // создаем массив для диагонали и присваиваем ему элементы нашей матрицы
    }
    for (int i = 0; i < N - 1; i++){
        for (int j = (N - 1); j > i; j--){
            if (a[j - 1] > a[j]){
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    } 
    char a_t[2*N]; 
    for(int i = 0; i < 2*N; i = i +2){
        itoa(a[i/2], &a_t[i], 10);
        a_t[i + 1] = *" "; 
    } // преобразовуем в char и записываем с учетом пробелов
    a_t[2*N-1] = 0; 
    putc('\n', out_t); 
    for(int i = 0; i < 2*N - 1; i++){
        putc(a_t[i], out_t);
    } // выходной файл принимает массив диагонали и записывает ее
    fclose(in_t);
    fclose(out_t); 
    return 0;
}