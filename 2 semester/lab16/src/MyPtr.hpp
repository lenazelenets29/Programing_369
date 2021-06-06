#include "lib.hpp"

template<typename T>
class MyPtr{
    T *ptr;  //Указатель
    int cnt; //Счетчик указателей 
public:
    MyPtr(T *ptr){
        this->ptr = ptr;
        cnt = 1;
        cout << "\nВызвался конструктор" << endl;
    }
    MyPtr(const MyPtr &other){
        this->ptr=other.ptr;
        this->cnt=other.cnt+1;  //При копировании счетчик увеличивается
        cout << "\nВызвался конструктор копирования" << endl;
    }
    ~MyPtr(){
        if (cnt == 1) {  //Деструктор очистит память только если это последний указатель
            delete *ptr; 
            cout << "\nВызвался деструктор" << endl;
        }
        cnt--; //Счетчик уменьшается
    }
    T& operator*(){
        return *ptr;
    }
    T& operator->(){
        return ptr;
    }
};