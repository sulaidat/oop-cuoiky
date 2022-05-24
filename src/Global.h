#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <regex>
#include <iostream>
using namespace std;

bool checkDateFormat(string date) { 
    /* DD-MM-YYYY */
    regex e("^(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-\\d{4}$");
    return regex_match(date, e);
}

#endif