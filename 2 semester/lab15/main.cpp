#include "src/List.hpp"

int main()
{
    List<Train*> list=List<Train*> ();

    list.ReadFile("input.txt");

    for(Train* &o : list){
        cout<<o->to_string()<<endl;
        cout << "------------------" << endl;
    }
    

    return 0;
}