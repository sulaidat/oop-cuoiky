#ifndef APP_H
#define APP_H

#include "QuanLy.h"
#include "lib/CSVParser.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

class App {
public:
    enum Menu {
        NhapNgayBatDau = 0,
        NhapNguonThu = 1,
        NhapChiPhi = 2,
        ThemNo = 3,
        InNguonThu = 4,
        InChiPhi = 5,
        InNo = 6,
        XuatBangTinh = 7,   
    };
    enum SubMenu {
        ManualInput = 1,
        FromFile = 2,
    };
    void init();
    void print_menu();
    void print_sub_menu();
    int get_num();

    void run();
};

#endif