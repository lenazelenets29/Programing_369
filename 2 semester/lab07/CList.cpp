#include "CList.hpp"

CList::CList(){
    lenght = 0;
    data = new Train*[lenght];
}

CList::CList(int len){
    lenght = 0;
    data = new Train*[len];
}

CList::~CList(){
	delete[] data;
}

void CList::addTrain(Train &train){
    lenght++;
    data[lenght - 1] = new Train(train);
}

void CList::removeTrain(int index){
    for(int i = index; i < lenght - 1; i++){
        data[i] = data[i + 1];
    }
    lenght--;
}

Train& CList::getTrain(int index){return *data[index];}

void CList::showAll(){
    for(int i = 0; i < lenght; i++){
        data[i]->printTrain();
    }
}

Train* CList::Metod1(char rep, int car){
    int k = 0;
    for(int i = 0; i < lenght; i++){
        if(rep == data[i]->getRepairs() && car < data[i]->getCarts()){ k++; }
    }
    Train * temp = new Train[k + 1];
    k = 0;
    for(int i = 0; i < lenght; i++){
        if(rep == data[i]->getRepairs() && car <= data[i]->getCarts()) {
           k++;
           temp[k] = *data[i];
        }
    }
    return temp;
}