#include "List.hpp"

Train& List::operator[] (int index)
{
    return *trains[index];
}
Train& List::operator[] (int index) const
{
    return *trains[index];
}

std::ostream& operator<< (std::ostream &out, const List &object)
{   
    int n = object.trains.size();

    for ( int i = 0; i < n; i++ )
    {
        out << object[i] << ( i != n - 1 ? "\n" : "" );
    }   

    return out;
}

std::istream& operator>> (std::istream &in, List &object)
{ 
    int n = object.trains.size();

    for ( int i = 0; i < n; i++ )
    {
        in >> object[i];
    }

    return in;
}

ofstream& operator<< (ofstream &out, const List &object)
{
    int n = object.trains.size();

    for ( int i = 0; i < n; i++ )
    {
        out << object[i] << ( i != n - 1 ? "\n" : "" );
    }   

    return out;
}

ifstream& operator>> (ifstream &in, List &object)
{
    int n = object.trains.size();

    for ( int i = 0; i < n; i++ )
    {
        in >> object[i];
    }

    return in;
}