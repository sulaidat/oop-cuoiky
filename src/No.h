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
    int timestamp;
    float lai;
    int kyhan;
public:
    No();
    // No(const No&);
    No(double, string, float, int);
    double tongSauKyHan(int);

    void No::getTimeStamp(string);
    string No::timestampToDate();

    void print();
};

#endif