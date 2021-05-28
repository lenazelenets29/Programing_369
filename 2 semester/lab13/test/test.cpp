#include "/home/lena/Lab/lab29/src/Array.hpp"

void test_Finder(){
    Array<int> a;
    for(int i=0; i<7;i++)
        a.AddEl(i+1);
    int result = a.Finder(4);
    if(result==3)
        std::cout<<"Тест Finder() пройден успешно!\n";
    else
        std::cout<<"Тест Finder() провален\n";
}

void test_FindMin(){
    Array<int> a;
    for(int i=0; i<7;i++)
        a.AddEl(i+1);
    int result = a.FindMin();
    if(result==1)
        std::cout<<"Тест FindMin() пройден успешно!\n";
    else
        std::cout<<"Тест FindMin() провален\n";
}

int main(){
    std::cout<<std::endl<<std::endl;

    test_Finder();
    test_FindMin();
    return 0;
}