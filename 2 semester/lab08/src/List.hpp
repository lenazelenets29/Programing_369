#include "Train.hpp"

class List //Класс-список
{
    Train** trains; //Массив указателей на указатели базового класса
    int size; //Размер массива

public:
    List(); //Конструктор по умолчанию
    List(const List &other); //Конструктор копирования
    ~List(); //Деструктор

    void ReadFile(string filename); //Чтение из файла
    void WriteFile(string filename); //Запись в файл
    
    void PrintTrains(); //Вывод на консоль

    int FindCountTrains(); //1 метод по работе с коллекцией

    void AddTrain( Train* object, int index ); //Добавление элемента в массив
    void DeleteTrain( int index ); //Удаление элемента из массива

};