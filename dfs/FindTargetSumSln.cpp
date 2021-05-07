//
// leetcode-cpp
//

#include "FindTargetSumSln.h"

int dfs(vector<int> &nums, int idx, int target) {
    int ans = 0;
    if (idx == nums.size() && (target == 0)) {
        return 1;
    }
    if (idx == nums.size()) {
        return 0;
    }
    ans += dfs(nums, idx + 1, target - nums[idx]);
    ans += dfs(nums, idx + 1, target + nums[idx]);
    return ans;
}

int FindTargetSumSln::findTargetSumWays(vector<int> &nums, int S) {
    // dfs 会超时
    int ans = 0;
    ans += dfs(nums, 0, S);
    return ans;
}