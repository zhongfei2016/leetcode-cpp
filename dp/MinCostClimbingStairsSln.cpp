//
// leetcode-cpp
// 使用最小花费爬楼梯 https://leetcode-cn.com/problems/min-cost-climbing-stairs/
//
// 到达第i级台阶的阶梯顶部的最小花费，有两个选择：
//最后踏上了第i级台阶，最小花费dp[i]，再迈一步到达第i级台阶楼层顶部；
//最后踏上了第i-1级台阶，最小花费dp[i-1]，再迈两步跨过第i级台阶直接到达第i级台阶的阶梯顶部。


#include "MinCostClimbingStairsSln.h"

int MinCostClimbingStairsSln::minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size());
    dp[0] = cost[0];//跨到第0级顶部只有一种选择
    dp[1] = cost[1];//跨到第1级顶部有两种选择，cost[0]+cost[1]或者cost[1](跨过cost[0]直接到cost[1])
    for (int i = 2; i < cost.size(); i++) {
        // 算出到第i级的最少花费，dp[i]表示跳到i级台阶的顶部的最小花费
        dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
    }
    return min(dp[cost.size() - 2], dp[cost.size() - 1]);
}
