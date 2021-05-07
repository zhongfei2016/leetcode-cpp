//
// leetcode-cpp
//

#include "InorderTraversalSolution.h"

void recursive(vector<int> &res, TreeNode *root) {
    if (root != nullptr) {
        if (root->left != nullptr) {
            recursive(res, root->left);
        }
        res.push_back(root->val);
        if(root->right != nullptr){
            recursive(res, root->right);
        }
    }
}

vector<int> InorderTraversalSolution::inorderTraversal(TreeNode *root) {
    vector<int> res;
    recursive(res, root);
    return res;
}