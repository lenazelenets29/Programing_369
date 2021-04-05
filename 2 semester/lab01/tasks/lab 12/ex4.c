#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "fcntl.h"

int main() {
    int in_t, out_t; 
    char c_N[3]; // строка, указывающая размер матрицы
    if((in_t = open("in.txt", O_RDONLY))==-1) {
        printf("Cannot open file.\n");
        exit(1); // открытие файла
    }
    read(in_t, c_N, 3); // считываем из файла записанный размер матрицы
    int N = atoi(&c_N[0]); 
    char mat[2*N*N+N-2]; 
    read(in_t, mat, 2*N*N+N-2); 
    mat[2*N*N-1] = '\n'; 
    mat[2*N*N] = 0; 
    if((out_t = open("out.txt", O_WRONLY))==-1) {
        printf("Cannot open file.\n");
        exit(1); 
    }
    write(out_t, mat, 2*N*N); // записываем у выходящий файл матрицу 2*N*N размером

    int arr[N][N];
    for (int i = 0; i < N; i++){
        int k = 2 * i * N;
        for( int j = 0; j < 2 * N; j = j + 2){
            arr[i][j / 2] = mat[j + k] - '0';
        }
    } // преобразовуем матрицу в int
    int a[N];
    for(int i = 0; i < N; i++){
        a[i] = arr[i][i];
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
    for(int i = 0; i < 2 * N; i = i + 2){
        itoa(a[i/2], &a_t[i], 10);
        a_t[i + 1] = *" "; 
    } // преобразовуем матрицу с строки int в char
    a_t[2*N-1] = 0; 
    write(out_t, "\n", 1); 
    write(out_t, a_t, 2*N-1); 
    printf(mat); 
    close(in_t); 
    close(out_t); 
    return 0;
}