#ifndef CHIPHI_H
#define CHIPHI_H

class ChiPhi {
protected:
    double sinhhoat;
    double khac;
public:
    ChiPhi();
    // ChiPhi(const ChiPhi&);
    ChiPhi(double, double);
    double tong();
};

#endif