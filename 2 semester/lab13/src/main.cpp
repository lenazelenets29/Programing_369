#include "Array.hpp"
#include "Class.hpp"
#include "Class1.hpp"

int main(){
    srand(time(0));

    //Реализация для демонстрации работы всех методов

    std::cout<<"----------------------------------------Работа с простыми числами типа  int----------------------------------------"<<std::endl;
    Array<int> in;
    for(int i=0;i<10;i++)
        in.AddEl(rand()%10);
    std::cout<<"Массив заполнен"<<std::endl;
    in.PrintArray();

    std::cout<<"\nУдаление 1 элемента"<<std::endl;
    in.DeleteEl(1);
    in.PrintArray();

    std::cout<<"\nМинимальный элемент в массиве: "<<in.FindMin()<<std::endl;

    std::cout<<"\nПоиск элемента `3`"<<std::endl;
    in.Finder(3);

    std::cout<<"\nСортировка массива"<<std::endl;
    in.SortArray();
    in.PrintArray();
   std::cout<<"----------------------------------------Работа с простыми числами типа  double----------------------------------------"<<std::endl;
    Array<double> db;
    for(int i=0;i<10;i++)
        db.AddEl(rand()%10+0.1);
    std::cout<<"Массив заполнен"<<std::endl;
    db.PrintArray();

    std::cout<<"\nУдаление 5 элемента"<<std::endl;
    db.DeleteEl(5);
    db.PrintArray();

    std::cout<<"\nМинимальный элемент в массиве: "<<db.FindMin()<<std::endl;

    std::cout<<"\nПоиск элемента `3.1`"<<std::endl;
    db.Finder(3.1);

    std::cout<<"\nСортировка массива"<<std::endl;
    db.SortArray();
    db.PrintArray();
    
 /*
    std::cout<<"----------------------------------------Работа с Классами----------------------------------------"<<std::endl;
    Array<Class*> a;

    Class c(5.15);
    a.AddEl(&c);
    Class c1(3.15);
    a.AddEl(&c1);
    Class c2(2.1);
    a.AddEl(&c2);
    Class c3(9.99);
    a.AddEl(&c3);
    std::cout<<"Массив заполнен"<<std::endl;
    a.PrintArray();
    std::cout<<"Добавление класса-наследника"<<std::endl;
    Class1 cc(3.1, 2);
    a.AddEl(&cc);
    a.PrintArray();

    std::cout<<"\nУдаление 2 элемента"<<std::endl;
    a.DeleteEl(2);
    a.PrintArray();

    std::cout<<"\nМинимальный элемент в массиве: "<<a.FindMin()<<std::endl;

    std::cout<<"\nПоиск элемента `2.1`"<<std::endl;
    a.Finder(2.1);

    std::cout<<"\nСортировка массива"<<std::endl;
    a.SortArray();
    a.PrintArray();
    */

    return 0;
}