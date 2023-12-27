#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_set>
using namespace std;
class CS
{
public:
      static int max_idd;
      CS() {
          idcs = max_idd++;
      }
      friend istream& operator>> (istream& in, CS& p);
      friend ostream& operator<< (ostream& out, CS& cs);
      void save_cs(ofstream& file);
      void edit_cs();
      void load_cs(ifstream& file);
      int get_id() { return idcs; }
      double get_unused() { return (((double)workshop - (double)working_workshop) / (double)workshop) * 100; }
      string name = "";
      int getwork() { return workshop; };
      static int GetMaxId() { return max_idd; };


private:
    int  workshop, working_workshop, idcs;
    double effectiveness;
    //static int max_idd;
};
