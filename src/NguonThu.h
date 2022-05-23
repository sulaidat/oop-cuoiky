#ifndef NGUONTHU_H
#define NGUONTHU_H

class NguonThu {
protected:
    double vo;
    double chong;
    double khac;
public:
    NguonThu();
    NguonThu(const NguonThu&);
    NguonThu(double vo, double chong, double khac);
    double tong();
    double tongVoChong();
    double tongKhac();
};

#endif