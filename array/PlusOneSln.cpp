//
// Created by ZHONGFEI on 2020/4/12.
//

#include "PlusOneSln.h"
#include <algorithm>

vector<int> PlusOneSln::plusOne(vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        // 倒序，从末位开始加1
        digits[i]++;
        digits[i] = digits[i] % 10;
        // 除以10取余如果等于他自己，就是等于一个非0的数，说明没有进位，返回当前数组即可
        if (digits[i] != 0) {
            return digits;
        }
    }
    // 一直到最后都有进位，说明后面全是0，第一个给1返回即可
    digits = vector<int>(digits.size() + 1, 0);
    digits[0] = 1;
    return digits;

    reverse(digits.begin(), digits.end());
    int flag = 0;
    if (digits[0] + 1 == 10) {
        flag = 1;
        digits[0] = 0;
    } else {
        digits[0] += 1;
    }
    if (digits.size() == 1) {
        if (flag == 1) {
            digits.push_back(flag);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
    for (int i = 1; i < digits.size(); i++) {
        if (digits[i] + flag == 10) {
            flag = 1;
            digits[i] = 0;
            if (digits.size() == i + 1) {
                digits.push_back(1);
                flag = 0;
            }
        } else {
            digits[i] += flag;
            flag = 0;
        }
    }
    reverse(digits.begin(), digits.end());
    return digits;
}