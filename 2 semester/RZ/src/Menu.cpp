#include "Menu.hpp"

void Menu::start()
{
    List list;
    BasicTrain bt;
    PassengerTrain pt;
    FreightTrain ft;
    Controller controller = Controller(list);
    cout << "      Меню для работы с программой" << endl;
    while (1)
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "            Введите цифру для:\n\n[1] Считать данные из файла \n[2] Добавить объект в массив\n[3] Удалить объект\n[4] Вывести массив в файл\n[5] Вывести массив в консоль\n[6] Отсортировать массив\n[7] Выполнить методы по работе с коллекцией\n\n[0] Конец работы\n"
             << endl;
        unsigned short to_do;
        cin >> to_do;

        string filename = {0};
        int a, b;
        string number, start, finish, type, result;
        char repairs;
        int carts, ticket_price, seats;
        switch (to_do)
        {
        case 1:
            cout << "Введите имя файла: "; cin >> filename;
            cout << endl;
            controller.ReadFile(filename);
            break;
        case 2:
            cout << "\n            Введите цифру для:\n[1]Добавить объект класса BasicTrain\n[2]Добавить объект класса FreightTrain\n[3]Добавить объект класса PassengerTrain" << endl;
            cin >> a;
            cout << "\n            Введите цифру для:\n[1]Выполнить ввод данных самостоятельно\n[2]Заполнить объект рандомом" << endl;
            cin >> b;
            if (b == 1)
            {
                cout << "\n Введите елемент для поля Number: ";
                cin >> number;
                cout << "\n Введите елемент для поля Start: ";
                cin >> start;
                cout << "\n Введите елемент для поля Finish: ";
                cin >> finish;
                cout << "\n Введите елемент для поля Type: ";
                cin >> type;
                cout << "\n Введите елемент для поля Repairs: ";
                cin >> repairs;   
                cout << "\n Введите елемент для поля Carts: ";
                cin >> carts;
                if (a == 3)
                {
                    cout << "\n Введите елемент для поля Ticket_price: ";
                    cin >> ticket_price;
                    cout << "\n Введите елемент для поля Seats: ";
                    cin >> seats;
                }
            }
            else if (b == 2)
            {
                number = "[RANDOM_NUMBER]";
                start = "[RANDOM_START]";
                finish = "[RANDOM_FINISH]";
                type = "[RANDOM_TYPE]";
                repairs = 'y';
                carts = rand() % 20;
                if (a == 3)
                {
                    ticket_price = rand() % 1000;
                    seats = rand() % 300;
                }
            }

            if (a == 1){
                result = number + " " + repairs + " " + std::to_string(carts) + " " + start + " " + finish + " " + type ;
                controller.list->AddTrain(bt.from_string(result), 100);
            }else if (a == 2)
            {
                result = number + " " + repairs + " " + std::to_string(carts) + " " + start + " " + finish + " " + type + " [RANDOM_CARGO] 12000";
                controller.list->AddTrain(ft.from_string(result), 100);
            }else if (a == 3)
            {
                result = number + " " + repairs + " " + std::to_string(carts) + " " + start + " " + finish + " " + type + " " + std::to_string(ticket_price) + " " + std::to_string(seats);
                controller.list->AddTrain(pt.from_string(result), 100);
            }
            break;

        case 3:
            cout << "Введите индекс обьекта для удаления [0.." << controller.list->trains.size() - 1 << "]: ";
            cin >> a;
            controller.list->DeleteTrain(a);
            break;
        case 4:
            cout << "Введите имя файла: ";
            cin >> filename;
            cout << endl;
            controller.WriteFile(filename);
            break;
        case 5:
            controller.PrintTrains();
            break;
        case 6:
            cout << "\n            Введите цифру для сортировки относительно поля:\n[1]Number\n[2]Repairs\n[3]Carts\n[4]Start\n[5]Finish\n[6]Type" << endl;
            cin >> a;
            controller.SortBy(a);
            cout << "Коллекция была отсортирована" << endl;
            break;
        case 7:
            cout << "\n            Введите цифру для:\n[1]Найти кол-во поездов с 10+ вагонами и которые требуют ремонта\n[2]Найти все грузовые поезда из Украины\n[3]Найти самый тяжелый поезд, который везёт дерево" << endl;
            cin >> a;
            switch (a)
            {
            case 1:
                cout << "Кол-во поездов с 10+ вагонами и которые требуют ремонта: " << controller.FindCountTrains() << endl;
                break;
            case 2:
                cout << "Все грузовые поезда из Украины: " << endl;
                controller.FreightFromUkr();
                break;
            case 3:
                cout << "Самый тяжелый поезд, который везёт дерево: " << endl;
                controller.MostHeavyFreight();
                break;

            default:
                break;
            }
            break;

        case 0:
            return;

        default:
            break;
        }
    }
}