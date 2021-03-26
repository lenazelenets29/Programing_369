#include <stdio.h>
int main() {
const int a = 3567;
const int n = 8;
int result;
int a1 = a/1000; // a1=3
int a2 = a/100%10; // a2=5
int a3 = a/10%10; // a3=6
int a4 = a%1000; // a3=7
result = a4*1 + a3*n + a2*n*n + a1*n*n*n;
return o;
}
