#ifndef NO_H
#define NO_H

#include <string>
using namespace std;

class No {
protected:
    double sotien;
    string ngaytra;
    float lai;
    int kyhan;
public:
    No();
    No(const No&);
    No(double, string, float, int);
    double tongSauKyHan(int);
};

#endif