	#include <stdlib.h>
    	#include <time.h>
    	int main() {
         
        char a[4][15];
     
        char thousand[12][15] = { "One thousand","Two thousand ","Three thousand","Four thousand ","Five thousand ","Six thousand ","Seven thousand ","Eight thousand ","Nine thousand " };
        char hundreds[12][15] = { "Hundred ","Two hundred " ,"Three hundred ","Four hundred ","Five hundred ","Six hundred ","Seven hundred ","Eight hundred ","Nine hundred " };
        char dozens[11][15] = { "twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety " };
        char units[20][15] = { "zero ","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ", "eleven ","twelve ","thirteen ","fourteen ","ifteen ","sixteen ","seventeen ","eighteen ","nineteen " };
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                a[i][j]=' ';
            }
        }
        
        int number = 1399; 
        int i = 0;
    

        for(int j = 0; j < 15; j++){
             a[0][j] = thousand[number/1000-1][j];
             a[1][j] = hundreds[number % 1000/100-1][j];
             a[2][j] = dozens[number % 100/10-2][j];
             if(number % 100 >= 10 & number % 100 < 20){
                 a[3][j] = units[number % 100][j];
             } else{
                 a[3][j] = units[number % 10][j];
             }
        }
        return 0;
    }
