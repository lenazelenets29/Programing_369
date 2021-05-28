#include "Array.hpp"

bool Array::isEl(int* position){
    if(position)
        return true;
}

int** Array::ReadFile(std::string filename){
    std::ifstream file;
    file.exceptions(std::ifstream::badbit | std::ifstream::failbit);  //Возможность самому обрабатывать ошибки потока
    
    try //Попытка открыть файл
    {
        std::cout << "Попытка открыть файл..." << std::endl;
        file.open(filename);
        std::cout << "Файл успешно открыт!" << std::endl;
    }
    catch (const std::exception &ex) 
    {
        std::cout << ex.what() << std::endl;    //Вывод ошибки
        std::cout << "Введите корректное имя файла: ";
        std::cin >> filename;
        std::cout << std::endl;
        Array::ReadFile( filename ); //Будет рекурсировать пока пользователь не введет корректное название файла
    }

    file.exceptions(std::ifstream::goodbit);
    
    std::string line;              //Строчка текста

        //Будем считывать информацию построчно до тех пор,
        //пока не закончится файл
         
    int j = 0;
    getline(file, line);                            //Первый элемент в файле - кол-во строк(массивов)
    size=atoi( line.c_str() );                   //Перевод из string в int
    int** arrays=new int*[size+1];                 //Массив указателей на созданные массивы
    try{
        while (getline(file, line))
        {
            if(j>=size){
                throw "В файле больше строк чем указано"; 
            }
            //Создадим поток для считывания данных из строчки    
            std::istringstream iss(line);
            std::string token;
            int i = 0;
            int* arr;
            while (getline(iss, token, ' '))
            {
                if (i == 0){
                    arr = new int[atoi(token.c_str())+1];  //Выделение памяти под массив (первый элемент строки - размер)
                    arr[i]=atoi(token.c_str());
                }
                else
                    arr[i]=atoi(token.c_str()); //заполнение элементов массива
                i++;
            }
            if(isEl(arrays[j]))  //Проверка на выход за пределы массива
                arrays[j]= arr;//присваивание указателя на массив в массив указателей 
            else    
                break;
            j++;
        }
    }
    catch(const char *ex){
        std::cout<<ex<<std::endl;
    }
    return arrays;
}


int* Array::SumOfArrays(int** arrays){ //Сумма каждого массива 
    int *res_arr = new int[size];
    for (int i = 0; i < size; i ++)
    {
        int sum = 0;
        for (int j = 1; j < arrays[i][0] + 1; j++)
        {
            sum += arrays[i][j];
        }

        res_arr[i] = sum;
    }
    return res_arr;
}

void Array::WriteOut(std::string filename, int* res_arr){
    std::ofstream output;
    output.open(filename); //открытие(создание) файла для записи
    for(int i=0; i<size; i++){
        output << res_arr[i]<< " "; //Вывод
    }
   output.close(); 
}

void Array::FreeMemory(int** arr, int* res_arr){ //очищение памяти
    
    for(int i=0;i<size;i++){
        delete[] arr[i];
    }
    delete[] arr;
    delete[] res_arr;
}