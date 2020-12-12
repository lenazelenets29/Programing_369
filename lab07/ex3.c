#include <stdarg.h>

int variable(int m, ...);

int main(){
    int count = variable(5, 7, 4, 9, -10, 11);
    return 0;
}

int variable(int m, ...){ // вызов функции
    int count = 0; //значение результата
    int b = 0;
    va_list temp;
    va_start (temp, m);
    for (int i = 1; i < m; i++){ 
        va_arg(temp, int); 
        if(va_arg(temp, int) > b){ 
            count++;
        }
     b = va_arg(temp, int);
    }
    va_end(temp); 
    return (count); 
}
