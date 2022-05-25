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

double No::get_sotien() {
    return sotien;
}

int No::get_ngayno() {
    return ngayno;
}

int No::get_ngaytra() {
    return ngaytra;
}

string No::getdate_ngayno() {
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

string No::getdate_ngaytra() {
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

int No::get_kyhan() {
    return kyhan;
}

int No::get_ndaohan() {
    return lai.size();
}

double No::tongNoSauKyHanThu(int k) {
    double res = sotien;
    if (k > lai.size()) {
        cout << "No::tongNoSauKyHanThu(): vuot qua ngay tra no\n";
        exit(0);
    }
    for (int i = 0; i < k; i++) {
        res *= (1 + lai[i]);
    }
    return res;
}

void No::print() {
    cout << sotien << "\t" << getdate_ngayno() << "\t" << getdate_ngaytra();
}