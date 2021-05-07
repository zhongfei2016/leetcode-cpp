//
// leetcode-cpp
//

#include "RobberSln.h"

// 打家劫舍 https://leetcode-cn.com/problems/house-robber/
int RobberSln::rob(vector<int> &nums) {
    if (nums.empty())return 0;
    if (nums.size() == 1)
        return nums[0];
    // dp[n]代表第n间房偷完的最大偷窃额，n为1,2,3...n，所以dp长度为n+1
    vector<int> dp(nums.size() + 1, 0);
    //第0间房偷完表示没偷，所以偷窃额为0，第一间房偷完偷窃额就是第一间房里的钱nums[0]
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= nums.size(); i++) {
        // 第i间房偷完，为了避免触发警报，要么不拿第i间房的钱，那得到的钱和偷完i-1间房时得到的钱一样
        // 要么拿当前房间i的钱nums[i-1]，再加上拿完i-2间房得到的钱，就是此种情况得到的钱
        // 两者取最大即为偷完i间房得到的最大偷窃额
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[nums.size()];
}