#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define N 10
int main() {
    srand(time(NULL));
    int count = 0;
    int temp = 0;
    bool flag = false;
    int start;
    int* arr = (int*)malloc(sizeof(int) * N);
    for (int j = 0; j < N; j++) {
        *(arr + j) = rand() % 30;
    }
    for (int i = 0; i < N - 1; i++) {
        if ((arr + i) < (arr + i + 1)) {
            if (!flag) {
                start = i;
            }
            flag = true;
            temp++;

        }
        else {
            if (temp > count)
            {
                count = temp;
            }
            flag = false;
        }

    }
    count++;
    int *res_arr = (int*)malloc(sizeof(int) * count);
    for (int i = start, j = 0; j <= count; i++, j++) {
        *(res_arr + j) = *(arr + i);
    }
    return 0;
}
