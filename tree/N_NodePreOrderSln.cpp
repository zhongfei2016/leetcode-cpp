//
// leetcode-cpp
//

#include <stack>
#include "N_NodePreOrderSln.h"

void N_NodePreOrderSln::dfs(class Node * root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    result.push_back(root->val);
    for (auto& child : root->children) {
        dfs(child, result);
    }
}

vector<int> N_NodePreOrderSln::preorder2(class Node * root) {
    if (root == nullptr) {
        return {};
    }
    vector<int> result;
    dfs(root, result);
    return result;
}

// 栈实现
vector<int> N_NodePreOrderSln::preorder(class Node *root) {
    stack<Node> stk;
    if (root == nullptr) return {};
    stk.push(*root);
    vector<int> results;
    while (!stk.empty()) {
        auto cur = stk.top();
        stk.pop();
        results.push_back(cur.val);
        for (int i = cur.children.size() - 1; i >= 0; i--) {
            stk.push(*cur.children[i]);
        }
    }
    return results;
}