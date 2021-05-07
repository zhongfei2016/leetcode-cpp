//
// leetcode-cpp
//

#include "AddBinarySln.h"
#include <vector>

string AddBinarySln::addBinary(string a, string b) {
    // 先补齐
    int aSize = a.size(), bSize = b.size();
    while (bSize < aSize) {
        b = '0' + b;
        bSize++;
    }
    while (aSize < bSize) {
        a = '0' + a;
        aSize++;
    }
    int carry = 0;
    // 倒序逐位求和
    for (int i = aSize - 1; i >= 0; i--) {
        int temp = a[i] - '0' + b[i] - '0' + carry;
        // 除以2取余是当前值，取商是进位值
        a[i] = temp % 2 + '0';
        carry = temp / 2;
    }
    if (carry > 0) {
        return '1' + a;
    }
    return a;
}

void AddBinarySln::reverseString(vector<char> &s) {
    if (s.empty()) {
        return;
    }
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return;
}