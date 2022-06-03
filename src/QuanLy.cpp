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
        return;
    }
    mocthoigian += stoi(date.substr(3, 2));
    mocthoigian += stoi(date.substr(6)) * 12;
}

int QuanLy::get_mocthoigian() {
    return mocthoigian;
}

string QuanLy::getdate_mocthoigian(int idx) {
    if (mocthoigian == 0) {
        string res = "(chua nhap moc thoi gian)";
        return res;
    }
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
    if (!checkDateFormat(ngayno) && !checkDateFormat(ngayno)) {
        cout << "QuanLy::add_no(): invalid date format (DD-MM-YYYY)\n";
        return;
    }
    cout << "Ngay tra: "; getline(cin, ngaytra);
    if (!checkDateFormat(ngaytra) && !checkDateFormat(ngayno)) {
        cout << "QuanLy::add_no(): invalid date format (DD-MM-YYYY)\n";
        return;
    }
    cout << "Ky han: "; cin >> kyhan;

    No* temp = new No(sotien, ngayno, ngaytra, kyhan);
    no.push_back(temp);
    /* Uu tien tra no nhieu hon */
    sort(no.begin(), no.end());
}

int QuanLy::add_stk(int idx, SavingOption* opt) {
    if (idx < tienvochong.size()) {
        SoTietKiem* tmp;
        // nếu tiensauchitieuno bị âm, dùng tiền vợ chồng bù qua, số tiền tạo sổ sẽ bớt đi 1 khoản
        if (idx < tiensauchitieu.size()) {
            if (tiensauchitieu[idx] < 0)  {
                if (tienvochong[idx] + tiensauchitieu[idx] > 0) {
                    tmp = new SoTietKiem(tienvochong[idx] + tiensauchitieu[idx], *opt);
                }
                else return 0;
            }
        }

        tmp = new SoTietKiem(tienvochong[idx], *opt);
        stk.push_back(tmp);
    }
    else {
        cout << "Nguon thu thang " << getdate_mocthoigian(idx) << " chua duoc nhap\n";
        return -1;
    }
    return 0;
}

void QuanLy::add_option(){
    SavingOption* temp= new SavingOption;
    cout << "Nhap ky han (thang): "; cin >> temp->kyhan;
    cout << "Nhap lai: "; cin >> temp->lai;
    
    options.push_back(temp);

}


int QuanLy::get_sizenguonthu(){
    return nguonthu.size();
}

int QuanLy::get_sizechiphi(){
    return chiphi.size();
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
        cout<<"\n";
    }
}


// rút từ sổ mới trước
int QuanLy::ruttien(double sotienphaitra, int pos) {
    for (int i = pos; i >= 0; i--) {
        if (stk[pos]->isDaohan()) continue;
        if (stk[pos]->get_sotien() > sotienphaitra) {
            stk[pos]->set_sotien(stk[pos]->get_sotien() - sotienphaitra);
            return 0;
        } else {
            sotienphaitra -= stk[pos]->get_sotien();
            stk[pos]->set_sotien(0);
            stk[pos]->setDaohan();
        }
    }
    return -1;
}

/* THANG | NGUON>>VOCHONG | KHAC | CHIPHI | STK>>TRONGKYHAN | DAOHAN | TAOSTK:SOTIEN | KYHAN | LAI | NO>>SOTIEN */
string QuanLy::exportData() {
    vector<double> notrungbinh;
    string data = "";
    vector<string> values;
    values.push_back("THANG");
    values.push_back("NGUON THU VO CHONG");
    values.push_back("NGUON THU KHAC");
    values.push_back("TONG CHI PHI");
    values.push_back("THU NHAP SAU CHI TIEU");
    values.push_back("TIEN DAO HAN");
    values.push_back("SO TIEN TAO STK");
    values.push_back("KY HAN");
    values.push_back("LAI");
    values.push_back("NO TRUNG BINH");
    data += CSVParser::writeLine(values);
    values.clear();

    int idx_no =0;
    if (!no.empty()) {
        double temp=0;
        for(int j=no.size()-1; j >= 0; j--){
            temp=no[j]->tongNoNgayTra();
            if(notrungbinh.empty()==true) notrungbinh.push_back(temp/(no[j]->get_ngaytra()-mocthoigian));
            else notrungbinh.push_back(temp/(no[j]->get_ngaytra()-no[j]->get_ngayno())+notrungbinh.back());
        }
    }
    
    for (int i = 0; i < nguonthu.size(); i++) {
        values.push_back(getdate_mocthoigian(i));
        values.push_back(to_string(nguonthu[i]->tongVoChong()));
        values.push_back(to_string(nguonthu[i]->tongKhac()));
        if (i < chiphi.size()) 
            values.push_back(to_string(chiphi[i]->tong()));
        else 
            values.push_back("0");

        if(i<thunhapsauchitieu.size())
            values.push_back(to_string(thunhapsauchitieu[i]));
        else
            values.push_back("0");

        values.push_back(to_string(daohan[i]));

        if (i < stk.size()) {
            values.push_back(to_string(stk[i]->get_sotien()));
            values.push_back(to_string(stk[i]->get_kyhan()));
            values.push_back(to_string(stk[i]->get_lai()));
        }
        else {
            values.push_back("NULL");
            values.push_back("NULL");
            values.push_back("NULL");
        }

        
        int sizenotb=notrungbinh.size();
        if (!no.empty()) {
            if (idx_no < no.size() && i < no[idx_no]->get_ngaytra() - mocthoigian)
                values.push_back(to_string(notrungbinh[sizenotb - 1 - idx_no]));
            if (idx_no < no.size() && i == no[idx_no]->get_ngaytra() - mocthoigian - 1) idx_no++;
        }
        else values.push_back("NULL");

        data += "\n";
        data += CSVParser::writeLine(values);
        values.clear();

        
    }

    return data;
}

