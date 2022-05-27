#include "App.h"

namespace Global {
    QuanLy* quanly;
    vector<NguonThu*> nguonthu;
    vector<ChiPhi*> chiphi;
    vector<No*> no;
    vector<SoTietKiem*> sotietkiem;
    vector<SavingOption*> options;
}
using namespace Global;

void App::init() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    quanly = new QuanLy(nguonthu, chiphi, no, sotietkiem, options);
}

void App::print_menu() {
    cout << "--------------------\n";
    cout << "What do?\n";
    cout << "0) Nhap ngay bat dau\n";
    cout << "1) Nhap nguon thu\n";
    cout << "2) Nhap chi phi\n";
    cout << "3) Them no\n";
    cout << "4) Add saving option\n";
    cout << "5) In nguon thu\n";
    cout << "6) In chi phi\n";
    cout << "7) In no\n";
    cout << "8) Xuat bang tinh\n";
}

void App::print_sub_menu() {
    cout << "--------------------\n";
    cout << "What do?\n";
    cout << "0) Manual input\n";
    cout << "1) From file\n";
}

int App::get_num() {
    int num;
    if (scanf("%d", &num) != 1) {
        num = -1;
    }
    while ((getchar()) != '\n');
    return num;
}

void App::run() {
    init();
    while (1) {
        print_menu();
        cout << "> ";
        int num = get_num();
        switch (num) {
            case Menu::NhapNgayBatDau: {
                string startday = "";
                cout << "Nhap ngay bat dau (DD-MM-YYYY): ";
                getline(cin, startday);
                
                quanly->update_mocthoigian(startday);
                break;
            }
            case Menu::NhapNguonThu: {
                print_sub_menu();
                num = get_num();
                switch (num) {
                    case SubMenu::ManualInput:
                        quanly->add_nguonthu();
                        break;
                    case SubMenu::FromFile: {
                        string filepath;
                        cout << "Nhap filepath: ";
                        getline(cin, filepath);
                        cout << filepath << "\n";
                        quanly->add_nguonthu_fromfile(filepath);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case Menu::NhapChiPhi: {
                print_sub_menu();
                num = get_num();
                switch (num) {
                    case SubMenu::ManualInput:
                        quanly->add_chiphi();
                        break;
                    case SubMenu::FromFile: {
                        string filepath;
                        cout << "Nhap filepath: ";
                        getline(cin, filepath);
                        cout << filepath << "\n";
                        quanly->add_chiphi_fromfile(filepath);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case Menu::ThemNo: {
                quanly->add_no();
                break;
            }
            case Menu::AddSavingOption: {
                SavingOption* so = new SavingOption;
                cout << "Nhap ky han (thang): "; cin >> so->kyhan;
                cout << "Nhap lai: "; cin >> so->lai;
                options.push_back(so);
                break;
            }
            case Menu::InNguonThu:
                quanly->inNguonThu();
                break;
            case Menu::InChiPhi:
                quanly->inChiPhi();
                break;
            case Menu::InNo:
                quanly->inNo();
                break;
            case Menu::XuatBangTinh: {
                string data = quanly->exportData();
                ofstream out("data/xuat.csv");
                out << data;
                out.close();
                cout << "Data written to data/xuat.csv\n";
                break;
            }
            default:
                cout << "Exiting...\n";
                exit(-1);
        }
        quanly->process();
    }
}