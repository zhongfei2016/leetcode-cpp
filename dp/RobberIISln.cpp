//
// leetcode-cpp
// 打家劫舍II 几户人家围起来，相邻的不能偷，https://leetcode-cn.com/problems/house-robber-ii/
//

#include "RobberIISln.h"

int singleRob(vector<int> &nums) {
    vector<int> dp(nums.size() + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[nums.size()];
}

int RobberIISln::rob(vector<int> &nums) {
    int cnt = nums.size();
    if (cnt < 2) {
        return nums[0];
    }
    vector<int> nums1(nums.begin(), nums.end() - 1);
    vector<int> nums2(nums.begin() + 1, nums.end());

    int res1 = singleRob(nums1);
    int res2 = singleRob(nums2);
    int res = max(res1, res2);
    return res;
}