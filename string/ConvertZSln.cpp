//
// Created by ZHONGFEI on 2021/4/11.
//

#include "ConvertZSln.h"

string ConvertZSln::convert(string s, int numRows) {
    if (numRows <= 1) {
        return s;
    }
    vector<string> results(numRows);
    int i = 0;
    int step = 1;
    for (auto &ch : s) {
        results[i].push_back(ch);
        i += step;
        if (i <= 0 || i >= (numRows - 1)) {
            step = -step;
        }
    }
    string ans{};
    for (auto &result : results) {
        ans += result;
    }
    return ans;
}
