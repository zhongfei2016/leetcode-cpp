//
// leetcode-cpp
//

#include <queue>
#include "N_NodeLevelOrderSln.h"

vector<vector<int> > N_NodeLevelOrderSln::levelOrder(class Node *root) {
    if (root == nullptr) {
        return {};
    }
    vector<vector<int>> results;
    std::queue<Node *> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> result;
        for (int i = 0; i < size; i++) {
            Node *node = que.front();
            que.pop();
            result.push_back(node->val);
            for (int i = 0; i < node->children.size(); i++) {
                que.push(node->children[i]);
            }
        }
        results.push_back(result);
    }
    return results;
}