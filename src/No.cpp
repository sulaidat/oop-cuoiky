#include "No.h"
#include <regex>

No::No() {
    sotien = 0;
    timestamp = -1;
    lai = 0;
    kyhan = 0;
}

No::No(double sotien, string ngaytra, float lai, int kyhan) {
    regex e("\\d{4}(?=$)");
    smatch m;
    regex_search(ngaytra, m, e);
    timestamp = atoi(m.str().c_str());
    sotien = sotien;
    lai = lai;
    kyhan = kyhan;
}

double No::tongSauKyHan(int k) {
    double res = sotien;
    for (int i = 0; i < k; i++) {
        res *= (double)(1 + lai);
    }
    return res;
}