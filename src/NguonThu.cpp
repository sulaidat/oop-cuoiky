#include "NguonThu.h"

NguonThu::NguonThu() {
    vo = 0;
    chong = 0;
    khac = 0;
}

NguonThu::NguonThu(const NguonThu& n) {
    vo = n.vo;
    chong = n.chong;
    khac = n.khac;
}

NguonThu::NguonThu(double vo, double chong, double khac) {
    vo = vo;
    chong = chong;
    khac = khac;
}

double NguonThu::tong() {
    return vo + chong + khac;
}

double NguonThu::tongVoChong() {
    return vo + chong;
}

double NguonThu::tongKhac() {
    return khac;
}

void NguonThu::print() {
    cout << vo << "\t" << chong << "\t" << khac << "\n";
}