int main(){
    int a = 9;
    int SUM = 0;
    for (int i=1; i<=a/2; ++i) {
        if (a%i==0) SUM += i; // i=1; SUM=1; i=3; SUM = 1+3
    }
    char add;
    if (add==a) add='Y';
    else add='N';
}

