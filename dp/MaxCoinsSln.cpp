//
// 戳气球，求能得到的最大积分值
// https://leetcode-cn.com/problems/burst-balloons/solution/zhe-ge-cai-pu-zi-ji-zai-jia-ye-neng-zuo-guan-jian-/
// https://qoogle.top/leetcode-312-burst-balloons/（重点参考）

#include "MaxCoinsSln.h"

// dfs实现
int MaxCoinsSln::maxCoins1(vector<int> &nums) {
    int ans = 0;
    dfs1(nums, 0, &ans);
    return ans;
}

/**
 *
 * @param nums 当前数组可用的值组成的数组
 * @param curCoins 当前的最大coin和
 * @param ans 结果值
 */
void MaxCoinsSln::dfs1(vector<int> &nums, int curCoins, int *ans) {
    if (nums.size() == 0) {
        // nums遍历完，找出当前的coins的和和当前的ans，取大值
        // 第一次到nums清空时，ans还是0，所以自然取curCoins的值，再后面的遍历就不一定了
        *ans = max(curCoins, *ans);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        // 暂存，本轮深度遍历结束后再插进去
        int temp = nums[i];
        int delta = nums[i] * (i > 0 ? nums[i - 1] : 1) * (i < nums.size() - 1 ? nums[i + 1] : 1);
        nums.erase(nums.begin() + i);
        dfs1(nums, curCoins + delta, ans);
        nums.insert(nums.begin() + i, temp);
    }
}

// dfs记忆化实现(dp)
int MaxCoinsSln::maxCoins2(vector<int> &nums) {
    vector<int> temp(nums.begin(), nums.end());
    temp.insert(temp.begin(), 1);
    temp.push_back(1);
    int n = nums.size();
    // 前后各追加1，就不用考虑边界问题了，遇到原边界可以直接乘
    vector<vector<int>> dp(temp.size(), vector<int>(temp.size(), 0));
    int ans = dfs2(temp, dp, 1, n);
    return ans;
}

int MaxCoinsSln::dfs2(vector<int> &nums, vector<vector<int>> &dp, int i, int j) {
    if (i > j) {
        return 0;
    }
    // 如果已经算过，不再重复计算
    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    for (int k = i; k <= j; k++) {
        // 先算k的左半部分，即i~k-1，算到底
        int left = dfs2(nums, dp, i, k - 1);
        // 再算k的右半部分，即k+1~j，算到底
        int right = dfs2(nums, dp, k + 1, j);
        // k的左右部分都算完之后，即左右都炸完了，此时只剩下i-1，k和j+1了，将其乘起来
        // 加上左右部分的最大值，即为当分界值为k时的当前能得到的最大值，即left + right + delta
        // 然后再循环下一个可能的k，在计算一次最大值，循环完，就得到了从i~j炸完的最大值
        int delta = nums[k] * nums[i - 1] * nums[j + 1];
        dp[i][j] = max(dp[i][j], left + right + delta);
    }
    return dp[i][j];
}

// dp
int MaxCoinsSln::maxCoins3(vector<int> &nums) {
    vector<int> temp(nums.begin(), nums.end());
    temp.insert(temp.begin(), 1);
    temp.push_back(1);
    vector<vector<int>> dp(temp.size(), vector<int>(temp.size(), 0));
    int n = nums.size();
    // len长度是由1到n的，目的是将1~n对应的最大值都计算出来
    for (int len = 1; len <= n; len++) {
        // i是左边界，当前数组temp是nums左右各塞了1，所以左边界要从1开始，到n结束
        // 左边界最大值是n，此时len是1，如果len是n，左边界就只能是1了
        for (int i = 1; i <= n + 1 - len; i++) {
            // j是右边界
            int j = i + len - 1;
            for (int k = i; k <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + temp[k] * temp[i - 1] * temp[j + 1]);
            }
        }
    }
    return dp[1][n];
}
