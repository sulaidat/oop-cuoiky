#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <regex>
#include <vector>
using namespace std;

bool checkDateFormat(string date);

template<class T>
bool exist(vector<T>, int);

#endif