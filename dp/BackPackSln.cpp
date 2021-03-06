//
// leetcode-cpp
// 0~n种物品放进背包能拿到的最大值

#include "BackPackSln.h"

int BackPackSln::backPack(int volume, vector<int> &costs) {
    if (costs.empty()) return 0;
    int M = volume;
    int N = costs.size();
    // i是每个物件的花费，j是当前的容量
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (costs[i] > j) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - costs[i]] + costs[i]);
            }
        }
    }
    return dp[N][M];
}