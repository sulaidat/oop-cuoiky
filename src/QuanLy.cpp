#include "QuanLy.h"

QuanLy::QuanLy() {
    timestamp = -1;
}

QuanLy::QuanLy(vector<NguonThu*> nguonthu, vector<ChiPhi*> chiphi) {
    this->nguonthu = nguonthu;
    this->chiphi = chiphi;
}

QuanLy::QuanLy(vector<NguonThu*> nguonthu, vector<ChiPhi*> chiphi, vector<No*> no): 
QuanLy::QuanLy(nguonthu, chiphi) {
    this->no = no;
}

QuanLy::QuanLy(vector<NguonThu*> nguonthu, vector<ChiPhi*> chiphi, vector<No*> no, vector<SoTietKiem*> stk): 
QuanLy::QuanLy(nguonthu, chiphi, no) {
    this->stk = stk;
}

void QuanLy::getTimeStamp(string startday) {
    if (!checkDateFormat(startday)) {
        cout << "QuanLy::getTimeStamp: invalid date format (DD-MM-YYYY)\n";
        exit(0);
    }
    timestamp += stoi(startday.substr(3, 2));
    timestamp += stoi(startday.substr(6)) * 12;
}

string QuanLy::timestampToDate(int idx) {
    string res = "";
    int cur = timestamp + idx;
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

int QuanLy::readNguonThuFromFile(string filepath) {
    ifstream file(filepath);
    if (!file.is_open()) {
        cout << "Could not open file\n";
        return -1;
    }

    string line;
    
    // skip header 
    getline(file, line);
    
    while (getline(file, line)) {
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

int QuanLy::readChiPhiFromFile(string filepath) {
    ifstream file(filepath);
    if (!file.is_open()) {
        cout << "Could not open file\n";
        return -1;
    }

    string line;
    
    // skip header 
    getline(file, line);
    
    while (getline(file, line)) {
        vector<string> values;

        CSVParser::parseLine(line, values);
        if (values.size() != 2) {
            cout << "ChiPhi::readChiPhiFromFile(): Improper number of headers\n";
            return -1;
        }

        ChiPhi* temp = new ChiPhi(stod(values[0]), stod(values[1]));
        chiphi.push_back(temp);
    }
    return 0;
}

int QuanLy::readNoFromFile(string filepath) {
    ifstream file(filepath);
    if (!file.is_open()) {
        cout << "Could not open file\n";
        return -1;
    }

    string line;
    
    // skip header 
    getline(file, line);
    
    while (getline(file, line)) {
        vector<string> values;

        CSVParser::parseLine(line, values);
        if (values.size() != 2) {
            cout << "No::readNoFromFile(): Improper number of headers\n";
            return -1;
        }

        No* temp = new No(stod(values[0]), values[1], stof(values[2]), stoi(values[3]));
        no.push_back(temp);
    }
    return 0;
}

void QuanLy::printNguonThu() {
    int i = 0;
    cout << "VO\tCHONG\tKHAC\n";
    for (NguonThu* temp : nguonthu) {
        cout << timestampToDate(i++) << "\t";
        temp->print();
    }
}

void QuanLy::printChiPhi () {
    int i = 0;
    cout << "SINHHOAT\tKHAC\n";
    for (ChiPhi* temp : chiphi) {
        cout << timestampToDate(i++) << "\t";
        temp->print();
    }
}

void QuanLy::printNo() {
    int i = 0;
    cout << "SOTIEN\tNGAYTRA\tLAI\tKYHAN\n";
    for (No* temp : no) {
        temp->print();
    }
}
