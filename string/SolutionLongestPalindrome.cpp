//
// leetcode-cpp
// 最长回文子串 https://leetcode-cn.com/problems/longest-palindromic-substring/

#include <vector>
#include "SolutionLongestPalindrome.h"

// 以左右为中心向两边扩展最大的回文数
string centerSpread(string str, int left, int right) {
    int i = left;
    int j = right;
    while (i >= 0 && j < str.size()) {
        if (str[i] == str[j]) {
            i--;
            j++;
        } else {
            break;
        }
    }
    return str.substr(i + 1, j - i - 1);
}

// 中心扩散
string SolutionLongestPalindrome::longestPalindrome(string s) {
    if (s.size() < 2) {
        return s;
    }
    int maxLen = 1;
    string maxStr = s.substr(0, 1);
    for (int i = 0; i < s.size() - 1; i++) {
        string oddstr = centerSpread(s, i, i);
        string evenstr = centerSpread(s, i, i + 1);
        string tempMax = oddstr.size() > evenstr.size() ? oddstr : evenstr;
        if (tempMax.size() > maxLen) {
            maxStr = tempMax;
            maxLen = tempMax.size();
        }
    }
    return maxStr;
}

std::string SolutionLongestPalindrome::longestPalindrome2(std::string s) {
    if (s.size() < 2) {
        return s;
    }
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = true;
    }
    int maxLen = 1;
    int startPos = 0;
    // 以长度判断是否是回文子串
    for (int len = 2; len <= s.size(); len++) {
        for (int i = 0; i < s.size() - 1; i++) {
            int j = len + i - 1;// i从0开始，j-i+1=len，所以可以计算出j
            if (j >= s.size()) {
                break;
            }
            if (s[i] == s[j]) {
                if (j - i <= 2) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            } else {
                dp[i][j] = false;
            }
            // 计算最大回文子串
            if (dp[i][j] == true && j - i + 1 > maxLen) {
                startPos = i;
                maxLen = j - i + 1;
            }
        }
    }
    string res = s.substr(startPos, maxLen);
    return res;
}