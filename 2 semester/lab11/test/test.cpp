#include "/home/lena/Lab/lab27/src/List.hpp"

void testFindCountTrains(){
    List test;
    test.ReadFile("input.txt");
    if(test.FindCountTrains()==3)
        cout<< "Тест Метода №1 по работе с коллекцией пройден успешно"<< endl;
    else 
        cout<< "Тест Метода №1 по работе с коллекцией провален"<< endl;
}

void testMostHeavyFreight(){
    List test;
    test.ReadFile("input.txt");
    if(test.MostHeavyFreight()==5)
        cout<< "Тест Метода №2 по работе с коллекцией пройден успешно"<< endl;
    else 
        cout<< "Тест Метода №2 по работе с коллекцией провален"<< endl;
}

void testFreightFromUkr(){
    List test;
    test.ReadFile("input.txt");
    if(test.FreightFromUkr()==3)
        cout<< "Тест Метода №3 по работе с коллекцией пройден успешно"<< endl;
    else 
        cout<< "Тест Метода №3 по работе с коллекцией провален"<< endl;
}

int main(){
    testFindCountTrains();
    testMostHeavyFreight();
    testFreightFromUkr();
    return 0;
}