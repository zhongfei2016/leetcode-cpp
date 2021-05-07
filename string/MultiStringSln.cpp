//
// leetcode-cpp
// 字符串相乘 https://leetcode-cn.com/problems/multiply-strings/
//

#include <algorithm>
#include <vector>
#include "MultiStringSln.h"

std::string MultiStringSln::multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    int n = num1.size();
    int m = num2.size();
    string res = "0";
    // 用num2的每个数字去乘以num1，从个位也就是倒序往前算
    for (int i = m - 1; i >= 0; i--) {
        string temp;
        // 从个位开始，每往前进一步，temp字符串要先补足够的0
        for (int j = 0; j < (m - 1) - i; j++) {
            temp += '0';
        }
        int curNum2 = num2[i] - '0';
        int carry = 0;
        for (int k = n - 1; k >= 0; k--) {
            int curNum1 = num1[k] - '0';
            int product = (curNum1 * curNum2 + carry);
            temp += product % 10 + '0';
            carry = product / 10;
        }
        if (carry > 0) {
            temp += carry + '0';
        }
        reverse(temp.begin(), temp.end());
        res = addString(res, temp);
    }
    return res;
}

std::string MultiStringSln::addString(std::string str1, std::string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<char> vec(abs(n - m), '0');
    int maxSize = m;
    if (n > m) {
        str2.insert(str2.begin(), vec.begin(), vec.end());
        maxSize = n;
    }
    // 当前是正序，补0是为了两数相加时不会越界访问
    if (m > n) {
        str1.insert(str1.begin(), vec.begin(), vec.end());
    }
    int carry = 0;
    string res;
    for (int i = maxSize - 1; i >= 0; i--) {
        int product = str1[i] - '0' + str2[i] - '0' + carry;
        res += product % 10 + '0';
        carry = product / 10;
    }
    if (carry > 0) {
        res += carry + '0';
    }
    std::reverse(res.begin(), res.end());
    return res;
}