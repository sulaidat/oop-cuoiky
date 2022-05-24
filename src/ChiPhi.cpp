#include "ChiPhi.h"

ChiPhi::ChiPhi() {
    sinhhoat = 0;
    khac = 0;
}

ChiPhi::ChiPhi(double sinhhoat, double khac) {
    this->sinhhoat = sinhhoat;
    this->khac = khac;
}

double ChiPhi::tong() {
    return sinhhoat + khac;
}

void ChiPhi::print() {
    cout << sinhhoat << "\t" << khac << "\n";
}