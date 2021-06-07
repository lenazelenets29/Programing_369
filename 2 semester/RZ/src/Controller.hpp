#include "List.hpp"

class Controller{
   
public:
    List *list;
    Controller(List list);

    void ReadFile(string filename); //Чтение из файла
    void WriteFile(string filename); //Запись в файл
    
    void PrintTrains(); //Вывод на консоль

    int FindCountTrains(); //1 метод по работе с коллекцией
    int FreightFromUkr();  //2 метод по работе с коллекцией
    int MostHeavyFreight();  //3 метод по работе с коллекцией

    void ConcVec(vector<Train*> v2);

    void SortBy(int a);

    Train& operator[] (int index);
    Train& operator[] (int index) const;

    
}; 
