//
// leetcode-cpp
//

#include "FindTargetSumSln.h"
#include <climits>

int dfs(vector<int> &nums, int idx, int sum, int target, vector<vector<int>> &memo) {
    if (idx == nums.size() && (target == sum)) {
        return 1;
    }
    if (idx == nums.size()) {
        return 0;
    }
    if (memo[sum + 1000][idx] == INT_MIN) {
        memo[sum + 1000][idx] = dfs(nums, idx + 1, sum - nums[idx], target, memo);
        memo[sum + 1000][idx] += dfs(nums, idx + 1, sum + nums[idx], target, memo);
    }
    return memo[sum + 1000][idx];
}

int FindTargetSumSln::findTargetSumWays(vector<int> &nums, int S) {
    // dfs 会超时, 加记忆化后可通过
    int ans = 0;
    // 因为数组和不会超过1000，又有+、—两种操作，所以取2000用于记忆化暂存每个和对应的组合方法个数
    vector<vector<int>> memo(2000, vector<int>(nums.size(), INT_MIN));
    ans += dfs(nums, 0, 0, S, memo);
    return ans;
}