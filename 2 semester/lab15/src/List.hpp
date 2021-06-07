#include "Train.hpp"
#include "BasicTrain.hpp"
#include "PassengerTrain.hpp"
#include "FreightTrain.hpp"

template <typename T>
class List //Класс-список
{
public:
    vector<T> trains; //Вектор указателей базового класса
    typedef typename std::vector<T>::iterator iterator;
    iterator begin()
    {
        return trains.begin();
    }
    iterator end()
    {
        return trains.end();
    }

    List() //Конструктор по умолчанию
    {
        cout << "Вызвался конструктор List \n";
    }
    List(const List &other) //Конструктор копирования
    {
        this->trains = other.trains;
        for (int i = 0; i < trains.size(); i++)
        {
            this->trains[i] = other.trains[i];
        }
        cout << "\nВызвался конструктор копирования" << endl;
    }
    ~List() //Деструктор
    {
    cout << "\nВызвался деструктор List \n\n";
    // удаление выделенной памяти
    trains.clear();
};

    void ReadFile(string filename)  //Чтение из файла
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
        List::ReadFile(filename); //Будет рекурсировать пока пользователь не введет корректное название файла
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
                AddTrain(bt.from_string(tmp_result), 100); //Строку, которую считали, заполняем в базовый класс
            else if (train_type == 2)
                AddTrain(pt.from_string(tmp_result), 100); //Строку, которую считали, заполняем в базовый класс
            else if (train_type == 3)
                AddTrain(ft.from_string(tmp_result), 100); //Строку, которую считали, заполняем в базовый класс
        }
        else
            break;
    }

    fin.seekg(0, ios::cur);
}

    void WriteFile(string filename) //Запись в файл
    {
    ofstream fout(filename); //Поток вывода в файл

    if (!fout.is_open()) // Если файл не открыт
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < trains.size(); i++) //До конца массива
        {
            fout << trains[i]->to_string() << endl; //Построчный вывод
        }
    }
}

    void PrintTrains() //Вывод на консоль
    {
    for (int i = 0; i < trains.size(); i++) //До конца массива
    {
        cout << trains[i]->to_string() << endl; //Построчный вывод
    }
}

    int FindCountTrains()  //1 метод по работе с коллекцией
    {
    int count = 0;
    for (int i = 0; i < trains.size(); i++)
    {
        if (trains[i]->getCarts() >= 10 && trains[i]->getRepairs() == 'y') //Если обьект имеет 10+ вагонов и требует ремонта
            count++;                                                       //Увеличиваем счетчик
    }
    return count; //Возвращаем кол-во
}

    int FreightFromUkr()   //2 метод по работе с коллекцией
    { //2 метод по работе с коллекцией
    int count = 0;
    for (int i = 0; i < trains.size(); i++)
    {
        string str = trains[i]->to_string(); //Берём в виде строки все параметры обьекта
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
                cout << trains[i]->to_string() << endl; //Выводим на экран
            }
        }
    }
    return count; //Возвращаем кол-во
}

    int MostHeavyFreight() //3 метод по работе с коллекцией
    { //3 метод по работе с коллекцией
    int most_heavy = 0, heavy = 0;
    for (int i = 1; i < trains.size(); i++)
    {
        string str = trains[i]->to_string(); //Берём в виде строки все параметры обьекта
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
    cout << trains[most_heavy]->to_string() << endl; //Вывод самого тяжелого поезда
    return most_heavy;                               //Возвращаем его индекс
}


    void AddTrain(Train *object, int index) //Добавление элемента в массив
    {
    if (index >= trains.size()) //Если переданный индекс больше
    {
        index = trains.size(); //Приравнивается размеру
    }
    auto iter = trains.cbegin();
    trains.insert(iter + index, object);
}
    void DeleteTrain(int index)             //Удаление элемента из массива
    {
    if (index >= trains.size()) //Если переданный индекс больше
    {
        index = trains.size() - 1; //Приравнивается последнему элементу
    }
    auto iter = trains.cbegin();
    trains.erase(iter + index);
}

    void ConcVec(vector<T> v2)
    {
    trains.insert( trains.end(), v2.begin(), v2.end()); //В конец 1 вектор1 записывается вектор2 с начала до конца
}

struct sort_birds  //функтор сортировки
{
	bool operator() (Train* i, Train* j)
	{ return (i->getNumber() < j->getNumber());}
} SortNumber;

    void SortByNumber()
    {
    sort (trains.begin(), trains.end(), SortNumber);  //сортировка с какого по какой элемент
}

    Train& operator[] (int index)
{
    return *trains[index];
}
Train& operator[] (int index) const
{
    return *trains[index];
}

friend std::ostream& operator<< (std::ostream &out, const List &object)
{   
    int n = object.trains.size();

    for ( int i = 0; i < n; i++ )
    {
        out << object[i] << ( i != n - 1 ? "\n" : "" );
    }   

    return out;
}

friend std::istream& operator>> (std::istream &in, List &object)
{ 
    int n = object.trains.size();

    for ( int i = 0; i < n; i++ )
    {
        in >> object[i];
    }

    return in;
}

friend ofstream& operator<< (ofstream &out, const List &object)
{
    int n = object.trains.size();

    for ( int i = 0; i < n; i++ )
    {
        out << object[i] << ( i != n - 1 ? "\n" : "" );
    }   

    return out;
}

friend ifstream& operator>> (ifstream &in, List &object)
{
    int n = object.trains.size();

    for ( int i = 0; i < n; i++ )
    {
        in >> object[i];
    }

    return in;
}
};