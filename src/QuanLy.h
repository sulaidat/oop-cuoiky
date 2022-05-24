#ifndef QUANLY_H
#define QUANLY_H

#include "NguonThu.h"
#include "ChiPhi.h"
#include "No.h"
#include "SoTietKiem.h"
#include "Global.h"
#include <vector>
#include <regex>

class QuanLy {
protected:
    int timestamp;
    vector<NguonThu> nguonthu;
    vector<ChiPhi> chiphi;
    vector<No> no;
    vector<SoTietKiem> stk;
public:
    QuanLy();
    QuanLy(string, vector<NguonThu>, vector<No>, vector<ChiPhi>);
};

#endif