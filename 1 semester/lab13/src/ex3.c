#define _CRT_SECURE_NO_WARNINGS //предназначен для работы strcpy
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#define N 10 

int main() {
    setlocale(LC_ALL, "Rus");

    const int SIZE = 41;
    char str[41] = "на улице уже зима поэтому скоро новый год";

    bool flag = true;
    char* res_arr = (char*)malloc(sizeof(char));
    int count_pairs = 0;
    char check_numb = 0;
    int count_check_numb;
    for (int i = 0; i < SIZE; i++)
    {
        for (int k = 0; k < count_pairs * 2; k += 2)
        {
            flag = true;
            if (*(res_arr + k) == *(str + i))
            {
                flag = false;
                k = count_pairs * 2;
            }


        }
        if (flag)
        {
            count_pairs++;
            check_numb = *(str + i);
            count_check_numb = 1;
            for (int j = i + 1; j < SIZE; j++)
            {
                if (check_numb == *(str + j))
                {
                    count_check_numb++;
                }

            }
            char *temp = (char*)malloc(sizeof(char) * count_pairs * 2);
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
    for (int i = 0; i < count_pairs * 2 - 2; i += 2) {
        //cout << "Символ " << (res_arr + i) << "Частота" << (int)(new_arr + i + 1) << endl;
        printf("Символ: ");
        printf("%c ", *(res_arr + i));
        printf("Частота: ");
        printf("%3.3f", (float)*(res_arr + i + 1)/100);
        printf("\n");
    }

    return 0;
}
