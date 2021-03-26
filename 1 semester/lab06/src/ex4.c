	#include <stdlib.h>
    	#include <math.h>
    	#include <stdbool.h>
    
    	#define SIZE 23
    
    	int main() {
        char sentence[SIZE] = { " One  hundred  ninety  " };
        int count_word = 0;
        char placeholder = ' ';
        bool flag = false;
        for (int i = 0; i < SIZE; i++) {
            if (sentence[i] != placeholder && sentence[i]!= '\0') {
                flag = true;
                while (i <= SIZE && sentence[i + 1] != placeholder)
                    i++;
            }
            if (flag) {
                count_word++;
                flag = false;
            }
        }
     return 0;
 }
