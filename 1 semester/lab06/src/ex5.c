#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(){
    int array[SIZE][SIZE] = {{1, 2, 3, 4, 5},
                            {6, 7, 8, 9, 10},
                            {11, 12, 13, 14, 15},
                            {16, 17, 18, 19, 20},
                            {21, 22, 23, 24, 25}};

    int aps[SIZE];

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            aps[i] = array[j][0];
            i++;
        }
    }

    for(int a = 0; a < (SIZE-1); a++){
        for(int b = 0; b < (SIZE - 1); b++){
            array[a][b] = array[a][b + 1];
            
        }
    }

    for (int c = 0; c < SIZE; c++){
        for (int d = 0; d < SIZE; d++){
            array[c][SIZE - 1] = aps[d];
            c++;
        }
    }
    return 0;
}
