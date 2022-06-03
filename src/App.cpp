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
        // system("cls");
        print_menu();
        cout << "> ";
        int num = get_num();
        switch (num) {
            case Menu::NhapNgayBatDau: {
                string startday = "";
                cout << "Nhap ngay bat dau (DD-MM-YYYY): ";
                getline(cin, startday);
                
                quanly->update_mocthoigian(startday);
                // system("pause");
                break;
            }
            case Menu::NhapNguonThu: {
                print_sub_menu();
                num = get_num();
                switch (num) {
                    case SubMenu::ManualInput:
                        quanly->add_nguonthu();
                        // system("pause");
                        break;
                    case SubMenu::FromFile: {
                        string filepath;
                        cout << "Nhap filepath: ";
                        getline(cin, filepath);
                        cout << filepath << "\n";
                        quanly->add_nguonthu_fromfile(filepath);
                        // system("pause");
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
                        // system("pause");
                        break;
                    case SubMenu::FromFile: {
                        string filepath;
                        cout << "Nhap filepath: ";
                        getline(cin, filepath);
                        cout << filepath << "\n";
                        quanly->add_chiphi_fromfile(filepath);
                        // system("pause");
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case Menu::ThemNo: {
                if (!quanly->get_mocthoigian()) {
                    cout << "Chua nhap ngay bat dau\n";
                    break;
                }
                quanly->add_no();
                // system("pause");
                break;
            }
            case Menu::AddSavingOption: {
                quanly->add_option();
                // system("pause");
                break;
            }
            case Menu::InNguonThu:
                quanly->inNguonThu();
                // system("pause");
                break;
            case Menu::InChiPhi:
                quanly->inChiPhi();
                // system("pause");
                break;
            case Menu::InNo:
                quanly->inNo();
                // system("pause");
                break;
            case Menu::XuatBangTinh: {
                string data=quanly->exportData();
                ofstream out("data/xuat.csv");
                out << data;
                out.close();
                cout << "Data written to xuat.csv\n";
                // system("pause");
                break;
            }
            default:
                cout << "Exiting...\n";
                exit(-1);
        }
        quanly->process();   
        // system("pause");
    }
}