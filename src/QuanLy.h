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

class QuanLy {
protected:
    int timestamp;
    vector<NguonThu*> nguonthu;
    vector<ChiPhi*> chiphi;
    vector<No*> no;
    vector<SoTietKiem*> stk;
public:
    QuanLy();
    QuanLy(vector<NguonThu*>, vector<ChiPhi*>);
    QuanLy(vector<NguonThu*>, vector<ChiPhi*>, vector<No*>);
    QuanLy(vector<NguonThu*>, vector<ChiPhi*>, vector<No*>, vector<SoTietKiem*>);

    void getTimeStamp(string);
    string timestampToDate(int);
    void themNguonThu();
    void themChiPhi();
    void themNo();
    void themSTK();

    int readNguonThuFromFile(string);
    int readChiPhiFromFile(string);
    int readNoFromFile(string);

    void printNguonThu();
    void printChiPhi();
    void printNo();
};

#endif