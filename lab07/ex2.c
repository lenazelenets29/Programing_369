	#include <stdlib.h>
   	#include <math.h>
    	#include <stdbool.h>
    
    	#define SIZE 23
    
    int Count_word(char sentence[]); // обьявление функции

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

