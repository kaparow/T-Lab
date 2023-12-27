#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "CS.h"
#include "Pipe.h"
#include "header.h"
#include "Graph.h"

using namespace std;
int main()
{
    System network;
    int option = -1;
    while (option) {
        cout << "\n1. Добавить трубу\n" <<
            "2. Добавить КС\n" <<
            "3. Просмотр всех объектов\n" <<
            "4. Редактировать трубу\n" <<
            "5. Редактировать КС\n" <<
            "6. Сохранить\n" <<
            "7. Загрузить\n" <<
            "8. Найти трубу\n" <<
            "9. Найти КС\n" <<
            "10. Создать газотранспортную сеть\n" <<
            "11. Сортировка\n" <<
            "0. Выход\n" <<
            "Введите ваш выбор: ";

        switch (correctnumber(0, 11)) {
        case 1: {
            Pipe p;
            cin >> p;
            network.pipe_group.insert({ p.get_id(), p });
            break;
        }
        case 2: {
            CS cs;
            cin >> cs;
            network.cs_group.insert({ cs.get_id(), cs });
            cout << network.cs_group.size();
            break;
        }
        case 3: {
            network.information();
            break;
        }
        case 4: {
            network.edit();
            break;
        }
        case 5: {
            network.editcs();
            break;
        }
        case 6: {
            network.save();
            break;
        }
        case 7: {
            network.load();
            break;
        }
        case 8: {
            findPipe();
            break;
        }
        case 9: {
            findCS();
            break;
        }
        case 10: {
            CreateGTsys(network);
            break;
        }
        case 11: {
            network.sorting();
            break;
        }
        case 0: {
            return 0;
        }
        }
    }

    return 0;
}
