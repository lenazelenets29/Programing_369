#include "Class.hpp"

class Class1: public Class{ //Класс-наследник
    int b;
public:
    Class1();
    Class1(double a, int b); //Конструктор с аргументом

    double GetValue() override;
};