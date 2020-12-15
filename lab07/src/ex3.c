#include <stdarg.h>
/ * *
*file ex3.c Реалізувати функцію, що визначає, скільки серед заданої послідовності чисел таких пар, у яких перше число менше наступного, використовуючи функцію з варіативною кількістю аргументів
* /
/ * *
* @param m кількість чисел варіативної функції
* /

int variable(int m, ...);

/ * *
головна функція {виклик варіативної функції з заданими числами}
* /

int main(){
    int count = variable(5, 7, 4, 9, -10, 11);
    return 0;
}

int variable(int m, ...){ // вызов функции
    int count = 0; //значение результата
    int b = 0;
    va_list temp;
    va_start (temp, m);
	b = va_arg(temp, int)
    for (int i = 1; i < m; i++){ 
        int c = va_arg(temp, int); 
        if(c < b){ 
            count++;
        }
     b = c;
    }
    va_end(temp); 
    return (count); 
}
