#include "Controller.hpp"

Controller::Controller(List list){
    this->list=&list;
}

void Controller::ReadFile(string filename)
{
    BasicTrain bt;
    PassengerTrain pt;
    FreightTrain ft;
    ifstream fin; //поток для считывания из файла

    fin.exceptions(ifstream::badbit | ifstream::failbit); //Возможность самому обрабатывать ошибки потока
    try                                                   //Попытка открыть файл
    {
        cout << "Попытка открыть файл..." << endl;
        fin.open(filename);
        cout << "Файл успешно открыт!" << endl;
    }
    catch (const std::exception &ex)
    {
        cout << ex.what() << endl; //Вывод ошибки
        cout << "Введите корректное имя файла: ";
        cin >> filename;
        cout << endl;
        Controller::ReadFile(filename); //Будет рекурсировать пока пользователь не введет корректное название файла
    }

    fin.exceptions(ifstream::goodbit);
    fin.seekg(0, ios::cur);

    string tmp_result;
    while (1) //Пока есть строки в файле
    {
        int train_type;
        if (fin >> train_type)
        { // читаем 1 значение в файле. если 1 - это первый наследник, если 2 - второй
            fin.seekg(1, ios::cur);

            std::getline(fin, tmp_result);
            if (train_type == 1)
                list->AddTrain(bt.from_string(tmp_result), 100); //Строку, которую считали, заполняем в базовый класс
            else if (train_type == 2)
                list->AddTrain(pt.from_string(tmp_result), 100); //Строку, которую считали, заполняем в базовый класс
            else if (train_type == 3)
                list->AddTrain(ft.from_string(tmp_result), 100); //Строку, которую считали, заполняем в базовый класс
        }
        else
            break;
    }

    fin.seekg(0, ios::cur);
}
void Controller::WriteFile(string filename) //Вывод в файл
{
    ofstream fout(filename); //Поток вывода в файл

    if (!fout.is_open()) // Если файл не открыт
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < list->trains.size(); i++) //До конца массива
        {
            fout << list->trains[i]->to_string() << endl; //Построчный вывод
        }
    }
}

void Controller::PrintTrains() //Вывод на консоль
{
    for (int i = 0; i < list->trains.size(); i++) //До конца массива
    {
        cout << list->trains[i]->to_string() << endl; //Построчный вывод
    }
}

int Controller::FindCountTrains() //1 метод по работе с коллекцией
{
    int count = 0;
    for (int i = 0; i < list->trains.size(); i++)
    {
        if (list->trains[i]->getCarts() >= 10 && list->trains[i]->getRepairs() == 'y') //Если обьект имеет 10+ вагонов и требует ремонта
            count++;                                                       //Увеличиваем счетчик
    }
    return count; //Возвращаем кол-во
}

int Controller::FreightFromUkr()
{ //2 метод по работе с коллекцией
    int count = 0;
    for (int i = 0; i < list->trains.size(); i++)
    {
        string str = list->trains[i]->to_string(); //Берём в виде строки все параметры обьекта
        stringstream result(str);
        string number, start, finish, type, cargo = "";
        char repairs;
        int carts, weight;

        result >> number >> repairs >> carts >> start >> finish >> type >> cargo >> weight; //Разбиваем строку по переменным
        static const std::regex r("\\D+");
        if (cargo != "")
        { //Если переменная заполнилась (один из двух наследников)
            if (regex_match(cargo, r) && start == "Ukraine")
            {                                           //Если переменная заполнена словами(грузовой поезд) и отправляется из Украины
                count++;                                //Увеличиваем счетчик
                cout << list->trains[i]->to_string() << endl; //Выводим на экран
            }
        }
    }
    return count; //Возвращаем кол-во
}

int Controller::MostHeavyFreight()
{ //3 метод по работе с коллекцией
    int most_heavy = 0, heavy = 0;
    for (int i = 1; i < list->trains.size(); i++)
    {
        string str = list->trains[i]->to_string(); //Берём в виде строки все параметры обьекта
        stringstream result(str);
        string number, start, finish, type, cargo = "";
        char repairs;
        int carts, weight;

        result >> number >> repairs >> carts >> start >> finish >> type >> cargo >> weight; //Разбиваем строку по переменным
        if (cargo == "Wood")
        { //Если груз дерево, то сравниваем вес
            if (weight > heavy)
            {
                heavy = weight;
                most_heavy = i;
            }
        }
    }
    cout << list->trains[most_heavy]->to_string() << endl; //Вывод самого тяжелого поезда
    return most_heavy;                               //Возвращаем его индекс
}

void Controller::ConcVec(vector<Train*> v2){
    list->trains.insert( list->trains.end(), v2.begin(), v2.end()); //В конец 1 вектор1 записывается вектор2 с начала до конца
}

struct sort_Num  //функтор сортировки
{
	bool operator() (Train* i, Train* j)
	{ return (i->getNumber() < j->getNumber());}
} SortNum;

struct sort_Repairs  //функтор сортировки
{
	bool operator() (Train* i, Train* j)
	{ return (i->getRepairs() < j->getRepairs());}
} SortRepairs;

struct sort_Carts  //функтор сортировки
{
	bool operator() (Train* i, Train* j)
	{ return (i->getCarts() < j->getCarts());}
} SortCarts;

struct sort_Start  //функтор сортировки
{
	bool operator() (Train* i, Train* j)
	{ return (i->getStart() < j->getStart());}
} SortStart;

struct sort_Finish //функтор сортировки
{
	bool operator() (Train* i, Train* j)
	{ return (i->getFinish() < j->getFinish());}
} SortFinish;

struct sort_Type  //функтор сортировки
{
	bool operator() (Train* i, Train* j)
	{ return (i->getType() < j->getType());}
} SortType;

void Controller::SortBy(int a){
    switch (a)
    {
    case 1:
        sort (list->trains.begin(), list->trains.end(), SortNum);  //сортировка с какого по какой элемент
        break;
    case 2:
        sort (list->trains.begin(), list->trains.end(), SortRepairs);  //сортировка с какого по какой элемент
        break;
    case 3:
        sort (list->trains.begin(), list->trains.end(), SortCarts);  //сортировка с какого по какой элемент
        break;
    case 4:
        sort (list->trains.begin(), list->trains.end(), SortStart);  //сортировка с какого по какой элемент
        break;
    case 5:
        sort (list->trains.begin(), list->trains.end(), SortFinish);  //сортировка с какого по какой элемент
        break;
    case 6:
        sort (list->trains.begin(), list->trains.end(), SortType);  //сортировка с какого по какой элемент
        break;
    default:
        break;
    }
}