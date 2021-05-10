#include <stdlib.h>
#include <stdio.h>
#define N 3
int main() {
    int** arr = (int**)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        *(arr + i) = (int*)malloc(sizeof(int) * N);
    }
    printf(" Автор: Зеленець Олена\n Лабораторна робота №12\n  Тема: Взаємодія з користувачем шляхом механізму введення/виведення\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int arr1;
            printf("Введіть число масиву: ");
            scanf("%d", &arr1);
            *(*(arr + i) + j) = arr1;           
        }
    }
    for (int i = 0; i < N; i++) { // выводит массив
        for (int j = 0; j < N; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n"); // перенос на новую строку
    }
    int res_arr[N] = { 0 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                *(res_arr + i) = *(*(arr + i) + j);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (*(res_arr + j) > *(res_arr + i)) {
                int temp = *(res_arr + j);
                *(res_arr + j) = *(res_arr + i);
                *(res_arr + i) = temp;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < N; i++){
            printf("%d ", *(res_arr + i));
    }
    return 0;
}
