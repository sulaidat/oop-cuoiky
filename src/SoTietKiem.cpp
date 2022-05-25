#include "SoTietKiem.h"


SoTietKiem::SoTietKiem() {
    sotien = 0;
    savingoption.lai = 0;
    savingoption.kyhan = 0;
}

SoTietKiem::SoTietKiem(const SoTietKiem& stk) {
    sotien = stk.sotien;
    savingoption = stk.savingoption;
}

SoTietKiem::SoTietKiem(double sotien, SavingOption SavingOption) {
    this->sotien = sotien;
    this->savingoption = savingoption;
}

double SoTietKiem::soDuSauKyHan(int k) {
    double res = sotien;
    for (int i = 0; i < k; i++) {
        res *= (double)(1 + savingoption.lai);
    }
    return res;
}

