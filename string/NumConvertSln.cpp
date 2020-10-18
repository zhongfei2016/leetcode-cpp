//
// Created by ZHONGFEI on 2020/10/18.
//

#include "NumConvertSln.h"

#include <string>
#include <sstream>
#include <bitset>
#include <cmath>

using namespace std;

// atoi/atof如果起始就无法转换会报异常，strtod就不会，而是把不符合的值传给入参指针，所以如果strPtr==str，则说明整个str都无法转为数字
bool IsDouble(string str) {
    char *strPtr = nullptr;
    double res = strtod(str.c_str(), &strPtr);
    return strPtr != str && *strPtr == '\0' && res != HUGE_VAL;
}

bool IsNum(string str) {
    stringstream ss(str);
    double dnum;
    if (!(ss >> dnum)) {
        return false;
    }
    char p;
    if (ss >> p) {
        return false;
    }
    return true;
}

string DecimalStrToBinaryStr(string str) {
    int num = std::stoi(str);
    return std::bitset<32>(num).to_string();
}

string BinaryStrToDecimalStr(string str) {
    // method 1
    std::size_t idx = -1;
    int res = std::stoi(str, &idx, 2);
    // method 2
    uint32_t ulRes = std::bitset<32>(str).to_ulong();

    // int res to string
    string strRes = std::to_string(res);
    strRes = std::to_string(ulRes);
    return strRes;
}

void NumConvertSln::NumConvertTest() {
    char *str2dPtr = nullptr;
    double d1 = strtod("123.5", &str2dPtr);
    double d2 = strtod("123.5abc", &str2dPtr);
    double d3 = strtod("-123.5abc", &str2dPtr);

    bool flag1 = IsDouble("123.5abc");
    bool flag2 = IsDouble("123.5");
    bool flag3 = IsDouble("-123.5abc");
    bool flag4 = IsDouble("-a123.5abc");
    bool flag5 = IsDouble("a123.5abc");
    bool flag6 = IsDouble("123abc");
    bool flag7 = IsDouble("a123");
    bool flag8 = IsDouble("123");
    bool flag9 = IsDouble("-123");

    std::size_t index = -1;
    int i1 = std::stoi("123", &index);
    int i2 = std::stoi("-123", &index);
    int i3 = std::stoi("1a23", &index);

    bool isInt1 = IsNum("a123");
    bool isInt2 = IsNum("123");
    bool isInt3 = IsNum("-123");
    bool isInt4 = IsNum("-123a");
    bool isInt5 = IsNum("123ab");

    string bsStr = std::bitset<8>(255).to_string();
    string binaryStr = DecimalStrToBinaryStr("255");
    string decimalStr1 = BinaryStrToDecimalStr("1111011");
    string decimalStr2 = BinaryStrToDecimalStr("0");
    return;
}