#include "No.h"

No::No() {
    sotien = 0;
    timestamp = -1;
    lai = 0;
    kyhan = 0;
}

No::No(double sotien, string ngaytra, float lai, int kyhan) {
    if (!checkDateFormat(ngaytra)) {
        cout << "No(double, string, float, int): invalid date format (DD-MM-YYYY)\n";
        exit(0);
    }
    timestamp += stoi(ngaytra.substr(3, 2));
    timestamp += stoi(ngaytra.substr(6)) * 12;
    this->sotien = sotien;
    this->lai = lai;
    this->kyhan = kyhan;
}

double No::tongSauKyHan(int k) {
    double res = sotien;
    for (int i = 0; i < k; i++) {
        res *= (double)(1 + lai);
    }
    return res;
}


void No::getTimeStamp(string ngaytra) {
    if (!checkDateFormat(ngaytra)) {
        cout << "No::getTimeStamp: invalid date format (DD-MM-YYYY)\n";
        exit(0);
    }
    timestamp += stoi(ngaytra.substr(3, 2));
    timestamp += stoi(ngaytra.substr(6)) * 12;
}

string No::timestampToDate() {
    string res = "";
    int cur = timestamp;
    if (cur % 12 == 0) {
        res += "12";
        cur -= 12;
    } else {
        res += to_string(cur % 12);
    }
    res += "-";
    res += to_string(cur / 12);
    return res;
}

void No::print() {
    cout << sotien << "\t" << timestampToDate() << lai << "\t" << kyhan << "\n";
}