#ifndef NO_H
#define NO_H

#include <string>
using namespace std;

class No {
protected:
    enum Lai {
        THANG = 1,
        _6THANG = 6,
        NAM = 12
    };
    
    double sotien;
    int timestamp;
    float lai;
    int kyhan;
public:
    No();
    // No(const No&);
    No(double, string, float, int);
    double tongSauKyHan(int);
};

#endif