#include "PassengerTrain.hpp"

class PassengerList{ //Единственное отличие от списка базового класса - другой тип указателя
    PassengerTrain** trains;
    int size;
public:
    PassengerList();
    PassengerList(const PassengerList &other);
    ~PassengerList();

    void ReadFile(string filename); //Чтение из файла
    void WriteFile(string filename); //Запись в файл
    
    void PrintTrains(); //Вывод на консоль

    void AddTrain( PassengerTrain* object, int index ); //Добавление элемента в массив
    void DeleteTrain( int index ); //Удаление элемента из массива
};