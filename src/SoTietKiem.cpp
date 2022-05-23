#include "SoTietKiem.h"


SoTietKiem::SoTietKiem() {
    sotien = 0;
    lai = 0;
    kyhan = 0;
}

SoTietKiem::SoTietKiem(const SoTietKiem& stk) {
    sotien = stk.sotien;
    lai = stk.lai;
    kyhan = stk.kyhan;
}

SoTietKiem::SoTietKiem(double sotien, float lai, int kyhan) {
    sotien = sotien;
    lai = lai;
    kyhan = kyhan;
}

double SoTietKiem::soDuSauKyHan(int k) {
    double res = sotien;
    for (int i = 0; i < k; i++) {
        res *= (double)(1 + lai);
    }
    return res;
}

