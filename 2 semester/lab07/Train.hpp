#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Train {
private:
    string number;
    char repairs;
    int carts;
    string start;
    string finish;
    string type;
public:

    Train();
    Train(string , char , int , string , string , string );
    Train(const Train& copy);
    virtual ~Train();

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

    void getCopy(Train copy);
    void printTrain() const;
};
