//
// leetcode-cpp
//

#include "CoinChangeIISln.h"

int CoinChangeIISln::change(int amount, vector<int> &coins) {
    // dp表的idx是要凑的金额，值是凑出idx金额的组合个数
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    // 每个coin使用的个数不限制，但coin顺序循环，保证不会有顺序问题，即用过的coin不再使用
    for (auto coin : coins) {
        for (int i = 1; i <= amount; i++) {
            if (i < coin) {
                continue;
            }
            // 第一次dp[i]是0，循环加上dp[i-coin]就得到了dp[i]的值
            dp[i] = dp[i] + dp[i - coin];
        }
    }
    return dp[amount];
}