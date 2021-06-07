#include "Train.hpp"

class FreightTrain : public Train{
    string cargo;
    int weight;
public:
    FreightTrain();
    FreightTrain(string number, char repairs, int carts, string start, string finish, string type, string cargo, int weight);

    string GetCargo();
    void SetCargo(string cargo);

    int GetWeight();
    void SetWeight(int weight);

    string to_string() override final;
    Train* from_string( string result ) override final;
};