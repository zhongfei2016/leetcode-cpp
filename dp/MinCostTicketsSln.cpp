//
// Created by ZHONGFEI on 2020/4/4.
//

#include <climits>
#include <map>
#include "MinCostTicketsSln.h"

int minVal(int a, int b, int c) {
    int min = a < b ? a : b;
    return min < c ? min : c;
}

int getDpVal(vector<int> &dp, int idx) {
    if (idx < 0) {
        return 0;
    }
    return dp[idx];
}

int MinCostTicketsSln::mincostTickets(vector<int> &days, vector<int> &costs) {
    // dp用于存放到dpIdx这一天的最小消费
    // dp大小初始化如果只取到days[days.size() - 1]，就是days数组最后一个数的大小，比如最后一个是30
    // 那dp数组的取值范围只能是0,29，就算不出到30这一天的消费总额了
    vector<int> dp(days[days.size() - 1] + 1, 0);
    vector<bool> travel(days[days.size() - 1] + 1, false);
    dp[0] = 0;
    // 出行的那天置为true
    for (auto day : days) {
        travel[day] = true;
    }
    for (int i = 1; i < dp.size(); i++) {
        // 为出行的那天消费肯定都是0
        if (!travel[i]) {
            dp[i] = dp[i - 1];
            continue;
        }
        // 第i天的前1/7/30天的最小消费值，加上为期1/7/30天的通行证售价，就是第i天所需消费值的三种情况，取最小值即可
        // 如果第i-1/i-7/i-30小于0，说明买1/7/30天的通行证就足够i天通行需求了，所以getDpVal直接返回0，取costs为1/7/30时的最小值即可
        dp[i] = minVal(getDpVal(dp, i - 1) + costs[0],
                       getDpVal(dp, i - 7) + costs[1],
                       getDpVal(dp, i - 30) + costs[2]);
    }
    return dp[days.back()];
}