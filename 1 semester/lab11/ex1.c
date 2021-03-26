#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define N 10
int main() {
    srand((unsigned int)time(NULL));
    // int* arr = (int*)malloc(sizeof(int) * N);
    int arr[N] = { 0 };
    for (int j = 0; j < N; j++) {
        *(arr + j) = rand() % 10;
    }
    bool flag = true;
    int *res_arr = (int*)malloc(sizeof(int) * N);
    int count_pairs = 0;
    int check_numb = 0;
    int count_check_numb;
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < count_pairs * 2; k += 2)
        {
            flag = true;
            if (*(res_arr + k) == *(arr + i))
            {
                flag = false;
                k = count_pairs * 2;
            }
        }
        if (flag)
        {
            count_pairs++;
            check_numb = *(arr + i);
            count_check_numb = 1;
            for (int j = i + 1; j < N; j++)
            {
                if (check_numb == *(arr + j))
                {
                    count_check_numb++;
                }

            }
            int *temp = (int*)malloc(sizeof(int) * count_pairs * 2);
            for (int l = 0; l < count_pairs * 2; l++)
            {
                *(temp + l) = *(res_arr + l);
            }
            res_arr = temp;
            if (count_pairs == 1)
            {
                *(res_arr + count_pairs - 1) = check_numb;
                *(res_arr + count_pairs) = count_check_numb;
            }
            else
            {
                *(res_arr + count_pairs * 2 - 2) = check_numb;
                *(res_arr + count_pairs * 2 - 1) = count_check_numb;
            }
        }
    }
    return 0;
}
