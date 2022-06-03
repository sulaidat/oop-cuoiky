#define _CRT_SECURE_NO_WARNINGS
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
        NhapNgayBatDau,
        NhapNguonThu,
        NhapChiPhi,
        ThemNo,
        AddSavingOption,
        InNguonThu,
        InChiPhi,
        InNo,
        XuatBangTinh,   
    };
    enum SubMenu {
        ManualInput,
        FromFile,
    };

    void init();
    void print_menu();
    void print_sub_menu();
    int get_num();


    void run();
};

#endif