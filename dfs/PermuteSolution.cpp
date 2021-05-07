//
// leetcode-cpp
//

#include "PermuteSolution.h"
#include <algorithm>

void backtrack(vector<int> &nums, vector<int> &trace, vector<vector<int>> &traces) {
    if (trace.size() == nums.size()) {
        traces.push_back(trace);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (find(trace.begin(), trace.end(), nums[i]) != trace.end()) {
            continue;
        }
        // 每次只管一层的数字的遍历，放进去一个数之后递归调用backtrack方法继续往深层遍历
        // 直到满足条件后往上层走，退出backtrack就pop掉刚放进去的数字，因为肯定里层的backtrack满足条件才会return
        // 所以要pop掉之前放进去的数字，再在本层放下一个数
        trace.push_back(nums[i]);
        backtrack(nums, trace, traces);
        trace.pop_back();
    }
}

vector<vector<int>> PermuteSolution::permute(vector<int> &nums) {
    vector<vector<int>> traces;
    vector<int> trace;
    backtrack(nums, trace, traces);
    return traces;
}