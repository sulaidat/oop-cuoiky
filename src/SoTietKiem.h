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
    double soDuSauKyHan(int);
    bool isDaohan();
    void setDaohan();
};

#endif