#include "lib.hpp"

class Train //Базовый класс
{
private: //Поля базового класса
    struct Route{  //Вложенная структура 
        string start;
        string finish;
    };
    string number;
    char repairs;
    int carts;
    struct Route route;
    string type;

public:
    Train(); //Конструктор по умолчанию
    Train(string number, char repairs, int carts, string start, string finish, string type); //Конструктор с аргументами

    string getNumber() const;
    void setNumber(const string num);

    char getRepairs() const;
    void setRepairs(const char rep);

    int getCarts() const;
    void setCarts(const int car);

    string getStart() const;
    void setStart(const string st);

    string getFinish() const;
    void setFinish(const string fin);

    string getType() const;
    void setType(const string typ);

    string to_string();
    void from_string( string result );
};
