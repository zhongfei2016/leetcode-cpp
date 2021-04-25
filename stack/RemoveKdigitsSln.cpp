//
// Created by ZHONGFEI on 2021/4/25.
//  移除K个数 https://leetcode-cn.com/problems/remove-k-digits/

#include <stack>
#include "RemoveKdigitsSln.h"

std::string RemoveKdigitsSln::removeKdigits(std::string num, int k) {
    deque<char> stk;
    if (k == 0 || num.empty()) {
        return num;
    }
    if (k >= num.size()) {
        return "0";
    }
    int remain = k;
    int n = num.size();
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && remain > 0 && (stk.back()) > num[i]) {
            stk.pop_back();
            remain--;
        }
        stk.push_back(num[i]);
    }
    while (stk.size() > n - k) {
        stk.pop_back();
    }
    string ans;
    bool remvZero = false;
    while (!stk.empty()) {
        if (!remvZero && stk.front() == '0') {
            stk.pop_front();
            continue;
        } else {
            remvZero = true;
        }
        ans += stk.front();
        stk.pop_front();
    }
    if (ans.empty()) {
        ans = "0";
    }
    return ans;
}