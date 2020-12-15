	#include <stdlib.h>
   	#include <math.h>
    	#include <stdbool.h>
	#define SIZE 23
/ * *
*@file ex2.c Реалізувати код таким чином, щоб у заданому тексті знайти кільксть слів за умови, що між словами може бути будь-яка кількість пропусків
*/

/ * *
* @param sentence[] масив, у якому рахується кількість слів 
* /
    
int Count_word(char sentence[]); // обьявление функции
/ * * 
головна функція {задає текст і рахує в ньому кількість слів}
* /
int main() {
        char sentence[SIZE] = { " One  hundred  ninety  " };
        int count_word = Count_word(sentence);
        return 0;
    }
int Count_word(char sentence[]){
        int count_word = 0;
        char placeholder = ' ';
        bool flag = false;
        for (int i = 0; i < SIZE; i++) {
            if (sentence[i] != placeholder && sentence[i]!= '\0') {
                flag = true;
                while ((i + 1) < SIZE && sentence[i + 1] != placeholder && sentence[i + 1] != '\0')
                    i++;
            }
            if (flag) {
                count_word++;
                flag = false;
            }
        return count_word; 
        }
     }

