//
// Created by ZHONGFEI on 2020/10/18.
//

#include "MinCostSln.h"

int MinCostSln::minCost(std::string s, vector<int> &cost) {
    int num = cost.size();
    int costRes = 0;
    for (int i = 0; i < num - 1; i++) {
        if (s[i] == s[i + 1]) {
            costRes += max(cost[i], cost[i + 1]);
            if (cost[i] > cost[i + 1]) {
                swap(cost[i], cost[i + 1]);
            }
        }
    }
    return costRes;
}