#include "CS.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "header.h"
#include "Graph.h"
using namespace std;
System t;
int CS::max_idd = 0;
istream& operator>> (istream& in, CS& cs)
{
    cout << "\nИндекс КС: " << cs.idcs;
    cout << "\nВведите название КС ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, cs.name);
    cout << "\nВведите количество цехов КС ";
    cs.workshop = correctnumber(0, INT_MAX);
    cout << "\nВведите количество цехов в работе ";
    cs.working_workshop = correctnumber(0, cs.workshop);
    cout << "\nУкажите эффективность(0 - 100) ";
    cs.effectiveness = correctnumber(0, 100);
    return in;
}
ostream& operator<< (ostream& out, CS& cs) {
    out << "Индекс КС: " << cs.idcs << endl;
    out << "КС: " << cs.name << endl;
    out << "Количество цехов: " << cs.workshop << endl;
    out << "Количество цехов в работе: " << cs.working_workshop << endl;
    out << "Эффективность: " << cs.effectiveness << endl;
    return out;
}
void CS::edit_cs() {
    cout << "Цехи: " << workshop << endl;
    cout << "Работающие цехи: " << working_workshop << endl;
    cout << "Введите новое количество работающих цехов" << endl;
    working_workshop = correctnumber(0, workshop);
}
void CS::save_cs(ofstream& file) {
    if (file.is_open()) {
        file << idcs << endl << name << endl
            << workshop << endl << working_workshop << endl << effectiveness << endl;
    }
}
void CS::load_cs(ifstream& file) {
    if (file.is_open()) {
        file >> idcs;
        getline(file, name);
        getline(file, name);
        file >> workshop;
        file >> working_workshop;
        file >> effectiveness;
    }
}
