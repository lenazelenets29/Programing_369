#include "Train.hpp"

class BasicTrain : public Train{

public:
    BasicTrain();
    BasicTrain(string number, char repairs, int carts, string start, string finish, string type);

    string to_string() override final;
    Train* from_string( string result ) override final;
};