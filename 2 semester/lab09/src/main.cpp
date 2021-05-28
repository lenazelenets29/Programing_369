#include "List.hpp"


int main(){
    //Демонстрация всех перегруженных операторов
    List list;
    Train temp;

    list.ReadFile("input.txt");
    
    ifstream train ("input.txt");
    train>>list;
    cout<<list<<endl<<endl;

    temp = list[1];
    cout<<endl;
    cout << temp <<endl<<endl;
    return 0;
}