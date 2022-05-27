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
    vector<SavingOption*> options;
    
    // other headers
    vector<double> tiensauchitieu;    // tiền sau trả chi phí và trả nợ cho tháng
    vector<double> tienvochong;
public:
    QuanLy();
    QuanLy(vector<NguonThu*>, vector<ChiPhi*>, vector<No*>, vector<SoTietKiem*>, vector<SavingOption*>);

    // update, add
    void update_mocthoigian(string);
    void add_nguonthu();
    void add_nguonthu_fromfile(string);
    void add_chiphi();
    void add_chiphi_fromfile(string);
    void add_no();
    int add_stk(int, SavingOption*);

    // get
    int get_mocthoigian();
    string getdate_mocthoigian(int);
    int get_best_option(vector<SavingOption*> opts);
    int get_best_option() {         // wrapper
        get_best_option(options);
    }
    int get_shortest_option(vector<SavingOption*> opts);
    int get_shortest_option() {     // wrapper
        get_shortest_option(options);
    }
    double get_sodu_trongkyhan(int idx);
    double get_sodu_daohan(int idx);

    // print
    void inNguonThu();
    void inChiPhi();
    void inNo();

    // other 
    int ruttien(double sotienphaitra, int pos);
    string exportData();

    void process();
};

#endif