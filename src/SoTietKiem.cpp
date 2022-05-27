#include "SoTietKiem.h"


SoTietKiem::SoTietKiem() {
    daohan = false;
    sotien = 0;
    savingoption.lai = 0;
    savingoption.kyhan = 0;
}

SoTietKiem::SoTietKiem(const SoTietKiem& stk) {
    daohan = false;
    sotien = stk.sotien;
    savingoption = stk.savingoption;
}

SoTietKiem::SoTietKiem(double sotien, SavingOption savingoption) {
    daohan = false;
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

bool SoTietKiem::isDaohan() {
    return daohan;
}

void SoTietKiem::setDaohan() {
    daohan = true;
}