#include "/home/lena/Lab/lab25/src/List.hpp"


void testFindCountTrains(){
    List test;
    test.ReadFile("input.txt");
    if(test.FindCountTrains()==1)
        cout<< "Тест Метода №1 по работе с коллекцией пройден успешно"<< endl;
    else 
        cout<< "Тест Метода №1 по работе с коллекцией провален"<< endl;
}



int main(){
    testFindCountTrains();
    return 0;
}