//
// leetcode-cpp
//

#include "MaxDepthSolution.h"
#include <vector>

using namespace std;

void getMaxDepth(TreeNode *root, int level, vector<int> &sizeVec) {
    if (root == nullptr) {
        return;
    }
    if (sizeVec.size() <= level) {
        sizeVec.push_back(0);
    }
    sizeVec.at(level) += 1;
    getMaxDepth(root->left, level + 1, sizeVec);
    getMaxDepth(root->right, level + 1, sizeVec);
}

int MaxDepthSolution::maxDepth(TreeNode *root) {
    vector<int> sizeVec;
    getMaxDepth(root, 0, sizeVec);
    return sizeVec.size();
}

int MaxDepthSolution::maxDepth2(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    return max(curMaxDepth(root->left), curMaxDepth(root->right)) + 1;
}

int MaxDepthSolution::curMaxDepth(TreeNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return max(curMaxDepth(node->left), curMaxDepth(node->right)) + 1;
}