//
// leetcode-cpp
//

#include "MaxSubArraySolution.h"
#include <climits>

int maxFun(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// -2,1,-3,4,-1,2,1,-5,4
int MaxSubArraySolution::maxSubArray(vector<int> &nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    // 获取最大值子序的集合
    vector<int> temp;
    vector<int> ans;
    int max = nums[0];
    int sum = 0;
    for (int num : nums) {
        if (sum > 0) {
            sum += num;
            temp.push_back(num);
        } else {
            sum = num;
            temp.clear();
            temp.push_back(num);
        }
        if (sum > max) {
            ans.clear();
            ans.assign(temp.begin(), temp.end());
        }
        max = maxFun(max, sum);
    }
    return max;
}

int MaxSubArraySolution::maxSubArrayDP(vector<int> &nums) {
    int sum = INT_MIN;
    // 动态规划，dp用于存前一个最大值和当前值的和与当前值中的最大值
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    sum = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = maxFun(dp[i - 1] + nums[i], nums[i]);
        sum = maxFun(sum, dp[i]);
    }
    return sum;
}