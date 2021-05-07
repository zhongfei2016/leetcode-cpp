//
// leetcode-cpp
// https://leetcode-cn.com/problems/longest-increasing-subsequence/
//

#include "LongestIncreaseSequenceSln.h"

int LongestIncreaseSequenceSln::longestIncreaseSequence(vector<int> nums) {
    // 到第n个值得最长子序列长度，求里面的最大值即可
    vector<int> dp(nums.size()+1, 1);

    // 求每个dp值
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}