#include "List.hpp"
#include "MyPtr.hpp"

int main()
{
    List l1, l2, l3;
    vector<unique_ptr<List>> v_Trains;
    v_Trains.push_back(std::make_unique<List>(l1));
    v_Trains.push_back(std::make_unique<List>(l2));
    v_Trains.push_back(std::make_unique<List>(l3));

    for (vector<unique_ptr<List>>::iterator it = v_Trains.begin(); it != v_Trains.end(); it++)
    {
        it->get()->ReadFile("input.txt");

        cout << endl<< "Все поезда: " << endl;
        it->get()->PrintTrains();

        cout << endl<< "Все грузовые поезда из Украины: " << endl;
        it->get()->FreightFromUkr();
        cout << endl<< "Самый тяжелый поезд: " << endl;
        it->get()->MostHeavyFreight();
        cout << endl<< "Кол-во поездов с вагонами более 10 и которые требуют ремонта: " << it->get()->FindCountTrains() << endl;

        cout << endl<< "Отсортированные поезда: " << endl;
        it->get()->SortByNumber();
        it->get()->PrintTrains();
    }
    for(vector<unique_ptr<List>>::iterator it = v_Trains.begin()+1; it != v_Trains.end(); it++){
        v_Trains.begin()->get()->ConcVec((it)->get()->trains);
    }

    cout << "\n\n--------------------------------------------Вывод конкатенированных векторов--------------------------------------------\n" << endl;

    v_Trains.begin()->get()->PrintTrains();

    //Демонстрация работы собственного указателя

    // int *a=new int(5); 
    // MyPtr<int*> ptr(&a);
    // MyPtr<int*> ptr2(ptr);  //При неправильной работе указателя была б ошибка двойного освобождения памяти
    return 0;
}