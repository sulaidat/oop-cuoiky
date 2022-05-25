#ifndef NO_H
#define NO_H

#include "Utils.h"
#include <iostream>
#include <string>
#include <regex>
using namespace std;

class No {
protected:
    double sotien;
    int ngayno;
    int ngaytra;
    int kyhan;
    vector<float> lai;
public:
    No();
    // No(const No&);
    No(double, string, string, int);

    void update_sotien(double);
    void update_ngayno(string);
    void update_ngaytra(string);

    string get_ngayno();
    string get_ngaytra();

    double tongSauKyHanThu(int);

    void print();
};

#endif