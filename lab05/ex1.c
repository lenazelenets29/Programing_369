int main(){
    int a = 60;
    int b = 288;
    int gcf; 
    while (a != 0 && b != 0)
    if (a > b) a = a%b;
    else b = b%a;
    gcf = (a + b);
    }
