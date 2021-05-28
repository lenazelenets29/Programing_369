#include "Class.hpp"

Class::Class(){
    a=0;
}

Class::Class(double a){
    this->a=a;
}

double Class::GetValue(){
    return a;
}
void Class::SetValue(double a){
    this->a=a;
}