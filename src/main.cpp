#include "QuanLy.h"
#include "App.h"
#include "Global.h"
#include <iostream>
using namespace std;

int main (){
    string date1 = "20-32-2022";
    string date2 = "20-03-2022";
    if (checkDateFormat(date1)) cout << date1 << "\n";
    if (checkDateFormat(date2)) cout << date2 << "\n";
    regex e("\\d{4}(?=$)");
    smatch m;
    regex_search(date2, m, e);
    cout << m.str() << "\n";
    cout << m.suffix() << "\n";
    return 0;
}