#include "List.hpp"
int main()
{

    std::unique_ptr<List> list1(new List); // выделение List
    std::unique_ptr<List> list2; // присваивается значение nullptr
    list2 = std::move(list1); // После этого первому указателю присваивается nullptr, а данные из него переносятся во второй
    cout << "list1 is " << list1.get() <<endl;
    cout << "list2 is " << list2.get() <<endl;
    

    std::shared_ptr<List> list3(new List); // выделение List
    std::shared_ptr<List> list4; // присваивается значение nullptr
    std::weak_ptr<List> weakList;

    list4 = list3; // И первый указатель и второй хранят указатель на одну и ту же область памяти
    weakList = list4;   // Weak лишь наблюдатель и не может напрямую работать с областью памяти
    
    cout << "list3 is " << list3.get() <<endl;  
    cout << "list4 is " << list4.get() <<endl;
   
    if(weakList.expired()){
    if(auto ptr = weakList.lock()) // Возвращает временный shared_ptr
        cout << "weakList " << ptr.get()<<endl;
    else
        cout << "lock() failed" <<endl;
    }
        list4= NULL;
    cout << "list4 is " << list4.get() <<endl;
    if(weakList.expired()){
    if(auto ptr = weakList.lock()) // Проверяет ссылается ли на что-то weak_ptr, может ли он создать временный shared_ptr, возвращает временный shared_ptr
        cout << "weakList " << ptr.get()<<endl;
    else
        cout << "lock() failed" <<endl;
} 
    return 0;
}