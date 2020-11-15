//
// Created by ZHONGFEI on 2020/11/15.
//

#include "CombinationSumIISln.h"

#include <algorithm>

void combinationSum2Dfs(vector<int> &candidates, vector<vector<int>> &res, vector<int> &path, int startPos, int target,
                        vector<bool> &visited) {
    if (startPos > candidates.size()) {
        return;
    }
    if (target == 0) {
        res.push_back(path);
        return;
    }
    for (int i = startPos; i < candidates.size() && target - candidates[i] >= 0; i++) {
        if (visited[i]) {
            continue;
        }
        // 当前值和前一个值相同，如果这两个值放在同一层遍历里，不能重复使用，visited[i - 1]==false表示前一个值已经用完并弹出了，所以表示当前值和前一个值同级，直接continue，如果是true，表示当前值在前一个值下一层，可以用
        if (i > 0 && candidates[i - 1] == candidates[i] && !visited[i - 1]) {
            continue;
        }
        visited[i] = true;
        path.push_back(candidates[i]);
        combinationSum2Dfs(candidates, res, path, i + 1, target - candidates[i], visited);
        path.pop_back();
        visited[i] = false;
    }
}

vector<vector<int> > CombinationSumIISln::combinationSum2(vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visited(candidates.size(), false);
    combinationSum2Dfs(candidates, res, path, 0, target, visited);
    return res;
}