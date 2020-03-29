//
// Created by ZHONGFEI on 2020/3/29.
//

#include "PermuteSolutionII.h"

#include <algorithm>

void dfs(vector<int> &nums, vector<int> &list, vector<bool> &visited, vector<vector<int>> &results) {
    if (list.size() == nums.size()) {
        results.push_back(list);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (visited[i] || (i>0 && nums[i]==nums[i-1] && !visited[i-1])) {
            continue;
        }
        visited[i] = true;
        list.push_back(nums[i]);
        dfs(nums, list, visited, results);
        visited[i] = false;
        list.pop_back();
    }
}

vector<vector<int>> PermuteSolutionII::permuteUnique(vector<int> &nums) {
    vector<vector<int>> results;
    if (nums.empty()) {
        results.push_back(nums);
        return results;
    }
    vector<int> list;
    std::sort(nums.begin(), nums.end());
    vector<bool> visited(nums.size(), false);
    dfs(nums, list, visited, results);
    return results;
}