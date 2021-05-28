#include "Train.hpp"

Train::Train(){ //Заполнение полей по умолчанию 
    this->number="A1000";
    this->repairs='n'; 
    this->carts=10; 
    this->route.start="Ukraine"; 
    this->route.finish="Russia"; 
    this->type="heat";
}

Train::Train(string number, char repairs, int carts, string start, string finish, string type){
    this->number=number; //Заполнение полей переданными переменными
    this->repairs=repairs; 
    this->carts=carts; 
    this->route.start=start; 
    this->route.finish=finish; 
    this->type=type;
}

string Train::getNumber() const { return number; };
void Train::setNumber(const string num) { number = num; };

char Train::getRepairs() const { return repairs; };
void Train::setRepairs(const char rep) { repairs = rep; };

int Train::getCarts() const { return carts; };
void Train::setCarts(const int car) { carts = car; };

string Train::getStart() const { return route.start; };
void Train::setStart(const string st) { route.start = st; };

string Train::getFinish() const { return route.finish; };
void Train::setFinish(const string fin) { route.finish = fin; };

string Train::getType() const { return type; };
void Train::setType(const string typ) { type = typ; };

string Train::to_string() //Возврат данных всех полей класса в виде строки 
{
	stringstream result;

	result << number << " " << repairs << " " << carts << " " << route.start << " " << route.finish << " " << type;

	return result.str();
}

void Train::from_string( string result2 ) //Разбитие строки на переменные и заполнение полей
{	
	stringstream result(result2);

	result >> number >> repairs >> carts >> route.start >> route.finish >> type;
}