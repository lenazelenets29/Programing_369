#ifndef _LAB_29_
#define _LAB_29_

class Class{ //Примитивный класс-родитель
    double a; //какое-то число
public:
    Class();
    Class(double a);
    virtual double GetValue();
    void SetValue(double a);
};

#endif