//
// Created by ZHONGFEI on 2020/2/2.
//

#include <climits>
#include "ValidBSTSolution.h"

bool validBST(TreeNode *root, long long low, long long high) {
    long long tempLow = low;
    long long tempHigh = high;
    if (root != nullptr) {
        bool left = true;
        bool right = true;
        if (root->left != nullptr) {
            //左子树非null，必须左子树值小于其根节点的值
            if (root->left->val >= root->val) {
                return false;
            }
            // 并且左子树值在上下界之间，相等也不行
            if (root->left->val <= low || root->left->val >= high) {
                return false;
            }
            // 而且由于是左子树，其后他的上界要受限制，也就是说它可以无限小，但不能无限大，再大不能大于其根节点的值
            if (root->val < high) {
                tempHigh = root->val;
            }
            left = validBST(root->left, low, tempHigh);
        }
        if (root->right != nullptr) {
            //右子树非null，必须右子树值大于其根节点的值
            if (root->right->val <= root->val) {
                return false;
            }
            // 并且右子树值在上下界之间，相等也不行
            if (root->right->val <= low || root->right->val >= high) {
                return false;
            }
            // 而且由于是右子树，其后他的下界要受限制，也就是说它可以无限大，但不能无限小，再小不能小于其根节点的值
            if (root->val > low) {
                tempLow = root->val;
            }
            right = validBST(root->right, tempLow, high);
        }
        // 每次取左右子树的并集
        return left & right;
    }
    // 根是null直接返回true
    return true;
}

bool ValidBSTSolution::isValidBST(TreeNode *root) {
    // TreeNode中是int值，要找一个一定小于其最小值和大于其最大值的数作为初始的上下界限
    long long low = LONG_LONG_MIN;
    long long high = LONG_LONG_MAX;
    if (root == nullptr) {
        return true;
    }
    return validBST(root, low, high);
}