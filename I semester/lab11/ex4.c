#include <stdlib.h>
#define N 3
int main() {
    int** arr = (int**)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        *(arr + i) = (int*)malloc(sizeof(int) * N);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(arr + i) + j) = rand() % 10;
        }
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
            if (*(res_arr + j) < *(res_arr + i)) {
                int temp = *(res_arr + j);
                *(res_arr + j) = *(res_arr + i);
                *(res_arr + i) = temp;
            }
        }
    }
    return 0;
}
