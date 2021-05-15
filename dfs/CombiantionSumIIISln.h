//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_COMBIANTIONSUMIIISLN_H
#define LEETCODE_CPP_COMBIANTIONSUMIIISLN_H

#include <vector>

using namespace std;

class CombiantionSumIIISln {
public:
    vector<vector<int>> combinationSum3(int k, int n);

    void dfs(vector<vector<int>>& results, vector<int>& result, int target, int k, int startPos);
};


#endif //LEETCODE_CPP_COMBIANTIONSUMIIISLN_H
