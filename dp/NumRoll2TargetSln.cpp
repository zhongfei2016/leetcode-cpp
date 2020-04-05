//
// Created by ZHONGFEI on 2020/4/4.
//

#include "NumRoll2TargetSln.h"

#include <vector>

using namespace std;

int numRollsToTarget(int d, int f, int target) {
    if (target < d || d * f < target) {
        return 0;
    }
    // dp含义是d个筛子每个筛子朝上的值的和等于target值的排列数
    int dpM = d + 1;
    int dpN = target + 1;
    vector<vector<int>> dp(dpM, vector<int>(dpN));
    dp[0][0]=1;
    int mod = 1000000007;
    //每一轮表示，如果有childNum个筛子，每个筛子的取值范围[1,f]
    // childNum个筛子面朝上的值的和等于childTarget的排列数
    for (int childNum = 1; childNum <= d; childNum++) {
        // 子目标值childTarget从筛子数开始，因为每个筛子值至少为1，所以筛子数childNum*1=childNum
        // 且childTarget要小于目标值target和筛子数*每个筛子最大值f
        for (int childTarget = childNum; childTarget <= target && childTarget <= childNum * f; childTarget++) {
            for (int i = 1; i <= f && childTarget - i>=0; i++) {
                dp[childNum][childTarget] =
                        (dp[childNum][childTarget] + dp[childNum - 1][childTarget - i]) % mod;
            }
        }
    }
    return dp[d][target];
}