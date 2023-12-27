#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "Pipe.h"
#include "CS.h"
#include "Graph.h"
using namespace std;
template <typename T>
T correctnumber(T min, T max) {
    T x;
    while (((cin >> x).fail()) || (cin.peek() != '\n') || (x < min) || (x > max)) {
        cout << "\nНеверный ввод данных!" << endl;
        cout << "Введите число от " << min << " до " << max << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    return x;
}

template <typename T>
T correctdiametr() {
    T x;
    while (((cin >> x).fail()) || (cin.peek() != '\n') || ((x != 500) && (x != 700) && (x != 1000) && (x != 1400))) {
        cout << "\nНеверный ввод данных!" << endl;
        cout << "Введите число из списка: (500, 700, 1000, 1400) "  << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    return x;
}

template <typename T>
ostream& operator<< (ostream& out, unordered_map <int, T>& p) {
    out << "ID выхода: ";
    for (auto& [i, obj] : p) {
        out << i << " ";
    }
    out << endl;
    return out;
}
template <typename T>
using filter_p = bool (*) (Pipe p, T par);
template <typename T>
using filter_cs = bool(*) (CS cs, T par);
template <typename T>
vector <int> search_p_by_parametr(unordered_map <int, Pipe>& pipe_group, filter_p<T> f, T par) {
    vector <int> id;
    for (auto& pipe : pipe_group) {
        if (f(pipe.second, par))
            id.push_back(pipe.second.get_id());
    }
    return id;
}
template <typename T>
vector <int> search_cs_by_parametr(unordered_map <int, CS>& cs_group, filter_cs<T> f, T par) {
    vector <int> id;
    for (auto& cs : cs_group) {
        if (f(cs.second, par))
            id.push_back(cs.second.get_id());
    }
    return id;
}

inline void findPipe(){
    System network;
    if (network.pipe_group.size() != 0) {
        auto x = network.search_p();
        if (x.size() != 0) {
            for (auto& i : x)
                cout << network.pipe_group[i] << endl;
        }
        else
            cout << "Нет такой трубы" << endl;
    }
    else
        cout << "Труба не найдена" << endl;
}

inline void findCS(){
    System network;
    if (network.cs_group.size() != 0) {
        auto x = network.search_cs();
        if (x.size() != 0) {
            for (auto& i : x)
                cout << network.cs_group[i] << endl;
        }
        else
            cout << "Нет такой КС";
    }
    else
        cout << "КС не найдена" << endl;
}

inline void CreateGTsys(){
    System network;
    cout << "1.Соеднить 2.Разъединить" << endl;
    int choise = correctnumber(1, 2);
    cout << network.cs_group.size();
    cout << network.pipe_group.size();

    if (choise == 1) {
        if ((network.cs_group.size() < 2) or (network.pipe_group.size() < 1))
            cout << "Недостаточно объектов, чтобы создать сеть" << endl;
        else
            cin >> network;
    }
    else {
        if (network.graphs.size() != 0) {
            cout << "Введите КС входа" << endl;
            int x = correctnumber(0, INT_MAX);
            x = network.check_existing(x);
            cout << "Введите КС выхода" << endl;
            int y = correctnumber(0, INT_MAX);
            y = network.check_existing(y);
            while (x == y) {
                cout << "Вы не можете разъединить одну и ту же КС" << endl;
                y = correctnumber(0, INT_MAX);
                y = network.check_existing(y);
            }
            auto i = network.graphs.cbegin();
            while (i != network.graphs.cend()) {
                if (((*i).second.id_entrance == x) and ((*i).second.id_exit == y)) {
                    network.graphs.erase(i);
                    break;
                }
                i++;
            }
        }

        else
            cout << "Нет доступных сетей" << endl;

    }
    for (auto& [i, j] : network.graphs)
        cout << i << ") " << j.id_entrance << " " << j.id_exit << " " << j.id_pipe << endl;
}
