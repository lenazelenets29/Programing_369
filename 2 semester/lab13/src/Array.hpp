#include "stdio.h"
#include <string>
#include "stdlib.h"
#include <iostream>
#include "Class.hpp"

template<typename T>
class Array{
    int size;
    T *arr;
public:
    Array(){ //Конструктор по умолчанию
        size=0;
    }
    Array(const Array &other){ //Конструктор копирования
    this->arr = other.arr;
        for(int i=0;i<Array::size;i++){
            this->arr[i]=other.arr[i];
        }
    }
    ~Array(){ //Деструктор
        delete[] arr;
    }

    void AddEl(T el){ //Добавление элемента в массив
        T* temp = new T[size+1]; //Создание массива размером на 1 больше
        for(int i=0;i<size;i++){
            temp[i]=arr[i]; //Переписывание данных со старого массива в новый
        }
        temp[size]=el; //Запись нового элемента в конец 
        size++;
        arr=temp; //Смена указателя со старого массива но новый
    }

    void DeleteEl(int position){ //Удаление элемента из массива
        if(position>=size) //Если переданная позиция больше размера массива - удаляется последний элемент
            position=size-1;
        
        T *temp = new T[size-1]; //Создаем массив размеров на 1 меньше 
        for(int i=0;i<position;i++){
            temp[i]=arr[i]; //Переписывание всех элементов до позиции из старого массива в новый
        }
        for(int i=position;i<size-1;i++){ //Переписывание всех элементов после позиции из старого в новый
            temp[i]=arr[i+1];
        }

        size--;
        arr=temp; //Смена указателя со старого массива но новый
    }
    int Finder(T el){ //Поиск элемента
        for(int i=0;i<size;i++){ //Поиск по всему массиву
            if(arr[i]==el){//Если встретили искомый элемент
                std::cout<<"Элемент был найден в ячейке номер: "<<i<<std::endl;
                return i;
            }  
        }
    }
    void PrintArray(){ //Вывод массива
        for(int i=0;i<size;i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }
    
    void SortArray(){ //Сортировка пузырьком
        for(int i=0;i<size;i++){
            for(int j=0;j<size-i;j++){
                T temp;
                if(arr[j+1]){ //Если есть след элемент(что бы не выйти за пределы массива)
                    if(arr[j]>arr[j+1]){
                        temp=arr[j+1];
                        arr[j+1]=arr[j];
                        arr[j]=temp;
                    }
                } 
            }
        }
    }
    T FindMin(){ //Поиск минимального элемента в массиве 
        T min=arr[0]; // По дефолту минимальный - первый элемент
        for(int i=1;i<size;i++){
            if(min>arr[i]) //Если встретили меньше - замена
                min=arr[i];
        }
        return min;
    }
};

//Особая реализация для указателей на Класс(перегрузка шаблона)
//Аналогичная реализация как и выше, но для каждого элемента массива нужно вызвать метод GetValue()
template<>
class Array<Class*>{
    int size;
    Class **arr;
public:
    Array(){
        size=0;
    }
    Array(const Array &other){
    this->arr = other.arr;
        for(int i=0;i<Array::size;i++){
            this->arr[i]=other.arr[i];
        }
    }
    ~Array(){
        delete[] arr;
    }

    void AddEl(Class* el){
        Class** temp = new Class*[size+1];
        for(int i=0;i<size;i++){
            temp[i]=arr[i];
        }
        temp[size]=el;
        size++;
        arr=temp;
    }
    void DeleteEl(int position){
        if(position>=size)
            position=size-1;
        
        Class **temp = new Class*[size-1];
        for(int i=0;i<position;i++){
            temp[i]=arr[i];
        }
        for(int i=position;i<size-1;i++){
            temp[i]=arr[i+1];
        }

        size--;
        arr=temp;
    }
    void Finder(double el){
        for(int i=0;i<size;i++){
            if(arr[i]->GetValue()==el)
                std::cout<<"Элемент был найден в ячейке номер: "<<i<<std::endl;
        }
    }
    void PrintArray(){
        for(int i=0;i<size;i++){
            std::cout<<arr[i]->GetValue()<<" ";
        }
        std::cout<<std::endl;
    }
    
    void SortArray(){
        for(int i=0;i<size-1;i++){
            for(int j=0;j<size-1-i;j++){
                Class* temp;
                if(arr[j+1]){
                    if(arr[j]->GetValue()>arr[j+1]->GetValue()){
                        temp=arr[j+1];
                        arr[j+1]=arr[j];
                        arr[j]=temp;
                    }
                }
            }
        }
    }
    double FindMin(){
        double min=arr[0]->GetValue();
        for(int i=1;i<size;i++){
            if(min>arr[i]->GetValue())
                min=arr[i]->GetValue();
        }
        return min;
    }
};