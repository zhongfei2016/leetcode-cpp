//
// leetcode-cpp
// 二叉树中最大路径和，路径要是一个完整的路径，https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

#include "MaxPathSumSln.h"

int MaxPathSumSln::maxPathSum(TreeNode *root) {
    int maxVal = INT_MIN;
    dfs(root, &maxVal);
    return maxVal;
}

int MaxPathSumSln::dfs(TreeNode *curNode, int *maxVal) {
    if (curNode == nullptr) {
        return 0;
    }
    // 如果得到的值小于0，加到父节点会导致更小，所以与0取最大值，主动断尾求生
    int left = max(0, dfs(curNode->left, maxVal));
    int right = max(0, dfs(curNode->right, maxVal));
    // left + right + curNode->val是一个完整路径，可以和当前最大路径和比较并取最大值
    // 求全局最大值，即当前值加上左右分支的和
    *maxVal = max(*maxVal, left + right + curNode->val);
    // left + curNode->val或者right + curNode->val只是路径一部分，只能返回上一步继续拼凑完整路径后计算一个和
    return max(left + curNode->val, right + curNode->val);
}
