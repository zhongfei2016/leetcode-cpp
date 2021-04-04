//
// Created by ZHONGFEI on 2021/4/4.
//

#ifndef LEETCODE_CPP_PATHSUMIIISLN_H
#define LEETCODE_CPP_PATHSUMIIISLN_H
// 路径总和III 前缀和 递归 https://leetcode-cn.com/problems/path-sum-iii/

#include <tree/Common.h>

class PathSumIIISln {
public:
    int pathSum(TreeNode* root, int sum);
    int pathSum2(TreeNode* root, int sum);

private:
    int countNodeResult(TreeNode *curNode, std::unordered_map<int, int> &sumCountMap, int srcSum, int target);
    int dfs(TreeNode *root, int target);
    int countPath(TreeNode *root, int num);
    };


#endif //LEETCODE_CPP_PATHSUMIIISLN_H
