#include "List.hpp"

int main(){
    List list;

    list.ReadFile("input.txt");
    
    cout<<endl<<"Все поезда: "<<endl;
    list.PrintTrains();

    cout<<endl<<"Все грузовые поезда из Украины: "<<endl;
    list.FreightFromUkr();
    cout<<endl<<"Самый тяжелый поезд: "<<endl;
    list.MostHeavyFreight();
    cout<<endl<<"Кол-во поездов с вагонами более 10 и которые требуют ремонта: "<<list.FindCountTrains()<<endl;
    return 0;
}