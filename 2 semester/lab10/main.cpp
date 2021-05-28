#include "FreightList.hpp"
#include "PassengerList.hpp"

int main(){
    //Демонстрация всех перегруженных операторов
    FreightList fr_list;
    PassengerList ps_list;

    fr_list.ReadFile("inputFreight.txt");
    ps_list.ReadFile("inputPassenger.txt");
    
    fr_list.PrintTrains();
    cout<<endl<<endl;

    ps_list.PrintTrains();
    cout<<endl<<endl;
    
    return 0;
}