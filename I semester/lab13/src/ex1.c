#define _CRT_SECURE_NO_WARNINGS // предназначен для работы strcpy
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#define N 10 
int Count_words(char str[]);
char** Sort(char** words, int size);

int main() {
    setlocale(LC_ALL, "Rus");

    char str[] = "на улице уже зима поэтому скоро новый год";
    char element[] = " ";
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

    for (int i = 0; i < count_words; i++)
    {
        printf("%s ", *(words + i));
    }

    words = Sort(words, count_words);


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
        if (*start == ' ' || *start == '.' || *start == ',' || *start == '!' || *start == '?' || *start == '\0')
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


char** Sort(char** words, int size)
{

    bool sortF = false;
    char* temp = (char*)malloc(sizeof(char));
    for (int i = 1; i < size; i++)
        for (int j = 0; j < size - i; j++)
            if (strcmp(words[j], words[j + 1]) > 0) {
                temp = *(words + j);
                *(words + j) = *(words + j + 1);
                *(words + j + 1) = temp;
            }
    return words;
}
