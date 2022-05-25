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

    double get_sotien();
    int get_ngayno();
    int get_ngaytra();
    string getdate_ngayno();
    string getdate_ngaytra();
    int get_kyhan();
    int get_ndaohan();      // so lan dao han giua ngay no va ngay tra

    double tongNoSauKyHanThu(int);

    void print();
};

#endif