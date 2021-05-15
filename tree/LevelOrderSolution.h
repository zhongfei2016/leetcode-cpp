//
// leetcode-cpp
//
// 二叉树层次遍历 https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

#ifndef LEETCODE_CPP_LEVELORDERSOLUTION_H
#define LEETCODE_CPP_LEVELORDERSOLUTION_H

#include "Common.h"
#include <vector>

using namespace std;

class LevelOrderSolution {
public:
    vector<vector<int>> levelOrder(TreeNode* root);
    vector<vector<int>> levelOrder2(TreeNode* root);
};


#endif //LEETCODE_CPP_LEVELORDERSOLUTION_H
