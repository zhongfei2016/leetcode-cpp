//
// leetcode-cpp
// 路径总和 根节点到叶子结点之和正好等于targetNumhttps://leetcode-cn.com/problems/path-sum/
//

#include "HasPathSumSln.h"

bool HasPathSumSln::hasPathSum(TreeNode *root, int targetSum) {
    bool result = dfs(root, targetSum);
    return result;
}

bool HasPathSumSln::dfs(TreeNode *node, int targetNum) {
    if (node == nullptr) {
        return false;
    }
    if (node->val == targetNum && node->left == nullptr && node->right == nullptr) {
        return true;
    }
    return dfs(node->left, targetNum - node->val) ||
           dfs(node->right, targetNum - node->val);
}
