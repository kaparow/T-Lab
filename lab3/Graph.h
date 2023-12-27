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
using namespace std;
class System
{
public:
    unordered_map <int, Pipe> pipe_group;
    unordered_map <int, CS> cs_group;
    void information();
    void save();
    void load();
    void editcs();
    vector<int> search_cs();
    void edit();
    vector<int> search_p();
    struct Graph {
        int id_entrance;
        int id_exit;
        int id_pipe;
        void save_edge(ofstream& file);
        void load_edge(ifstream& file);
    };
    void adjacencytable(unordered_map<int, System::Graph>&);
    unordered_map <int, vector <Graph>> table;
    friend istream& operator>> (istream& in, System& s);
    friend ostream& operator<<(ostream& out, unordered_set<int> s);
    unordered_map <int, Graph> graphs;
    void topsort(int x, unordered_map<int, int>& visited, vector<int>& vertexes);
    void sorting();
    void sorted();
    int check_pipe(int x);
    bool checking(int x);
    int edge(int x);
    int check_graph(int x);
    int check_existing(int x);
    bool check_only(int x, int y);
    bool check_obj(int x);
};
