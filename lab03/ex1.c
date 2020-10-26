#include <stdio.h>
int main() {
#define r1 3
#define r2 6
#define r3 9
float R;
R = (r1*r2*r3)/(1*r2*r3 + 1*r1*r3 + 1*r1*r2);
return 0;
}
