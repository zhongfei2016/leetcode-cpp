//
// Created by ZHONGFEI on 2020/2/2.
//

#include "SymmetricSolution.h"

bool isLeftRightSymmetric(TreeNode *left, TreeNode *right) {
    // 左右子树均为null，对称
    if (left == nullptr && right == nullptr) {
        return true;
    }
    // 左右子树一个为空一个不为空，不对称
    if (left == nullptr || right == nullptr) {
        return false;
    }

    // 左右子树值相等后，还要判断左子树的左子树和右子树的右子树是否对称
    // 以及左子树的右子树和右子树的左子树是否对称
    // 只有都满足才对称
    if (left->val == right->val) {
        return isLeftRightSymmetric(left->left, right->right) && isLeftRightSymmetric(left->right, right->left);
    }
    return false;
}

bool SymmetricSolution::isSymmetric(TreeNode *root) {
    return isLeftRightSymmetric(root, root);
}