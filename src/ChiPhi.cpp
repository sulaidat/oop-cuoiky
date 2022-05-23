#include "ChiPhi.h"

ChiPhi::ChiPhi() {
    sinhhoat = 0;
    khac = 0;
}

ChiPhi::ChiPhi(double sinhhoat, double khac) {
    sinhhoat = sinhhoat;
    khac = khac;
}

double ChiPhi::tong() {
    return sinhhoat + khac;
}