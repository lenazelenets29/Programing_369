#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define N 10
int main() {
    srand(time(NULL));
    int* arr = (int*)malloc(sizeof(int) * N);
    for (int j = 0; j < N; j++) {
        *(arr + j) = rand() % 61 - 30;
    }
    int sum = 0;
    bool flag = false;
    int start;
    int size = 0;
    int count_sum = 0;
    int* size_arr = (int*)malloc(sizeof(int));
    int* sum_arr = (int*)malloc(sizeof(int));
    for (int i = 0; i < N; i++) {
        if (*(arr + i) > 0) {
            if (!flag) {
                count_sum++;
                start = i;
                int* temp = (int*)malloc(sizeof(int) * count_sum);
                int* temp_s = (int*)malloc(sizeof(int) * count_sum);
                for (int n = 0; n < (count_sum - 1); n++) {
                    *(temp + n) = *(sum_arr + n);
                    *(temp_s + n) = *(size_arr + n);
                }
                size_arr = temp_s;
                sum_arr = temp;
            }
            size++;
            flag = true;
            sum += *(arr + i);

        }
        else {
            if (flag)
            {
                *(sum_arr + count_sum - 1) = sum;
                *(size_arr + count_sum - 1) = size;
            }
            flag = false;
        }
        if (!flag) {
            sum = 0;
            size = 0;
        }
    }
    if (flag)
    {
        *(sum_arr + count_sum - 1) = sum;
        *(size_arr + count_sum - 1) = size;
    }
    int max_value = *sum_arr;
    start = 0;
    for (int i = 0; i < count_sum; i++)
    {
        if (max_value < *(sum_arr + i))
        {
            max_value = *(sum_arr + i);
            start = i;
        }
    }
    int* res_arr = (int*)malloc(sizeof(int) * *(size_arr + start));
    for (int i = 0, j = 0, k = 0; i < N; i++)
    {
        if (*(arr + i) > 0) {
            if (!flag && start != 0) {
                j++;
            }
            if (j == start)
            {
                *(res_arr + k) = *(arr + i);
                k++;
            }
            flag = true;
        }
        else {
            flag = false;
        }
    }
    return 0;
}
