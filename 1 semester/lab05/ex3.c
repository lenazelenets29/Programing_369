int main (){
    #define VALUES 144306    
    int A = VALUES;
    int sum1 = 0;
    int sum2 = 0;
    char tic;
    while (A/1000 > 0 ){
        sum1 += A%10;
        A /= 10;  
    }
    int N=A;
    while(N > 0 ){
    sum2 += N%10;
    N /= 10;
    }
    if(sum1==sum2) tic = 'Y';
    else tic = 'N';
    return 0;
}

