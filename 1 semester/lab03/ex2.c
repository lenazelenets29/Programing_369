#include <stdio.h>
int main() {
const int a = 249;
int result;
int a1 = a/100; // a=2
int a2 = a%10; //a=9
int a3 = a/10%10; // a=4
result = a2*100 + a3*10 + a1;
return 0;
}
