#include "BasicTrain.hpp"

BasicTrain::BasicTrain() : Train(){} // Вызвался конструктор по умолчанию базового класса 

BasicTrain::BasicTrain(string number, char repairs, int carts, string start, string finish, string type): Train(number, repairs, carts, start, finish, type){}

string BasicTrain::to_string() //Возврат данных всех полей класса в виде строки 
{
	stringstream result;

	result << getNumber() << " " << getRepairs() << " " << getCarts() << " " << getStart() << " " << getFinish() << " " << getType();

	return result.str();
}

Train* BasicTrain::from_string( string result2 ) //Разбитие строки на переменные и заполнение полей
{	
	BasicTrain* temp = new BasicTrain[1];
	stringstream result(result2);
    string number, start, finish, type; char repairs; int carts;

	result >> number >> repairs >> carts >> start >> finish >> type;
    
    temp->setNumber(number); temp->setRepairs(repairs); temp->setCarts(carts); temp->setStart(start); temp->setFinish(finish); temp->setType(type);
	return temp;
}