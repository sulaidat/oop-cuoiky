#ifndef SOTIETKIEM_H
#define SOTIETKIEM_H

struct SavingOption {
    float lai;
    int kyhan;
};

class SoTietKiem {
protected:
    double sotien;
    SavingOption savingoption;
    bool daohan;
public:
    SoTietKiem();
    SoTietKiem(const SoTietKiem&);
    SoTietKiem(double, SavingOption);
    void set_sotien(double);
    double get_sotien();
    int get_kyhan();
    float get_lai();
    double soduSauKyHan(int);
    bool isDaohan();
    void setDaohan();
};

#endif