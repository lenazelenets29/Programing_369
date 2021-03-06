#include "Train.hpp"
#include "BasicTrain.hpp"
#include "PassengerTrain.hpp"
#include "FreightTrain.hpp"

class List //Класс-список
{
public:
    vector<Train*> trains; //Вектор указателей базового класса

    List(); //Конструктор по умолчанию
    List(const List &other); //Конструктор копирования
    ~List(); //Деструктор

    void ReadFile(string filename); //Чтение из файла
    void WriteFile(string filename); //Запись в файл
    
    void PrintTrains(); //Вывод на консоль

    int FindCountTrains(); //1 метод по работе с коллекцией
    int FreightFromUkr();  //2 метод по работе с коллекцией
    int MostHeavyFreight();  //3 метод по работе с коллекцией

    void AddTrain( Train* object, int index ); //Добавление элемента в массив
    void DeleteTrain( int index ); //Удаление элемента из массива

    void ConcVec(vector<Train*> v2);

    void SortByNumber();

    Train& operator[] (int index);
    Train& operator[] (int index) const;

    friend std::ostream& operator<< (std::ostream &out, const List &object);
    friend std::istream& operator>> (std::istream &in, List &object); 

    friend ofstream& operator<< (ofstream &out, const List &object);
    friend ifstream& operator>> (ifstream &in, List &object); 
};