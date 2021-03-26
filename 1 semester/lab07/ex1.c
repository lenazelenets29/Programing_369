/** 
	* @file ex1.c Реалізувати код, який допоможе визначити  чи є 6-значне число "щасливим квитком"("щасливий квиток" - це квиток, у яком сума першої половини чисел номера дорівнює сумі другої половини).
*/

/** 
	* Перевірка 6-значного числа
	* @param A дане число
*/
int calculate(int A);
/**
	головна функція {Оголосити число, викликати функцію, що перевіряє наше число, вивести результат перевірки}
*/

int main (){
    int A = 144304;
    char tic;
    int sum1 = 0;
    int sum2 = 0;
    int result = 0;
    result = calculate(A);
    if(result = 1){
        tic = 'Y';
    }
    else if(result = 0){
        tic = 'N';
    }
    return 0;
}

int calculate(int A){
    int sum1 = 0;
    int sum2 = 0;
    while (A/1000 > 0 ){
        sum1 += A%10;
        A /= 10;
    }
    int N=A;
    while(N > 0 ){
    sum2 += N%10;
    N /= 10;
    }
    int result;
    if (sum1 == sum2){
        result = 1;
    }
    else if(sum1 != sum2){
        result = 0;
    }
    return result;
}

