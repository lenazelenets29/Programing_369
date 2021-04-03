#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[]) {
    int N = 3;
    char text[2 * N * N];
    int arr[N][N];
    printf("Enter your arr: ");
    gets(text);

    for (int i = 0; i < N; i++){
        int k = 2 * i * N;
        for( int j = 0; j < 2 * N; j = j + 2){
            arr[i][j / 2] = text[j + k] - '0';
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%i %c", arr[i][j], " ");
            if(j == N - 1){
                printf("\n");
            }
        }
    }

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

    char str_t[2 * N];
    for(int j = 0; j < 2 * N; j = j + 2){
        itoa(a[j / 2], &str_t[j], 10);
        str_t[j + 1] = *" ";
    }

    str_t[2 * N - 1] = 0;
    printf("\n");
    puts(str_t);

    return 0;
}
