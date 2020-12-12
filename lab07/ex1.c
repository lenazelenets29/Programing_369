int calculate(int A);

int main (){
    int A = 144304;
    char tic;
    int sum1 = 0;
    int sum2 = 0;
    int result = 0;
    result = calculate(A);
    if(result = 1){
        tic = 'Y';
    }
    else if(result = 0){
        tic = 'N';
    }
    return 0;
}

int calculate(int A){
    int sum1 = 0;
    int sum2 = 0;
    while (A/1000 > 0 ){
        sum1 += A%10;
        A /= 10;
    }
    int N=A;
    while(N > 0 ){
    sum2 += N%10;
    N /= 10;
    }
    int result;
    if (sum1 == sum2){
        result = 1;
    }
    else if(sum1 != sum2){
        result = 0;
    }
    return result;
}

