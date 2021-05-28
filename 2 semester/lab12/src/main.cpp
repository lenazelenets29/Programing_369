#include "Array.hpp"

int main(){
    Array a;
    int** arrays;
    int* res_arr;
    std::string filename;

    while(1){
        std::cout<<"Введите название файла для чтения: ";
        std::cin>>filename;
        std::cout<<std::endl;
        if(filename=="/exit")
            break;
        arrays = a.ReadFile(filename);
        
        res_arr = a.SumOfArrays(arrays);

        std::cout<<"Введите название файла для вывода: ";
        std::cin>>filename;
        std::cout<<std::endl;
        if(filename=="/exit")
            break;
        a.WriteOut(filename, res_arr);
    }
    
    a.FreeMemory(arrays, res_arr);
    return 0;
}