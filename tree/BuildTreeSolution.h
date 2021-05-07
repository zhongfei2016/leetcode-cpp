//
// leetcode-cpp
//
// 从前序与中序遍历序列构造二叉树 https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#ifndef LEETCODE_CPP_BUILDTREESOLUTION_H
#define LEETCODE_CPP_BUILDTREESOLUTION_H

#include <vector>
#include "Common.h"
using namespace std;
class BuildTreeSolution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
};


#endif //LEETCODE_CPP_BUILDTREESOLUTION_H
