#include "PassengerTrain.hpp"

PassengerTrain::PassengerTrain() : Train(){ // Вызвался конструктор по умолчанию базового класса и к нему добавилась инициализация 2 полей
    this->ticket_price = 150; 
    this->seats = 100;
}
// Вызвался конструктор с аргументами базового класса и к нему добавилась инициализация 2 полей
PassengerTrain::PassengerTrain(string number, char repairs, int carts, string start, string finish, string type, int ticket_price, int seats) : Train(number, repairs, carts, start, finish, type){
    this->ticket_price = ticket_price;
    this->seats = seats;
}

int PassengerTrain::GetPrice(){
    return ticket_price;
}
void PassengerTrain::SetPrice(int ticket_price){
    this->ticket_price=ticket_price;
}

int PassengerTrain::GetSeats(){
    return seats;
}
void PassengerTrain::SetSeats(int seats){
    this->seats=seats;
}

string PassengerTrain::to_string() //Возврат данных всех полей класса в виде строки 
{
	stringstream result;

	result << getNumber() << " " << getRepairs() << " " << getCarts() << " " << getStart() << " " << getFinish() << " " << getType() << " " << ticket_price << " " << seats;

	return result.str();
}

Train* PassengerTrain::from_string( string result2 ) //Разбитие строки на переменные и заполнение полей
{	
    PassengerTrain* temp = new PassengerTrain;
	stringstream result(result2);
    string number, start, finish, type; char repairs; int carts, ticket_price, seats;

	result >> number >> repairs >> carts >> start >> finish >> type >> ticket_price >> seats;
    
    temp->setNumber(number); temp->setRepairs(repairs); temp->setCarts(carts); temp->setStart(start); temp->setFinish(finish); temp->setType(type); temp->SetPrice(ticket_price); temp->SetSeats(seats);
    return temp;
}