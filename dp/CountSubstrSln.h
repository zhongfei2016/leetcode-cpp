//
// leetcode-cpp
//
// 回文子串 https://leetcode-cn.com/problems/palindromic-substrings/

#ifndef LEETCODE_CPP_COUNTSUBSTRSLN_H
#define LEETCODE_CPP_COUNTSUBSTRSLN_H

//使用动态规划， dp[i][j] 代表str[i] - str[j]是否是回文子串

#include <string>

using namespace std;

class CountSubstrSln {
public:
    int countSubstrings(string s);
};


#endif //LEETCODE_CPP_COUNTSUBSTRSLN_H
