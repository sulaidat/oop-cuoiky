#ifndef NGUONTHU_H
#define NGUONTHU_H

#include <iostream>
using namespace std;

class NguonThu {
protected:
    double vo;
    double chong;
    double khac;
public:
    NguonThu();
    NguonThu(const NguonThu&);
    NguonThu(double vo, double chong, double khac);
    
    double tong();
    double tongVoChong();
    double tongKhac();

    void print();
};

#endif