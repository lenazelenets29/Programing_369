#include <stdio.h>
int main() {
double original_a = 3;
double a;
a = original_a;
a *= a;
a *= a; // a^4
a = original_a;
a *= a;
a *= a;
a *= a; // a^8
a = original_a;
a = a*a*a;
a *= a; // a^6
a = original_a;
a *= a; // a^2
double b = a*a; // a^4
b *= b; // a^8
a *= b; // a^2*a^8=a^10
return o;
}
