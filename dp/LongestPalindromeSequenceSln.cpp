//
// Created by ZHONGFEI on 2020/4/5.
//

#include "LongestPalindromeSequenceSln.h"
#include <vector>

using namespace std;

int LongestPalindromeSequenceSln::longestPalindromeSubseq(string s) {
    if (s.empty())
        return 0;
    //在子串 s[i..j] 中，最长回文子序列的长度为 dp[i][j]
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    // i==j时，从i到j的回文子串就一个字母，就是1
    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
    }
    // 斜着遍历，j从1到n，i跟在后面从j到0，遍历dp矩阵里的左下三角
    /**
     * #  |     #    |    #    |    #        #
     * #  |  i=j=0   |         |
     * #  | j=1,i=0  |  i=j=1  |
     * #  | j=2,i=0  | j=2,i=1 |  i=j=2
     * #  | j=3,i=0  | j=3,i=1 | j=3,i=2  | i=j=3
     */
    for (int j = 1; j < s.size(); j++) {
        for (int i = j - 1; i >= 0; i--) {
            // 如果s[j] == s[i]，那再加上 s[i+1..j-1] 中的最长回文子序列就是 s[i..j] 的最长回文子序列
            if (s[j] == s[i]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                //不相等，说明s[i],s[j]不可能同时出现在 s[i..j] 的最长回文子序列中
                // 那么把它俩分别加入 s[i+1..j-1] 中，看看哪个子串产生的回文子序列更长
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][s.size() - 1];
}