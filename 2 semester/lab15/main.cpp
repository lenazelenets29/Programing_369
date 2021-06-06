#include "List.hpp"

int main()
{
    List l1, l2, l3;
    vector<List> v_Trains{l1, l2, l3};

    for (vector<List>::iterator it = v_Trains.begin(); it != v_Trains.end(); it++)
    {
        it->ReadFile("input.txt");

        cout << endl<< "Все поезда: " << endl;
        it->PrintTrains();

        cout << endl<< "Все грузовые поезда из Украины: " << endl;
        it->FreightFromUkr();
        cout << endl<< "Самый тяжелый поезд: " << endl;
        it->MostHeavyFreight();
        cout << endl<< "Кол-во поездов с вагонами более 10 и которые требуют ремонта: " << it->FindCountTrains() << endl;

        cout << endl<< "Отсортированные поезда: " << endl;
        it->SortByNumber();
        it->PrintTrains();
    }
    for(vector<List>::iterator it = v_Trains.begin()+1; it != v_Trains.end(); it++){
        v_Trains.begin()->ConcVec((it)->trains);
    }

    cout << "\n\n--------------------------------------------Вывод конкатенированных векторов--------------------------------------------\n" << endl;

    v_Trains.begin()->PrintTrains();
    return 0;
}