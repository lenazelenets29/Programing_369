#define _CRT_SECURE_NO_WARNINGS //для работы strcpy
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#define N 10
#define SIZE 51


int main() {
    setlocale(LC_ALL, "Rus");

    char str[SIZE] = "н1а ули3це уж2е зи7ма поэ6том9у с4коро нов8ый 9го9д";

    bool flag = true;
    int count_numb = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if ((int)*(str + i) > 0 && (int)*(str + i) != (int)' ')
            count_numb++; // количество цифр
    }
    char* numb_arr = (char*)malloc(sizeof(char) * count_numb);
    for (int i = 0, j = 0; i < SIZE; i++)
    {
        if ((int)*(str + i) > 0 && (int)*(str + i) != (int)' ')
        {
            *(numb_arr + j) = *(str + i);
            j++; // запись в масив символов чисел (numb_arr)
        }
    }
    for (int i = 0; i < count_numb; i++)
        printf("%c ",*(numb_arr + i));
    free(numb_arr);
    return 0;
}
