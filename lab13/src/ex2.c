#define _CRT_SECURE_NO_WARNINGS // предназначен для работы strcpy
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#define N 10 
int Count_words(char str[]);


int main() {
    setlocale(LC_ALL, "Rus");

    int SIZE = 50;
    char str[] = "Иванов,Семенов,Семенов,Петров,Иванов";
    char element[] = ",";
    int count_words = Count_words(str);
    char** words = (char**)malloc(sizeof(char*) * count_words);
    char* temp = strtok(str, element);

    int i = 0;
    while (temp != NULL)
    {
        *(words + i) = temp;
        i++;
        temp = strtok(NULL, element);

    }

    for (int i = 0; i < count_words; ++i) {
        for (int j = i + 1; j < count_words; ++j) {
            if (!strcmp(words[j], words[i])) {
                words[j] = words[--count_words]; // дикремент
                --j;
            }
        }
    }

    for (int i = 0; i < count_words; i++)
    {
        printf("%s ", *(words + i));
    }
    return 0;
}

int Count_words(char str[])
{
    char* start = &str[0];
    bool flag = true;
    bool space = true;
    int count_word = 0;
    while (flag)
    {
        start++;
        if (*start == ' ' || *start == '.' || *start == ',' || *start == '!' || *start == '?' || *start == ',' || *start == '\0')
        {
            space = true;
            while (space)
            {
                if (!(*start == ' ' || *start == '.' || *start == ',' || *start == '!' || *start == '?' || *start == ',') || *start == '\0')
                    space = false;
                else
                    start++;
            }
            count_word++;
        }

        if (*start == '\0')
            flag = false;
    }



    return count_word;

}
