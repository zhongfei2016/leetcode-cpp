//
// leetcode-cpp
//

#include "CombiantionSumIIISln.h"

vector<vector<int>> CombiantionSumIIISln::combinationSum3(int k, int n) {
    vector<vector<int>> results;
    vector<int> result;
    dfs(results, result, n, k, 1);
    return results;
}

/**
 *
 * @param results 最终结果集
 * @param result 单个结果集
 * @param target 本轮递归的目标值，必须是>=0才能算数
 * @param k 单个结果集的有效个数
 * @param startPos 本轮起始的增量（1——9为有效值，可以计算
 * 10就是结束值了，如果是10，就只看本轮是否满足result.size() == k && target == 0，否则直接返回
 */
void CombiantionSumIIISln::dfs(vector<vector<int>> &results, vector<int> &result, int target, int k, int startPos) {
    if (result.size() > k || target < 0 || startPos > 10) {
        return;
    }
    if (result.size() == k && target == 0) {
        results.push_back(result);
        return;
    }

    for (int i = startPos; i <= 9; i++) {
        result.push_back(i);
        dfs(results, result, target - i, k, i + 1);
        result.pop_back();
    }
}