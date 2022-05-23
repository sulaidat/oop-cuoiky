#ifndef SOTIETKIEM_H
#define SOTIETKIEM_H

class SoTietKiem {
protected:
    enum Lai {
        THANG = 1,
        _6THANG = 6,
        NAM = 12
    };
    double sotien;
    float lai;
    int kyhan;
public:
    SoTietKiem();
    SoTietKiem(const SoTietKiem&);
    SoTietKiem(double, float, int);
    double soDuSauKyHan(int);
};

#endif