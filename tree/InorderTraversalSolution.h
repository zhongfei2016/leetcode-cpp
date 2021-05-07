//
// leetcode-cpp
//
// 二叉树的中序遍历 https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// 前序遍历规则：根结点 ---> 左子树 ---> 右子树
// 中序遍历规则：左子树---> 根结点 ---> 右子树
// 后序遍历规则：左子树 ---> 右子树 ---> 根结点

#ifndef LEETCODE_CPP_INORDERTRAVERSALSOLUTION_H
#define LEETCODE_CPP_INORDERTRAVERSALSOLUTION_H

#include <vector>
#include "Common.h"

using namespace std;

class InorderTraversalSolution {
public:
    vector<int> inorderTraversal(TreeNode *root);
};


#endif //LEETCODE_CPP_INORDERTRAVERSALSOLUTION_H
