//
// Created by ZHONGFEI on 2021/4/4.
//https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

#include "SortArrayToBSTSln.h"

// BST是二叉搜索树，即每个节点的左子节点值比其小，右子节点值比其大
// 当前数组已排序，而且左右高度差不能大于1，所以使用二分法每次取中间作为根
TreeNode *SortArrayToBSTSln::sortedArrayToBST(vector<int> &nums) {
    auto *root = BuildBST(nums, 0, nums.size() - 1);
    return root;
}

TreeNode *SortArrayToBSTSln::BuildBST(vector<int> &nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int mid = left + (right - left) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = BuildBST(nums, left, mid-1);
    node->right = BuildBST(nums, mid + 1, right);
    return node;
}
