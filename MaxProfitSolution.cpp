//
// Created by ZHONGFEI on 2020/3/8.
//

#include "MaxProfitSolution.h"

int MaxProfitSolution::maxProfit(vector<int>& prices)
{
    int maxProfit = 0;
    if (prices.empty() || prices.size() < 2) {
        return maxProfit;
    }
    // 动态规划
    // 记录包括今天在内的最小买入值，并计算包括今天在内的最大收益
    int minIn = prices[0];
    for (int i=0;i<prices.size();i++) {
        minIn = min(minIn, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minIn);
    }
    return maxProfit;
}