//
// Created by ZHONGFEI on 2020/10/18.
// 避免重复字母的最小删除成本 https://leetcode-cn.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
// s = "abaac", cost = [1,2,3,4,5]

#include "MinCostSln.h"

int MinCostSln::minCost(std::string s, vector<int> &cost) {
    int num = cost.size();
    int costRes = 0;
    for (int i = 0; i < num - 1; i++) {
        // 遇到相同字符，就取最小花费
        if (s[i] == s[i + 1]) {
            costRes += min(cost[i], cost[i + 1]);
            // 如果i的花费比i+1小，那自然取的是i的花费，后面i++后原i也已经被用掉了
            // 原i+1变成i了，可以再判断下一轮i和i+1的花费了
            // 只有i花费大于i+1时，上面用掉了小的，要把大的换到下一轮的i上才能继续用，所以交换一下
            if (cost[i] > cost[i + 1]) {
                swap(cost[i], cost[i + 1]);
            }
        }
    }
    return costRes;
}

int MinCostSln::minCost2(string s, vector<int> &cost) {
    const int M = s.size();
    int costSum = 0;
    if (M <= 1)
        return 0;

    int i = 0, j = 1;
    while (j < M) {
        if (s[i] == s[j]) {
            // i的cost小，则用掉了i的值，从j重新开始
            if (cost[i] < cost[j]) {
                costSum += cost[i];
                i = j;
                ++j;
            } else {
                // 否则i不变，j++继续往后看
                costSum += cost[j];
                ++j;
            }
        } else {
            // 遇到不等，则i从j开始，相当于新的开始
            i = j;
            ++j;
        }
    }

    return costSum;
}