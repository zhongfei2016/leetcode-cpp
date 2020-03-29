//
// Created by ZHONGFEI on 2020/3/29.
//

#include "LuckFibonacciStrSln.h"

#include <algorithm>
#include <cstring>

set<int> GetFibonacciNums(int n) {
    set<int> fibonacciSet;
    if (n == 1 || n == 2) {
        fibonacciSet.insert(1);
        return fibonacciSet;
    }
    fibonacciSet.insert(1);
    int f1 = 1, f2 = 1;
    int sum = f1 + f2;
    while (sum <= n) {
        fibonacciSet.insert(sum);
        f1 = f2;
        f2 = sum;
        sum = f1 + f2;
    }
    return fibonacciSet;
}

bool isFibonacci(string s, set<int> fibonacciSet) {
    set<char> charSet;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        charSet.insert(*iter);
    }
    return !fibonacciSet.emplace(charSet.size()).second;
}

set<string> LuckFibonacciStrSln::ListLuckFiboSubStr(string input) {
    int size = input.size();
    // set默认排序
    set<string> luckStrSet;
    set<int> fibonacciSet = GetFibonacciNums(size);
    string subStr;
    for (int i = 0; i < input.size(); i++) {
        for (int j = i + 1; j <= input.size(); j++) {
            subStr = input.substr(i, j - i);
            if (isFibonacci(subStr, fibonacciSet)) {
                luckStrSet.emplace(subStr);
            }
        }
    }
    return luckStrSet;
}
