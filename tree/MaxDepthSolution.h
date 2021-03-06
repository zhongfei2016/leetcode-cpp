//
// leetcode-cpp
//
//  二叉树的最大深度 https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

#ifndef LEETCODE_CPP_MAXDEPTHSOLUTION_H
#define LEETCODE_CPP_MAXDEPTHSOLUTION_H

#include "Common.h"

class MaxDepthSolution {
public:
    int maxDepth(TreeNode* root);
    int maxDepth2(TreeNode* root);

private:
    int curMaxDepth(TreeNode *node);
};


#endif //LEETCODE_CPP_MAXDEPTHSOLUTION_H
