#include "Train.hpp"

void Train::operator =(const Train &object)
{
    this->number=object.number; 
    this->repairs=object.repairs; 
    this->carts=object.carts; 
    this->route.start=object.route.start; 
    this->route.finish=object.route.finish; 
    this->type=object.type;
}

bool Train::operator ==(const Train &object)
{
    return this->number == object.number
    && this->repairs == object.repairs
    && this->carts == object.carts
    && this->route.start == object.route.start
    && this->route.finish == object.route.finish
    && this->type == object.type;
}

bool Train::operator !=(const Train &object)
{
    return !(*this == object);
}

bool Train::operator <(const Train &object)
{
    return this->number < object.number
    && this->repairs < object.repairs
    && this->carts < object.carts
    && this->route.start < object.route.start
    && this->route.finish < object.route.finish
    && this->type < object.type;
}

bool Train::operator >(const Train &object)
{
    return !(*this < object);
}

bool Train::operator <=(const Train &object)
{
    return this->number <= object.number
    && this->repairs <= object.repairs
    && this->carts <= object.carts
    && this->route.start <= object.route.start
    && this->route.finish <= object.route.finish
    && this->type <= object.type;
}

bool Train::operator >=(const Train &object)
{
    return !(*this <= object);
}

std::ostream& operator<< (std::ostream &out, const Train &object)
{   
    out << object.number << " " << object.repairs << " " << object.carts << " " 
    << object.route.start << " " << object.route.finish << " " << object.type;
    return out;
}

std::istream& operator>> (std::istream &in, Train &object)
{
    in >> object.number >> object.repairs >> object.carts >> object.route.start >> object.route.finish >> object.type ; 
    return in;
}