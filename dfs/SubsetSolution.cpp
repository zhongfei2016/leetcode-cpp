//
// leetcode-cpp
//

#include "SubsetSolution.h"

void backtrack(int i, vector<int> &nums, vector<int> subset, vector<vector<int>> &res) {
    if (subset.size() <= nums.size()) {
        res.push_back(subset);
    }
    for (int j = i; j < nums.size(); j++) {
        subset.push_back(nums[j]);
        backtrack(j + 1, nums, subset, res);
        subset.pop_back();
    }
}

vector<vector<int>> SubsetSolution::subsets(vector<int> &nums) {
    vector<int> subset;
    vector<vector<int>> res;
    backtrack(0, nums, subset, res);
    return res;
}