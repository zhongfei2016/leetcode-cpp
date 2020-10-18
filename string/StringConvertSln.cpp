//
// Created by ZHONGFEI on 2020/10/18.
//

#include "StringConvertSln.h"

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <regex>

using namespace std;

vector<string> split2(string &str, string &separator) {
    std::regex reg("\\.");
    vector<string> v(std::sregex_token_iterator(str.begin(), str.end(), reg, -1), std::sregex_token_iterator());
    return v;
}

vector<string> split(string &str, string &separator) {
    vector<string> ipNums;
    int start = 0;
    int idx = 0;
    while (idx != std::string::npos) {
        idx = str.find_first_of(separator, start);
        if (idx == string::npos) {
            break;
        }
        ipNums.push_back(str.substr(start, idx - start));
        start = str.find_first_not_of(separator, idx);
        if (start == string::npos) {
            break;
        }
    }
    if (start != string::npos) {
        ipNums.push_back(str.substr(start));
    }
    return ipNums;
}

vector<string> basicSplit(string &str, string &sep) {
    vector<string> res;
    int beginPos = 0;
    int idx = 0;
    while ((idx = str.find(sep, beginPos)) != string::npos) {
        res.push_back(str.substr(beginPos, idx - beginPos));
        beginPos = idx + 1;
    }
    if (beginPos < str.size()) {
        res.push_back(str.substr(beginPos));
    }
    return res;
}

string join(vector<string> &vec, string &sep) {
    string ipRes;
    std::for_each(vec.begin(), vec.end() - 1, [&](string &str) { ipRes.append(str + sep); });
    ipRes = ipRes.append(vec[vec.size() - 1]);
    return ipRes;
}

void StringConvertSln::StringConvertTest() {
    string str = "255.2.1.234";
    string sep = ".";
    vector<string> ipNums = split(str, sep);
    vector<string> ipNums2 = split2(str, sep);
    vector<string> basicIpNums = basicSplit(str, sep);
    str = "255||2||1||234";
    sep = "||";
    ipNums = split(str, sep);

    string ipRes = join(ipNums, sep);
    std::cout << ipRes << std::endl;
}