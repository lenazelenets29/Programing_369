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

    cout<<endl<<"Отсортированные поезда: "<<endl;
    list.SortByNumber();
    list.PrintTrains();
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

    map<string, vector<string>> map1;
    map<string, vector<string>> map2;

    vector<string> uk {"Харків","Київ"};
    vector<string> ru {"Москва","Бєлгород"};
    vector<string> bl{"Мінськ","Бобруйськ",};

    map1.emplace("Україна", uk);
    map1.emplace("Росія", ru);
    map1.emplace("Білорусь", bl);

    vector<string> uk1{"Харків","Запоріжжя"};
    vector<string> ru1 {"Санкт-Петербург"};
    vector<string> pl{"Варшава"};

    map2.emplace("Польща", pl);
    map2.emplace("Росія", ru1);
    map2.emplace("Україна", uk1);

    for (map<string, vector<string>>::iterator it = map2.begin(); it != map2.end(); it++)   //парсинг по map2
    {
        bool is =true; //Флаг на встречание одинаковых ключей
        for (map<string, vector<string>>::iterator it1 = map1.begin(); it1 != map1.end(); it1++)     //парсинг по map1
        {
            if (it->first == it1->first)      //Если встретились одинаковые ключи
            {
                is=false;
                for(int i=0;i<it->second.size();i++){   //Парсинг вектора map2
                     bool empty=true;  //Флаг на встречание повтора городов
                     for(int j=0;j<it1->second.size();j++){    //Парсинг вектора map1
                        if(it->second[i]==it1->second[j])
                            empty=false;  //Если есть повтор городов
                     }
                     if(empty)  //Если нет повтора, то город добавляется в map1
                        it1->second.push_back(it->second[i]);
                 }
            }
        }
        if(is)  //Если нет повтора ключей, то полностью дублируется в map1
            map1.emplace(it->first, it->second);
    }


    for (map<string, vector<string>>::iterator it = map1.begin(); it != map1.end(); it++)
    {
        std::cout << it->first << ": ";
        for(int i=0;i<it->second.size();i++)
            cout<<it->second[i]<<", ";
        cout<<endl;
    }

    uk.clear();
    uk1.clear();
    ru.clear();
    ru1.clear();
    pl.clear();
    bl.clear();
    return 0;
}