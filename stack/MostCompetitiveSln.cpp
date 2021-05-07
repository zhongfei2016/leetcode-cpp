//
// leetcode-cpp
// 更具竞争力子序列 https://leetcode-cn.com/problems/find-the-most-competitive-subsequence/
//在子序列 a 和子序列 b 第一个具有不同值的位置上，如果 a 中的数字小于 b 中对应的数字
// 那么我们称子序列 a 比子序列 b（相同长度下）更具 竞争力

#include "MostCompetitiveSln.h"

#include <stack>

vector<int> MostCompetitiveSln::mostCompetitive(vector<int> &nums, int k) {
    stack<int> numStack;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        while (!numStack.empty() && numStack.top() > nums[i] &&
               ((n - (i + 1)) >= k - static_cast<int>(numStack.size()))) {
            numStack.pop();
        }
        if (numStack.size() < k) {
            numStack.push(nums[i]);
        }
    }
    vector<int> res(k, 0);
    while (k > 0) {
        res[--k] = numStack.top();
        numStack.pop();
    }
    return res;
}