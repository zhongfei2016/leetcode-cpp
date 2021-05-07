//
// leetcode-cpp
// 路径总和 根节点到叶子结点之和正好等于targetNumhttps://leetcode-cn.com/problems/path-sum/
//

#ifndef LEETCODE_CPP_HASPATHSUMSLN_H
#define LEETCODE_CPP_HASPATHSUMSLN_H


#include "Common.h"

class HasPathSumSln {
public:
    bool hasPathSum(TreeNode* root, int targetSum);

private:
    bool dfs(TreeNode* node, int targetNum);
};


#endif //LEETCODE_CPP_HASPATHSUMSLN_H
