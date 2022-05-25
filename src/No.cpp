#include "No.h"

No::No() {
    sotien = 0;
    ngayno = 0;
    ngaytra = 0;
}

No::No(double sotien, string ngayno, string ngaytra, int kyhan) {
    if (!checkDateFormat(ngaytra) && !checkDateFormat(ngayno)) {
        cout << "No(): invalid date format (DD-MM-YYYY)\n";
        exit(0);
    }
    this->ngayno += stoi(ngayno.substr(3, 2));
    this->ngayno += stoi(ngayno.substr(6)) * 12;
    this->ngaytra += stoi(ngaytra.substr(3, 2));
    this->ngaytra += stoi(ngaytra.substr(6)) * 12;
    this->sotien = sotien;
    this->kyhan = kyhan;
    
    int cnt = (this->ngaytra - this->ngayno) / kyhan;
    cout << "Tu " << ngayno << " den " << ngaytra << " co " << cnt << " ky han.\n";
    cout << "Nhap lai cho tung ky han: \n";
    float buf;
    for (int i = 0; i < cnt; i++) {
        buf = 0;
        cin >> buf;
        lai.push_back(buf);
    }
}

string No::get_ngayno() {
    int time = ngayno;
    string res = "";
    if (time % 12 == 0) {
        res += "12";
        time -= 12;
    } else {
        res += to_string(time % 12);
    }
    res += "-";
    res += to_string(time / 12);
    return res;
}

string No::get_ngaytra() {
    int time = ngaytra;
    string res = "";
    if (time % 12 == 0) {
        res += "12";
        time -= 12;
    } else {
        res += to_string(time % 12);
    }
    res += "-";
    res += to_string(time / 12);
    return res;
}

double No::tongSauKyHanThu(int k) {
    double res = sotien;
    for (float i : lai) {
        res *= (1 + i);
    }
    return res;
}

void No::print() {
    cout << sotien << "\t" << get_ngayno() << "\t" << get_ngaytra();
}