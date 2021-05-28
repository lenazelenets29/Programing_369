#include "Train.hpp"

class PassengerTrain : public Train{
    int ticket_price;
    int seats;
public:
    PassengerTrain();
    PassengerTrain(string number, char repairs, int carts, string start, string finish, string type, int ticket_price, int seats);

    int GetPrice();
    void SetPrice(int ticket_price);

    int GetSeats();
    void SetSeats(int seats);

    string to_string();
    void from_string( string result );
};