#include "QuanLy.h"

QuanLy::QuanLy() {
    timestamp = -1;
}

QuanLy::QuanLy(vector<NguonThu*> nguonthu, vector<ChiPhi*> chiphi) {
    nguonthu = nguonthu;
    chiphi = chiphi;
}

QuanLy::QuanLy(vector<NguonThu*> nguonthu, vector<ChiPhi*> chiphi, vector<No*> no): 
QuanLy::QuanLy(nguonthu, chiphi) {
    no = no;
}

QuanLy::QuanLy(vector<NguonThu*> nguonthu, vector<ChiPhi*> chiphi, vector<No*> no, vector<SoTietKiem*> stk): 
QuanLy::QuanLy(nguonthu, chiphi, no) {
    stk = stk;
}

void QuanLy::dateToTimestamp(string startday) {
    if (!checkDateFormat(startday)) {
        cout << "QuanLy(double, string, float, int): invalid date format (DD-MM-YYYY)\n";
        exit(0);
    }
    regex e("\\d{4}(?=$)");
    smatch m;
    regex_search(startday, m, e);
    timestamp = stoi(m.str());
}

string QuanLy::timestampToDate() {
    string res = "";
    res += to_string(timestamp % 12);
    res += "-";
    res += to_string(timestamp / 12);
    return res;
}

void QuanLy::printNguonThu() {
    for (NguonThu* temp : nguonthu) {
        cout << timestampToDate() << "\t";
        temp->print();
    }
}


int QuanLy::readNguonThuFromFile(string filepath) {
    ifstream fcsv(filepath);
    if (!fcsv.is_open()) {
        cout << "Could not open file\n";
        return -1;
    }

    string line;
    
    // skip header 
    getline(fcsv, line);
    
    while (getline(fcsv, line)) {
        vector<string> values;

        CSVParser::parseLine(line, values);
        if (values.size() != 3) {
            cout << "QuanLy::readNguonThuFromFile(): Improper number of headers\n";
            return -1;
        }

        NguonThu* temp = new NguonThu(stod(values[0]), stod(values[1]), stod(values[2]));
        nguonthu.push_back(temp);
    }
    return 0;
}