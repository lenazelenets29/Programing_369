	#include <stdio.h>
    	#include <stdlib.h>
    	#include <math.h>
    	#define SIZE 3

    	int main(){
        float matrix[SIZE][SIZE] = {{3, 6, 9},
                                    {8, 3, 4},
                                    {2, 7, 5}};
        float matrix_result[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                matrix_result[i][j] = 0;
                    for (int a = 0; a < SIZE; a++)
                matrix_result[i][j] += matrix[i][a] * matrix[a][j];
            }
        }
        return 0;
     }
