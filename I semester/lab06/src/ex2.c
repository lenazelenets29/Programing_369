#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	const int SIZE = 5;
	int a[SIZE]; 
	int n;
	bool flag = false;
	for (int i = 0; i < SIZE;) {
		n = rand() % 100;
		const double eps=0.01;
		double m=0;
		while(m * m <n){
		m+=eps;
        };
        m = m;
	for (int j = 2; j < n; j++) {
		if (n % j != 0) {
                flag = true;
            }
            else{
                flag = false;
                j = m;
            }
        }
        if (flag)
        {
            a[i++] = n;
            flag = false;
        } 
    }
    return 0;
}
