#include "No.h"

No::No() {
    sotien = 0;
    ngaytra = "";
    lai = 0;
    kyhan = 0;
}

No::No(double sotien, string ngaytra, float lai, int kyhan) {
    sotien = sotien;
    ngaytra = ngaytra;
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