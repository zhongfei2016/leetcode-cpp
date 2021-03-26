//
// Created by ZHONGFEI on 2021/3/24.
// 打家劫舍III https://leetcode-cn.com/problems/house-robber-iii/
//

#include <algorithm>
#include "RobberSlnIII.h"

int RobberSlnIII::rob(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int res = root->val;
    if (root->left != nullptr) {
        res += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right != nullptr) {
        res += rob(root->right->left) + rob(root->right->right);
    }
    int sonRes = rob(root->left) + rob(root->right);
    return std::max(res, sonRes);
}
