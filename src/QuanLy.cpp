#include "QuanLy.h"

QuanLy::QuanLy() {
    timestamp = -1;
}

QuanLy::QuanLy(string current, vector<NguonThu> nguonthu, vector<No> no, vector<ChiPhi> chiphi) {
    size_t pos = current.find("-");
    timestamp = atoi(current.substr(pos+1, 1).c_str());
    timestamp += atoi(current.substr(pos+3).c_str()) * 12;
    nguonthu = nguonthu;
    no = no;
    chiphi = chiphi;
}