/*  
    Lap ke hoach gui chi tieu, tiet kiem va tra no 
    - Nguon thu vo chong: gui tiet kiem
    - Nguon thu khac: chi tieu va tra no
    - Uu tien tra no co so tien nhieu hon
*/
void QuanLy::process() {

    /*
        CẬP NHẬP, XỬ LÝ
        ================
        chenhlech = 0
        1. tiensauchitieu = nguonthu.khac và tienvochong = nguonthu.vochong
        2. Xử lý đáo hạn: duyệt qua sổ tiết kiêm, sổ nào đáo hạn thì tienvochong += stk[x].sodu()
        3. tiensauchitieu -= chiphi. Nếu âm tienvochong += tiensauchitieu, tiensauchitieu = 0
                tienvochong < 0, tienvochong += rút tiền từ stk cho tới khi = 0 hoặc hết tiền stk
                    - hết tiền stk: Tuyên bố phá sản
        4. Ngày trả nợ: chenhlech = no
        nếu chenhlech <= tienvochong: tienvochong -= chenhlech
        nếu chenhlech > tienvochong: chenhlech -= tienvochong, tienvochong = 0,
            chenhlech -= rút tiền từ stk cho tới khi = 0 hoặc hết tiền stk
                - hết tiền stk: Tuyên bố phá sản
        5. Tạo Sổ tiết kiệm (chỉ khi tienvochong > 0)
    */



    thunhapsauchitieu.clear();
    daohan.clear();
    double chenhlech = 0;
    tiensauchitieu.clear();
    tienvochong.clear();
    stk.clear();
    int pos_cur = 0;
    int idx_no = 0;
    No* ptr_no = NULL;
    int pos_trano;
    if (idx_no < no.size()) {
        pos_trano = no[idx_no]->get_ngaytra() - get_mocthoigian();
        ptr_no = no[idx_no];
    }


    int flag_tiensauchitieu; //Cờ thông báo tháng này có bị âm tiền hay không

    double chitieuam;
    double tiendaohan;

    for (;; pos_cur++) {

        flag_tiensauchitieu = 0;
        chitieuam = 0;
        tiendaohan = 0;


        //
        if (ptr_no != NULL && pos_cur >= pos_trano) {
            idx_no++;
            if (idx_no < no.size()) {
                pos_trano = no[idx_no]->get_ngaytra() - get_mocthoigian();
                ptr_no = no[idx_no];
            }
        }

        // 1. tiensauchitieu = nguonthu.khac và tienvochong = nguonthu.vochong 
        if (nguonthu.empty() || (pos_cur != 0 && pos_cur >= nguonthu.size())) {
            return;
        }
        tiensauchitieu.push_back(nguonthu[pos_cur]->tongKhac());
        tienvochong.push_back(nguonthu[pos_cur]->tongVoChong());

        // 2. Xử lý đáo hạn: duyệt qua sổ tiết kiêm, sổ nào đáo hạn thì tienvochong += stk[x].sodu()
        for (SavingOption* opt : options) {
            int pos_daohan = pos_cur - opt->kyhan;
            if (pos_daohan >= 0 && stk[pos_daohan]->get_kyhan() == opt->kyhan && !stk[pos_daohan]->isDaohan()) {

                tienvochong[pos_cur] += stk[pos_daohan]->soduSauKyHan(1);

                tiendaohan += stk[pos_daohan]->soduSauKyHan(1);

                stk[pos_daohan]->setDaohan();

            }
        }

        // 3. tiensauchitieu -= chiphi. Nếu âm tienvochong += tiensauchitieu, tiensauchitieu = 0
        //         tienvochong < 0, tienvochong += rút tiền từ stk cho tới khi = 0 hoặc hết tiền stk
        //             - hết tiền stk: Tuyên bố phá sản
        if (pos_cur < chiphi.size()) {
            tiensauchitieu[pos_cur] -= chiphi[pos_cur]->tong();
            chitieuam = tiensauchitieu[pos_cur];
            if (tiensauchitieu[pos_cur] < 0) {
                tienvochong[pos_cur] += tiensauchitieu[pos_cur];
                tiensauchitieu[pos_cur] = 0;
                flag_tiensauchitieu = 1;
                if (tienvochong[pos_cur] < 0) {
                    if (stk.empty()) {
                        cout << "QuanLy::Process(): PHA SAN vao thang " << getdate_mocthoigian(pos_cur) << " (khong co so tiet kiem)\n";
                        return;
                    }
                    else if (ruttien(-tienvochong[pos_cur], pos_cur) == -1) {
                        cout << "QuanLy::Process(): PHA SAN vao thang " << getdate_mocthoigian(pos_cur) << " (so du stk khong du)\n";
                        return;
                    }
                    else {
                        tienvochong[pos_cur] = 0;
                    }
                }
            }

            thunhapsauchitieu.push_back(tiensauchitieu[pos_cur]);

        }

        daohan.push_back(tiendaohan);
        // values.push_back(to_string(tiendaohan));


        if (pos_cur + 1 == chiphi.size()) {
            //Chi tiêu âm dương
            cout << "QuanLy::Process(): Thu nhap sau chi tieu cua thang " << getdate_mocthoigian(pos_cur) << " la: " << tiensauchitieu[pos_cur] << endl;
            if (flag_tiensauchitieu == 1) cout << "So tien tham hut vao luong vo chong: " << -chitieuam << endl;
            // else cout<<"Chi tieu duong"<<endl;


            //Nhận xét phá sản
            double kiemtra = nguonthu[pos_cur]->tong() - chiphi[pos_cur]->tong();
            if (kiemtra < 0) cout << "QuanLy::Process(): SE PHA SAN VOI MUC CHI TIEU NAY ";
        }


        // 4. Ngày trả nợ: chenhlech = no
        // nếu chenhlech <= tienvochong: tienvochong -= chenhlech
        // nếu chenhlech > tienvochong: chenhlech -= tienvochong, tienvochong = 0,
        //     chenhlech -= rút tiền từ stk cho tới khi = 0 hoặc hết tiền stk
        //         - hết tiền stk: Tuyên bố phá sản       
        if (ptr_no != NULL && pos_cur == pos_trano) {
            double chenhlech = ptr_no->tongNoNgayTra();
            if (chenhlech < tienvochong[pos_cur]) tienvochong[pos_cur] -= chenhlech;
            else {
                chenhlech -= tienvochong[pos_cur];
                tienvochong[pos_cur] = 0;
                if (ruttien(chenhlech, pos_cur) == -1) {
                    cout << "QuanLy::process(): PHA SAN vao thang " << getdate_mocthoigian(pos_cur) << " (so du stk khong du)\n";
                    return;
                }
            }
        }

        // 5. Tạo Sổ tiết kiệm (chỉ khi tienvochong > 0)
        if (tienvochong[pos_cur] <= 0) continue;

        /*
            TẠO SỔ TIẾT KIỆM
            ================
            Nợ to trả trước, nợ nhỏ trả sau
            Thuật toán:
            1. Chon ra saving option có lãi cao nhất mà kyhan <= ngaytrano
                Nếu không có, tạo sổ với saving option có lãi cao nhất
        */

        if (options.empty()) continue;
        vector<SavingOption*> options_copy = options;
        int pos_best = get_best_option(options_copy);
        if (ptr_no != NULL) {
            while (options_copy[pos_best]->kyhan + pos_cur > pos_trano) {
                options_copy.erase(options_copy.begin() + pos_best);
                if (!options_copy.empty()) {
                    pos_best = get_best_option(options_copy);
                }
                else break;
            }
            if (options_copy.empty()) {
                pos_best = get_best_option();
                add_stk(pos_cur, options[pos_best]);
            }
            else {
                add_stk(pos_cur, options_copy[pos_best]);
            }
        }
        else add_stk(pos_cur, options_copy[pos_best]);


    }


}