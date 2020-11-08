#include <stdio.h>
int main() {
const int a = 369;
float info;
float a1 = a/100; //a1 = 3
float a2 = a%10; // a2 = 9
info = a1/a2; // 0,33333
info = info*100; // 33,33333
int figure = (int) info; // 33
float result = (float) figure; // 33,00000
result = result/100; // 0,3300000
return 0;
}
