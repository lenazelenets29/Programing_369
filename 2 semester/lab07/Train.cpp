#include "Train.hpp"

using namespace std;

Train::Train(){
    cout << "~ Default constructor ~" << endl;
    number = "A1000";
    repairs = 'y';
    carts = 50;
    start = "Ukraine";
    finish = "Russia";
    type = "heat";
}

Train::Train(string numb, char rep, int car, string st, string fin, string typ){
    cout << "~ Parameter-based constructor ~"<< endl;
    number = numb;
    repairs = rep;
    carts = car;
    start = st;
    finish = fin;
    type = typ;
}

Train::Train(const Train& copy){
    cout << "~ Copy-constructor ~"<< endl;
    number = copy.number;
    repairs = copy.repairs;
    carts = copy.carts;
    start = copy.start;
    finish = copy.finish;
    type = copy.type;
}

Train::~Train() {
    cout << "~ Destructor ~"<< endl;
}

void Train::printTrain () const {
    cout << number << " " << repairs << " " << carts << " " << start << " " << finish << " " << type << endl;
}

string Train::getNumber() const { return number; };
void Train::setNumber(const string num) { number = num; };

char Train::getRepairs() const { return repairs; };
void Train::setRepairs(const char rep) { repairs = rep; };

int Train::getCarts() const { return carts; };
void Train::setCarts(const int car) { carts = car; };

string Train::getStart() const { return start; };
void Train::setStart(const string st) { start = st; };

string Train::getFinish() const { return finish; };
void Train::setFinish(const string fin) { finish = fin; };

string Train::getType() const { return type; };
void Train::setType(const string typ) { type = typ; };

void Train::getCopy(Train copy){
    number = copy.number;
    repairs = copy.repairs;
    carts = copy.carts;
    start = copy.start;
    finish = copy.finish;
    type = copy.type;
}