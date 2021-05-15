//
// leetcode-cpp
//
#include <Common.h>

TreeNode *convertToTreeNode(vector<int> nodes) {
    if (nodes.empty()) {
        return nullptr;
    }
    int idx = 0;
    TreeNode *root = new TreeNode(nodes[idx]);
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
        TreeNode *curNode = que.front();
        que.pop();
        if (idx < nodes.size() - 1) {
            idx++;
            if (nodes[idx] != INT_MIN) {
                curNode->left = new TreeNode(nodes[idx]);
                que.push(curNode->left);
            } else {
                curNode->left = nullptr;
            }
        }
        if (idx < nodes.size() - 1) {
            idx++;
            if (nodes[idx] != INT_MIN) {
                curNode->right = new TreeNode(nodes[idx]);
                que.push(curNode->right);
            } else {
                curNode->right = nullptr;
            }
        }
    }
    return root;
}