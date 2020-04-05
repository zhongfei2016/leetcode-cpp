//
// Created by ZHONGFEI on 2020/4/4.
//

#include "CoinChangeSln.h"

int CoinChangeSln::coinChange(vector<int> &coins, int amount) {
    if (amount < 0) {
        return -1;
    }
    if (amount == 0) {
        return 0;
    }
    // 初始化dp表，表示用给定的coins面额种类拼出给定总金额amount所需的最少硬币数
    // dp表的idx是从0到amount的每一个金额数，所以其size为amount+1
    // 每一个初始值要给一个所需硬币数的最大值，就是用硬币面额都是1拼出给定金额再加1，所有情况都不可能比这个大
    vector<int> dp(amount + 1, amount + 1);
    // 拼出0这个总金额需要0个硬币，这是初始值
    dp[0] = 0;
    // 然后进入循环，计算拼出childAmount这个总金额所需最小硬币数，childAmount属于[1,amount]
    for (int childAmount = 1; childAmount <= amount; childAmount++) {
        for (int coinIdx = 0; coinIdx < coins.size(); coinIdx++) {
            if (coins[coinIdx] > childAmount)
                continue;
            // 将childAmount减掉当前的coin值作为idx从dp表中取出其所需的最少硬币数，再加上当前coin这个
            dp[childAmount] = min(dp[childAmount], dp[childAmount - coins[coinIdx]] + 1);
        }
    }
    if (dp[amount] > amount) {
        return -1;
    }
    return dp[amount];
}