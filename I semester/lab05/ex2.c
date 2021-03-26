#include <math.h>
#include<stdbool.h>

int main(){
    int N = 13;
    char ans;
    if(N==1) ans ='N';
    else{
        int sqrt_t = sqrt(N)+1;
        bool flag = true;
        for(int i=2; i<sqrt_t; i++){
            if(N%i==0){
                flag=false;
                break;
            }
        }
        if(flag)
           ans = 'Y';
        else
        {
            ans = 'N';
        }

    }
}

