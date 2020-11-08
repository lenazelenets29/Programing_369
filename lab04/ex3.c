#include <math.h>
int main()
{
int k = 3;
int m = -1;
int n = 9;
int a = 0;
if (k>=m){
a = k;
k = m;
m = a;
}
else if (k>=n){
a = k;
k = n;
n = a;
}
if (m>=n){
a = m;
m = n;
n = a;
}
return 0;
}
