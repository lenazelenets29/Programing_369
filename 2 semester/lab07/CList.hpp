#include "Train.hpp"

class CList {
private:
    int lenght;
    Train **data;
public:

    CList();
    CList(int );
    ~CList();
    
    void addTrain(Train &train);
    void removeTrain(int );
    Train& getTrain(int );
    Train* Metod1(char , int );
    void showAll();
};