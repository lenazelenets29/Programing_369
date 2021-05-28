#include "List.hpp"

List::List(){
    cout << "Вызвался конструктор List \n";
    size=0;
}

List::List(const List &other){
    this->trains = other.trains;
        for(int i=0;i<size;i++){
            this->trains[i]=other.trains[i];
        }
        cout << "\nВызвался конструктор копирования" << endl;
}

List::~List()
{
	cout << "Вызвался деструктор List \n";
	
	// удаление выделенной памяти
    for(int i=0;i<size;i++)
        delete[] trains[i]; //Удаляем выделенную память на каждый указатель базового класса
    delete[] trains;	//Удаление массива
};

void List::ReadFile( string filename ) 
{
	ifstream fin(filename); //Поток для работы с файлом
    
	fin.seekg(0,ios::cur);				//Переместил курсор на начало файла

    if ( !fin.is_open() ) // Если файл не открыт
        cout << "Файл не может быть открыт!\n"; 
    else
    {
        string tmp_result; 
		while(std::getline(fin, tmp_result)) //Пока есть строки в файле
		{	
            Train* temp_train=new Train[1];
			temp_train->from_string(tmp_result); //Строку, которую считали, заполняем в базовый класс

            AddTrain(temp_train, 100); //Добавляем созданный обьект в массив
		}
	}

	fin.seekg(0,ios::cur);
}
void List::WriteFile( string filename ) //Вывод в файл
{
	ofstream fout(filename); //Поток вывода в файл

    if ( !fout.is_open() ) // Если файл не открыт
        cout << "Файл не может быть открыт!\n"; 
	else
	{
		for ( int i = 0; i < size; i++ ) //До конца массива
		{
			fout << trains[i]->to_string()<< endl; //Построчный вывод
		}
	}
}

void List::PrintTrains() //Вывод на консоль
{	
	for ( int i = 0; i < size; i++ ) //До конца массива
	{
		cout<<trains[i]->to_string()<< endl;  //Построчный вывод
	}
}

int List::FindCountTrains() //1 метод по работе с коллекцией
{   
    int count = 0;
	for(int i=0;i<size;i++){
        if(trains[i]->getCarts()>=10 && trains[i]->getRepairs()=='y') //Если обьект имеет 10+ вагонов и требует ремонта
            count++; //Увеличиваем счетчик
    }
    return count; //Возвращаем кол-во
}

void List::AddTrain( Train* object, int index ) //Добавление обьекта в массив
{
    if (index >= size) //Если переданный индекс больше
    {
        index = size; //Приравнивается размеру
    }

	Train** temp_trains = new Train*[size+1]; //Создаем массив размером на 1 больше старого

	for ( int i = 0; i < index; i++)
		temp_trains[i] = trains[i];	//Переписываем старые указатели до индекса
    temp_trains[index] = object; //Записываем новый указатель
    for(int i=index;i<size;i++)
        temp_trains[i] = trains[i-1]; //Переписываем старые указатели после индекса

    size++; //Увеличиваем размер
	trains = temp_trains; //Присваиваем новый массив старому
}

void List::DeleteTrain( int index ) //Удаление элемента из массива
{
    if (index >= size)//Если переданный индекс больше
    {
        index = size-1;//Приравнивается последнему элементу
    }
    Train** temp_trains = new Train*[size-1];//Создаем массив размером на 1 меньше старого

    for(int i=0; i<index;i++){
        temp_trains[i]=trains[i]; //Переписываем старые указатели до индекса
    }
	for ( int i = index; i < size-1; i++)
	{
		temp_trains[i] = trains[i+1];//Переписываем старые указатели после индекса
	}	
    delete[] trains[index]; //Очищаем память выделенную под ненужный более обьект

	trains = temp_trains;//Присваиваем новый массив старому
    size--;//Уменьшаем размер
}