#include "QuanLy.h"

QuanLy::QuanLy() {
    mocthoigian = 0;
}

QuanLy::QuanLy(vector<NguonThu*> nguonthu, vector<ChiPhi*> chiphi, vector<No*> no, vector<SoTietKiem*> stk, vector<SavingOption*> options) {
    this->mocthoigian = 0;
    this->nguonthu = nguonthu;
    this->chiphi = chiphi;
    this->no = no;
    this->stk = stk;
    this->options = options;
}

void QuanLy::update_mocthoigian(string date) {
    if (!checkDateFormat(date)) {
        cout << "QuanLy::update_mocthoigian: invalid date format (DD-MM-YYYY)\n";
        exit(0);
    }
    mocthoigian += stoi(date.substr(3, 2));
    mocthoigian += stoi(date.substr(6)) * 12;
}

int QuanLy::get_mocthoigian() {
    return mocthoigian;
}

string QuanLy::getdate_mocthoigian(int idx) {
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
    /* Uu tien tra no nhieu hon */
    sort(no.begin(), no.end(), compare);
}

void QuanLy::inNguonThu() {
    int i = 0;
    cout << "VO\tCHONG\tKHAC\n";
    for (NguonThu* temp : nguonthu) {
        cout << getdate_mocthoigian(i++) << "\t";
        temp->print();
    }
}

void QuanLy::inChiPhi () {
    int i = 0;
    cout << "SINHHOAT\tKHAC\n";
    for (ChiPhi* temp : chiphi) {
        cout << getdate_mocthoigian(i++) << "\t";
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

/*  
    Lap ke hoach gui chi tieu, tiet kiem va tra no 
    - Nguon thu vo chong: gui tiet kiem
    - Nguon thu khac: chi tieu va tra no
    - Uu tien tra no co so tien nhieu hon
*/
void QuanLy::process() {
    
    // CAP NHAT TIEN CHI TIEU
    // ======================
    tienchitieu.clear();

    // cap nhat tu nguon thu
    for (NguonThu* nt: nguonthu) {
        tienchitieu.push_back(nt->tongKhac());
    }

    // cap nhat tu chi tieu 
    int i = 0; 
    while (i < tienchitieu.size()) {
        tienchitieu[i] -= chiphi[i]->tong();
        i++;
    }
    if (i < chiphi.size()) {
        tienchitieu.push_back(0-chiphi[i]->tong());
        i++;
    }
    
    // cap nhat tu no 
    int pos_cur = 0;    
    for (No* n: no) {
        int pos_end = n->get_ngaytra() - mocthoigian;
        int thoigiantra = pos_end - pos_cur;  
        int cnt = n->get_solantinhlai();    

        for (;pos_cur <= pos_end; pos_cur++) {
            if (exist(tienchitieu, pos_cur)) {
                tienchitieu[pos_cur] -= n->tongNoSauKyHanThu(cnt) / thoigiantra;
            } else {
                tienchitieu.push_back(0 - n->tongNoSauKyHanThu(cnt) / thoigiantra);
            }
        }
    }

    /*  
        TAO SO TIET KIEM 
        ================

        Thuật toán:
        - Chọn ra option có lãi cao nhất (X) và option có kỳ hạn ngắn nhất (Y) (bỏ qua những option k hiệu quả)
        - Nếu thòi gian trả nợ (payingtime) > mọi kỳ hạn tiết kiệm -> k thể tạo lãi trong thời gian nợ này -> tạo sổ X
        - payingtime = m*X.kyhan + n*Y.kyhan + r 
            + nếu m > 0 -> tạo m (m+1 nếu r > 0) sổ X, n sổ y
            + nếu m = 0
                - tìm sổ Z sao cho payingtime = p*Z.kyhan + n*Y.kyhan + r -> tạo p sổ Z, n sổ Y (và 1 sổ X nếu r > 0)
                - Nếu không có sổ Z thoả mãn, payingtime = n*Y.kyhan + r -> tạo n sổ Y (và 1 sổ X nếu r > 0)
    */
    
    
}