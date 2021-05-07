//
// leetcode-cpp
//

#include "MaxSameStrSln.h"

#include <vector>

int MaxSameStrSln::maxSameStr(std::string str1, std::string str2) {
    vector<vector<int>> dp(1001, vector<int>(1001, 0));
    int res = 0;
    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
        }
    }
    return res;
}
