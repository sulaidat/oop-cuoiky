#include "App.h"

namespace Global {
    QuanLy* quanly;
    vector<NguonThu*> nguonthu;
    vector<ChiPhi*> chiphi;
    vector<No*> no;
    vector<SoTietKiem*> sotietkiem;
}
using namespace Global;

void App::init() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    quanly = new QuanLy(nguonthu, chiphi, no, sotietkiem);
}

void App::print_menu() {
    cout << "--------------------\n";
    cout << "What do?\n";
    cout << "0) Nhap ngay bat dau\n";
    cout << "1) Nhap nguon thu\n";
    cout << "2) Nhap chi phi\n";
    cout << "3) Them no\n";
    cout << "4) In nguon thu\n";
    cout << "5) In chi phi\n";
    cout << "6) In no\n";
    cout << "7) Xuat bang tinh\n";
}

void App::print_sub_menu() {
    cout << "--------------------\n";
    cout << "What do?\n";
    cout << "1) Manual input\n";
    cout << "2) From file\n";
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
                
                quanly->getTimeStamp(startday);
                break;
            }
            case Menu::NhapNguonThu: {
                print_sub_menu();
                num = get_num();
                switch (num) {
                    case SubMenu::ManualInput:
                        break;
                    case SubMenu::FromFile: {
                        string filepath;
                        cout << "Nhap filepath: ";
                        getline(cin, filepath);
                        cout << filepath << "\n";
                        quanly->readNguonThuFromFile(filepath);
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
                        break;
                    case SubMenu::FromFile: {
                        string filepath;
                        cout << "Nhap filepath: ";
                        getline(cin, filepath);
                        cout << filepath << "\n";
                        quanly->readChiPhiFromFile(filepath);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case Menu::ThemNo: {
                print_sub_menu();
                num = get_num();
                switch (num) {
                    case SubMenu::ManualInput:
                        break;
                    case SubMenu::FromFile: {
                        string filepath;
                        cout << "Nhap filepath: ";
                        getline(cin, filepath);
                        cout << filepath << "\n";
                        quanly->readNoFromFile(filepath);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case Menu::InNguonThu:
                quanly->printNguonThu();
                break;
            case Menu::InChiPhi:
                quanly->printChiPhi();
                break;
            case Menu::InNo:
                quanly->printNo();
                break;
            case Menu::XuatBangTinh:
                break;
            default:
                cout << "Exiting...\n";
                exit(-1);
        }
    }
}