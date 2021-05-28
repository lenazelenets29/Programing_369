#include "/home/lena/Lab/lab28/src/Array.hpp"

void test_SumArray(){
    Array a;
    int** arrays;
    int* res_arr;

    arrays = a.ReadFile("input.txt");
    res_arr = a.SumOfArrays(arrays);
    
    if(res_arr[0]==21)
        std::cout<<"Тест SumArray №1 успешно завершен!"<<std::endl;
    else
        std::cout<<"Тест SumArray №1 провален"<<std::endl;
    
    if(res_arr[1]==8)
        std::cout<<"Тест SumArray №2 успешно завершен!"<<std::endl;
    else
        std::cout<<"Тест SumArray №2 провален"<<std::endl;

    if(res_arr[3]==6)
        std::cout<<"Тест SumArray №3 успешно завершен!"<<std::endl;
    else
        std::cout<<"Тест SumArray №3 провален"<<std::endl;

    a.FreeMemory(arrays, res_arr);
}


int main(){
    std::cout<<std::endl<<std::endl;

    test_SumArray();
    return 0;
}