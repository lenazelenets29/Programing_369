#include <iostream>
#include "CList.hpp"
#include <cstdbool>

bool test_metod1();
bool test_get_train();

using namespace std;

int main(){
    bool result = true;
    if(test_metod1()){
        result &= true;
        cout << "Test_metod1 passed!" << endl;
    } else {
        result &= false;
        cout << "Error!" << endl;
    }
    if(test_get_train()){
        result &= true;
        cout << "Test_get_train passed!" << endl;
    } else {
        result &= false;
        cout << "Error!" << endl;
    }
    if(result){
        cout << "All tests passed!" << endl;
    } else {
        cout << "Error!" << endl;
    }
    
    CList list(9);
    Train poezd1;
    Train poezd_copy("A1001", 'n', 100, "Ukr", "Rus", "elec");
    Train poezd2(poezd_copy);
    Train poezd3("A1003", 'y', 15, "Rus", "Ger", "heat");
    list.addTrain(poezd1);
    list.addTrain(poezd2);
    list.addTrain(poezd3);
    cout << "All trains: " << endl; 
    list.showAll();
    cout << "Metod 1:" << endl;
    list.Metod1('y', 10);
    cout << "Get second train:" << endl;
    poezd1 = list.getTrain(1);
    poezd1.printTrain();
    cout << "Remove first train: " << endl;
    list.removeTrain(0);
    list.showAll();

    return 0;
}

bool test_metod1(){
    bool result = true;
    CList list(9);
    Train poezd1;
    Train poezd_copy("A1001", 'n', 100, "Ukr", "Rus", "elec");
    Train poezd2(poezd_copy);
    Train poezd3("A1003", 'y', 15, "Rus", "Ger", "heat");
    list.addTrain(poezd1);
    list.addTrain(poezd2);
    list.addTrain(poezd3);
    Train *exp = new Train[2] { poezd1, poezd3 };
    Train *act = new Train[2];
    act = list.Metod1('y', 10);

    for(int i = 0; i < 2; i++){
        if(act[i + 1].getNumber() != exp[i].getNumber() || act[i + 1].getRepairs() != exp[i].getRepairs() || act[i + 1].getCarts() != exp[i].getCarts() || act[i + 1].getStart() != exp[i].getStart() || act[i + 1].getFinish() != exp[i].getFinish() || act[i + 1].getType() != exp[i].getType()){
            result = false;
        }
    }
    delete[] exp;
    delete[] act;
    return result;
}

bool test_get_train(){
    bool result = true;
    CList list(9);
    Train poezd1;
    Train poezd_copy("A1001", 'n', 100, "Ukr", "Rus", "elec");
    Train poezd2(poezd_copy);
    Train poezd3("A1003", 'y', 15, "Rus", "Ger", "heat");
    list.addTrain(poezd1);
    list.addTrain(poezd2);
    list.addTrain(poezd3);
    Train exp("A1003", 'y', 15, "Rus", "Ger", "heat");
    Train act(list.getTrain(2));
    if(act.getNumber() != exp.getNumber() || act.getRepairs() != exp.getRepairs() || act.getCarts() != exp.getCarts() || act.getStart() != exp.getStart() || act.getFinish() != exp.getFinish() || act.getType() != exp.getType()){
        result = false;
    }
    return result;
}