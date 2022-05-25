#ifndef QUANLY_H
#define QUANLY_H

#include "lib/CSVParser.h"
#include "Utils.h"
#include "NguonThu.h"
#include "ChiPhi.h"
#include "No.h"
#include "SoTietKiem.h"
#include <vector>
#include <regex>
#include <fstream>
#include <iostream>
using namespace std;

class QuanLy {
protected:
    int mocthoigian;
    vector<NguonThu*> nguonthu;
    vector<ChiPhi*> chiphi;
    vector<No*> no;
    vector<SoTietKiem*> stk;
public:
    QuanLy();
    QuanLy(vector<NguonThu*>, vector<ChiPhi*>, vector<No*>, vector<SoTietKiem*>);

    void update_mocthoigian(string);
    void add_nguonthu();
    void add_nguonthu_fromfile(string);
    void add_chiphi();
    void add_chiphi_fromfile(string);
    void add_no();
    void add_stk();

    string get_mocthoigian(int);

    void inNguonThu();
    void inChiPhi();
    void inNo();

    string exportData();

    void process();
};

#endif