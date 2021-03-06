#include "FreightTrain.hpp"

FreightTrain::FreightTrain() : Train(){ // Вызвался конструктор по умолчанию базового класса и к нему добавилась инициализация 2 полей
    this->cargo = "Wood";
    this->weight = 10000;
}
// Вызвался конструктор с аргументами базового класса и к нему добавилась инициализация 2 полей
FreightTrain::FreightTrain(string number, char repairs, int carts, string start, string finish, string type, string cargo, int weight) : Train(number, repairs, carts, start, finish, type){
    this->cargo = cargo;
    this->weight = weight;
}

string FreightTrain::GetCargo(){
    return cargo;
}
void FreightTrain::SetCargo(string cargo){
    this->cargo=cargo;
}

int FreightTrain::GetWeight(){
    return weight;
}
void FreightTrain::SetWeight(int weight){
    this->weight=weight;
}

string FreightTrain::to_string() //Возврат данных всех полей класса в виде строки 
{
	stringstream result;

	result << getNumber() << " " << getRepairs() << " " << getCarts() << " " << getStart() << " " << getFinish() << " " << getType() << " " << cargo << " " << weight;

	return result.str();
}

void FreightTrain::from_string( string result2 ) //Разбитие строки на переменные и заполнение полей
{	
	stringstream result(result2);
    string number, start, finish, type; char repairs; int carts;

	result >> number >> repairs >> carts >> start >> finish >> type >> cargo >> weight;
    
    setNumber(number); setRepairs(repairs); setCarts(carts); setStart(start);setFinish(finish); setType(type);
}