#include "QuanLy.h"

QuanLy::QuanLy() {
    mocthoigian = 0;
}

QuanLy::QuanLy(vector<NguonThu*> nguonthu, vector<ChiPhi*> chiphi, vector<No*> no, vector<SoTietKiem*> stk) {
    this->mocthoigian = 0;
    this->nguonthu = nguonthu;
    this->chiphi = chiphi;
    this->no = no;
    this->stk = stk;
}

void QuanLy::update_mocthoigian(string date) {
    if (!checkDateFormat(date)) {
        cout << "QuanLy::update_mocthoigian: invalid date format (DD-MM-YYYY)\n";
        exit(0);
    }
    mocthoigian += stoi(date.substr(3, 2));
    mocthoigian += stoi(date.substr(6)) * 12;
}

string QuanLy::get_mocthoigian(int idx) {
    string res = "";
    int cur = mocthoigian + idx;
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

void QuanLy::add_nguonthu() {
    double vo, chong, khac;
    cout << "vo, chong, khac:\n";
    cin >> vo >> chong >> khac;
    NguonThu* temp = new NguonThu(vo, chong, khac);
    nguonthu.push_back(temp);
}

void QuanLy::add_nguonthu_fromfile(string filepath) {
    ifstream in(filepath);
    if (!in.is_open()) {
        cout << "Could not open file\n";
        return;
    }

    string line;
    vector<string> values;
    
    // skip header 
    getline(in, line);

    // check number of headers
    CSVParser::parseLine(line, values);
    if (values.size() != 3) {
        cout << "QuanLy::add_nguonthu_fromfile(): Improper number of headers\n";
        return;
    }  

    while (getline(in, line)) {
        values.clear();
        CSVParser::parseLine(line, values);
        NguonThu* temp = new NguonThu(stod(values[0]), stod(values[1]), stod(values[2]));
        nguonthu.push_back(temp);
    }
}

void QuanLy::add_chiphi() {
    double sinhhoat, khac;
    cout << "sinh hoat, khac:\n";
    cin >> sinhhoat >> khac;
    ChiPhi* temp = new ChiPhi(sinhhoat, khac);
    chiphi.push_back(temp);
}

void QuanLy::add_chiphi_fromfile(string filepath) {
    ifstream in(filepath);
    if (!in.is_open()) {
        cout << "Could not open file\n";
        return;
    }

    string line;
    vector<string> values;
    
    // skip header 
    getline(in, line);

    // check number of headers
    CSVParser::parseLine(line, values);
    if (values.size() != 2) {
        cout << "QuanLy::add_chiphi_fromfile(): Improper number of headers\n";
        return;
    }  

    while (getline(in, line)) {
        values.clear();
        CSVParser::parseLine(line, values);
        ChiPhi* temp = new ChiPhi(stod(values[0]), stod(values[1]));
        chiphi.push_back(temp);
    }
}

void QuanLy::add_no() {
    double sotien;
    string ngayno, ngaytra;
    int kyhan;
    cout << "So tien: "; cin >> sotien;
    cout << "Ngay no: "; getline(cin, ngayno);
    cout << "Ngay tra: "; getline(cin, ngaytra);

    No* temp = new No(sotien, ngayno, ngaytra, kyhan);
    no.push_back(temp);
}

void QuanLy::inNguonThu() {
    int i = 0;
    cout << "VO\tCHONG\tKHAC\n";
    for (NguonThu* temp : nguonthu) {
        cout << get_mocthoigian(i++) << "\t";
        temp->print();
    }
}

void QuanLy::inChiPhi () {
    int i = 0;
    cout << "SINHHOAT\tKHAC\n";
    for (ChiPhi* temp : chiphi) {
        cout << get_mocthoigian(i++) << "\t";
        temp->print();
    }
}

void QuanLy::inNo() {
    int i = 0;
    cout << "SOTIEN\NGAYNO\tNGAYTRA\n";
    for (No* temp : no) {
        temp->print();
    }
}

/* NGUONTHUVOCHONG | NGUONTHUKHAC | CHIPHI | SODUTIETKIEM | NOTRUNGBINH | CHIPHI-NOTRUNGBINH */
string QuanLy::exportData() {

}

/*  Lap ke hoach gui chi tieu, tiet kiem va tra no 
    - Nguon thu vo chong: gui tiet kiem
    - Nguon thu khac: chi tieu va tra no
    - */
void QuanLy::process() {
    for (NguonThu* tmp : nguonthu) {
        
    }
}