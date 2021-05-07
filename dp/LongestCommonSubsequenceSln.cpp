//
// leetcode-cpp
//

#include "LongestCommonSubsequenceSln.h"

#include <vector>

using namespace std;

int LongestCommonSubsequenceSln::longestCommonSubsequence(string text1, string text2) {
    if (text1.empty() || text2.empty()) {
        return 0;
    }
    int len1 = text1.size();
    int len2 = text2.size();
    // dp表示text1的前i个字符和text2的前j个字符最长公共子序列的长度
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];
}