//
// leetcode-cpp
//

#include "MinTimesCostSln.h"

#include <climits>

int MinTimesCostSln::minTimesCost(vector<int> items, int cost) {
    vector<int> dp(cost + 1, 0);
    for (int c = 1; c <= cost; c++) {
        int times = INT_MAX;
        for (int i = 0; i < items.size(); i++) {
            if (c - items[i] >= 0) {
                times = min(times, dp[c - items[i]] + 1);
            }
        }
        dp[c] = times;
    }
    return dp[cost];
}