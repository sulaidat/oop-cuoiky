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

int QuanLy::get_best_option(vector<SavingOption*> opts) {
    int idx = -1;
    int i = 0;
    float best = 0;
    for (SavingOption* opt: opts) {
        if (best < opt->lai/opt->kyhan) {
            best = opt->lai/opt->kyhan;
            idx = i;
        }
        ++i;
    }
    return idx;
}

int QuanLy::get_shortest_option(vector<SavingOption*> opts) {
    int idx = -1;
    int i = 0;
    float best = __FLT_MAX__;
    // chon ky han ngan nhat
    for (SavingOption* opt: opts) {
        if (best > opt->kyhan) {
            best = opt->kyhan;
            idx = i;
        }
        ++i;
    }
    // chon option hieu qua nhat trong cac ky han ngan nhat
    best = 0;
    i = 0;
    for (SavingOption* opt: opts) {
        if (opt->kyhan == opts[idx]->kyhan && best < opt->lai/opt->kyhan) {
            best = opt->lai/opt->kyhan;
            idx = i;
        }
        ++i;   
    }
    return idx;
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
    getchar();  // getline is anoying
    cout << "Ngay no: "; getline(cin, ngayno);
    cout << "Ngay tra: "; getline(cin, ngaytra);
    cout << "Ky han: "; cin >> kyhan;

    No* temp = new No(sotien, ngayno, ngaytra, kyhan);
    no.push_back(temp);
    /* Uu tien tra no nhieu hon */
    sort(no.begin(), no.end());
}

int QuanLy::add_stk(int idx, SavingOption* opt) {
    if (idx < tienvochong.size()) {
        SoTietKiem* tmp;
        // nếu tháng đó chi tiêu bị âm, dùng tiền vợ chồng bù qua, số tiền tạo sổ sẽ bớt đi 1 khoản
        // (chưa làm) còn trường hợp bù xong tiền vợ chồng bị âm
        if (idx < tienchitieu.size() && tienchitieu[idx] < 0)  {
            tmp = new SoTietKiem(tienvochong[idx] + tienchitieu[idx], *opt);
        }
        else {
            tmp = new SoTietKiem(tienvochong[idx], *opt);         
        }
        stk.push_back(tmp);
    }
    else {
        cout << "Nguon thu thang " << getdate_mocthoigian(idx) << " chua duoc nhap\n";
        return -1;
    }
    return 0;
}

void QuanLy::inNguonThu() {
    int i = 0;
    cout << "THANG\tVO\tCHONG\tKHAC\n";
    for (NguonThu* temp : nguonthu) {
        if (mocthoigian == 0) cout << "NULL" << "\t";
        else cout << getdate_mocthoigian(i++) << "\t";
        temp->print();
    }
}

void QuanLy::inChiPhi () {
    int i = 0;
    cout << "THANG\tSINHHOAT\tKHAC\n";
    for (ChiPhi* temp : chiphi) {
        if (mocthoigian == 0) cout << "NULL" << "\t";
        else cout << getdate_mocthoigian(i++) << "\t";
        temp->print();
    }
}

void QuanLy::inNo() {
    int i = 0;
    cout << "SOTIEN\tNGAYNO\tNGAYTRA\n";
    for (No* temp : no) {
        temp->print();
    }
}

/* NGUONTHUVOCHONG | NGUONTHUKHAC | CHIPHI | SODUTIETKIEM | NOTRUNGBINH | CHIPHI-NOTRUNGBINH */
// string QuanLy::exportData() {

// }

/*  
    Lap ke hoach gui chi tieu, tiet kiem va tra no 
    - Nguon thu vo chong: gui tiet kiem
    - Nguon thu khac: chi tieu va tra no
    - Uu tien tra no co so tien nhieu hon
*/
void QuanLy::process() {
    
    // CẬP NHẬT TIỀN (DÙNG ĐỂ) CHI TIÊU VÀ TIỀN VỢ CHỒNG
    // ======================
    tienchitieu.clear();
    tienvochong.clear();

    // Cập nhật từ nguồn thu
    for (NguonThu* nt: nguonthu) {
        tienchitieu.push_back(nt->tongKhac());
        tienvochong.push_back(nt->tongVoChong());
    }

    // Cập nhật từ chi phí 
    if (!chiphi.empty()) {
        int i = 0; 
        while (i < tienchitieu.size()) {
            tienchitieu[i] -= chiphi[i]->tong();
            i++;
        }
        if (i < chiphi.size()) {
            tienchitieu.push_back(0-chiphi[i]->tong());
            i++;
        }
    }
    
    // Cập nhật từ nợ 
    int pos_cur = 0;    
    int pos_cur2 = 0;
    for (No* n: no) {
        int pos_end = n->get_ngaytra() - mocthoigian;
        int payingtime = pos_end - pos_cur;  
        int cnt = n->get_solantinhlai();    

        for (;pos_cur <= pos_end; pos_cur++) {
            if (pos_cur < tienchitieu.size()) {
                tienchitieu[pos_cur] -= n->tongNoSauKyHanThu(cnt) / payingtime;
            } else {
                tienchitieu.push_back(0 - n->tongNoSauKyHanThu(cnt) / payingtime);
            }
            // nếu tháng trước chi tiêu có dư thì cộng vô 
            if (pos_cur > 0 && tienchitieu[pos_cur-1] > 0) 
                tienchitieu[pos_cur] += tienchitieu[pos_cur-1];
        }

        // TẠO SỔ TIẾT KIỆM
        vector<SavingOption*> options_copy = options;
        while (1) {
            int pos_best = get_best_option(options_copy);
            int pos_short = get_shortest_option(options_copy);

            // payingtime < short.kyhan
            if (payingtime < options_copy[pos_short]->kyhan) {
                for (; pos_cur2 <= pos_end; pos_cur2++) {
                    if (add_stk(pos_cur2, options_copy[pos_best]) == -1) {
                        break;
                    }
                }
            }

            // payingtime >= best.kyhan
            else if (payingtime >= options_copy[pos_best]->kyhan) {
                while (pos_cur2 + options_copy[pos_best]->kyhan <= pos_end) {
                    if (add_stk(pos_cur2++, options_copy[pos_best]) == -1) {
                        break;
                    }
                }
                for (; pos_cur2 <= pos_end; pos_cur2++) {
                    if (add_stk(pos_cur2, options_copy[pos_short]) == -1) {
                        break;
                    }
                }
            }

            // short.kyhan <= payingtime < best.kyhan
            else {
                options_copy.erase(options_copy.begin() + pos_best);
                continue;
            }
        }
    }

    /*  
        TẠO SỔ TIẾT KIỆM
        ================
        Nợ to trả trước, nợ nhỏ trả sau 
        Thuật toán:
        1 Chọn ra option có lãi cao nhất (X) và option có kỳ hạn ngắn nhất (Y) 
        2 Nếu payingtime < Y.kyhan -> tạo toàn sổ X
        3 Nếu payingtime >= X.kyhan -> tạo nbest = (payingtime - X.kyhan + 1) sổ X và nshort = payingtime - nbest sổ Y
            (Ví dụ payingtime = 4, kỳ hạn X là 3 -> 2 tháng đầu tạo 2 sổ X, 2 tháng sau tạo 2 sổ Y)\
        4 Nếu Y <= payingtime < X -> bỏ X và lặp lại bước 1
    */

}