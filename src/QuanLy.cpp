#include "QuanLy.h"
#include <regex>

QuanLy::QuanLy() {
    timestamp = -1;
}

QuanLy::QuanLy(string today, vector<NguonThu> nguonthu, vector<No> no, vector<ChiPhi> chiphi) {
    regex e("\\d{4}(?=$)");
    smatch m;
    regex_search(today, m, e);
    timestamp = atoi(m.str().c_str());
    nguonthu = nguonthu;
    no = no;
    chiphi = chiphi;
}