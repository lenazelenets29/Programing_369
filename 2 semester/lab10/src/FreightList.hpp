#include "FreightTrain.hpp"

class FreightList{ //Единственное отличие от списка базового класса - другой тип указателя
    FreightTrain** trains;
    int size;
public:
    FreightList();
    FreightList(const FreightList &other);
    ~FreightList();

    void ReadFile(string filename); //Чтение из файла
    void WriteFile(string filename); //Запись в файл
    
    void PrintTrains(); //Вывод на консоль

    void AddTrain( FreightTrain* object, int index ); //Добавление элемента в массив
    void DeleteTrain( int index ); //Удаление элемента из массива
};