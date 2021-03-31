//
// Created by ZHONGFEI on 2021/3/30.
// https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/solution/che-di-chi-tou-shu-de-qian-zhong-hou-xu-di-gui-fa-/
//

#include <stack>
#include <algorithm>
#include "N_NodePostOrderSln.h"

void N_NodePostOrderSln::dfs(Node *root, vector<int> &results) {
    if (root == nullptr) {
        return;
    }
    for (auto &child: root->children) {
        dfs(child, results);
    }
    results.push_back(root->val);
}

vector<int> N_NodePostOrderSln::postorder(Node *root) {
    vector<int> results;
    dfs(root, results);
    return results;
}

vector<int> N_NodePostOrderSln::postorder2(class Node *root) {
    if (root == nullptr) {
        return {};
    }
    std::stack<Node *> stk;
    stk.push(root);
    vector<int> results;
    while (!stk.empty()) {
        auto* item = stk.top();
        results.push_back(item->val);
        stk.pop();
        // 前序遍历是中左右，颠倒一下前序遍历的左右变成中右左，然后再整个翻转，就是左右中，就是后序遍历
        for (auto *child : item->children) {
            stk.push(child);
        }
    }
    std::reverse(results.begin(), results.end());
    return results;
}