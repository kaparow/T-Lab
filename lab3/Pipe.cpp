#include "Pipe.h"
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
System s;
string status_check(bool x)
{
    if (x == true)
        return ("Труба в работе");
    else
        return ("Труба в ремонте");
}
int Pipe::max_id = 0;
istream& operator>> (istream& in, Pipe& p)
{
    cout << "\n Индекс трубы: " << p.idp;
    cout << "\nВведите название трубы ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, p.name);
    cout << "\nВведите длину трубы  ";
    p.length = correctnumber(0.0, DBL_MAX);
    cout << "\nВведите диаметр трубы ";
    p.diameter = correctdiametr<int>();
    cout << "\nВведите состояние трубы(0 - в ремонте, 1 - в работе) ";
    p.status = correctnumber(0, 1);
    cout << status_check(p.status) << endl;
    return in;
}
ostream& operator<< (ostream& out, Pipe& p) {
    out << "\nИндекс трубы: " << p.idp << endl;
    out << "Труба: " << p.name << endl;
    out << "Длина: " << p.length << endl;
    out << "Диаметр: " << p.diameter << endl;
    out << "Состояние(0 - в ремонте, 1 - в работе): " << status_check(p.status) << endl;

    return out;
}
void Pipe::edit_Pipe() {
    cout << "Состояние трубы: " << status_check(status) << endl;
    cout << "Изменить состояние трубы (0 - в ремонте, 1 - в работе)" << endl;
    status = correctnumber(0, 1);
    cout << status_check(status) << endl;;
}
void Pipe::save_pipe(ofstream& file) {
    if (file.is_open()) {
        file << idp << endl;
        file << name << endl;
        file << length << endl;
        file << diameter << endl;
        file << status << endl;
        
    }
}
void Pipe::load_pipe(ifstream& file) {
    if (file.is_open()) {
        file >> idp;
        getline(file, name);
        getline(file, name);
        file >> length;
        file >> diameter;
        file >> status;
    }
}
bool check_p_name(Pipe& p, string name) {
    return (p.name.find(name) != string::npos);
}
bool check_p_status(Pipe& p, bool status) {
    return (p.status == status);
}
