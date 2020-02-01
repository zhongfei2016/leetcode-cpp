//
// Created by ZHONGFEI on 2020/2/1.
//

#ifndef LEETCODE_CPP_INORDERTRAVERSALSOLUTION_H
#define LEETCODE_CPP_INORDERTRAVERSALSOLUTION_H

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class InorderTraversalSolution {
public:
    vector<int> inorderTraversal(TreeNode *root);
};


#endif //LEETCODE_CPP_INORDERTRAVERSALSOLUTION_H
