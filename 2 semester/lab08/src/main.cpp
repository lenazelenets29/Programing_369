#include "List.hpp"


int main(){
    List list;
    
    list.ReadFile("input.txt");
    list.PrintTrains();

    cout<<"\n\n";

    list.DeleteTrain(1);
    list.PrintTrains();

    list.WriteFile("output.txt");

    cout<<"\nКоличество поездов с вагонами более 10 и которым нужен ремонт: "<<list.FindCountTrains()<<endl;
    return 0;
}