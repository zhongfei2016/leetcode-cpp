//
// leetcode-cpp
//

#include "WordBreakSln.h"
#include <unordered_set>

bool WordBreakSln::wordBreak(string s, vector<string> &wordDict) {
    // 设置动态规划数组， dp[i]表示s的前i个字符是否可以拆分成wordDict
    vector<bool> dp(s.size() + 1, false);
    // 前0个字符什么都不匹配，所以默认为true
    dp[0] = true;
    // 将wordDict中的字符串去重
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            // 确定前j个字符和后i-j个字符在wordDict中并将dp[i]置为true
            // 然后再看后面的i-j个字符是否在wordDict中，这样可以确保s中没有字符被重叠匹配
            if (dp[j] && wordSet.find(s.substr(j, i-j)) != wordSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}