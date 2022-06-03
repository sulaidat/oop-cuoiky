#ifndef CHIPHI_H
#define CHIPHI_H

#include <iostream>
using namespace std;

class ChiPhi {
protected:
    double sinhhoat;
    double khac;
public:
    ChiPhi();
    // ChiPhi(const ChiPhi&);
    ChiPhi(double, double);

    double tong();

    void print();
};

#endif