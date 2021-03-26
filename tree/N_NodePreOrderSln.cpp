//
// Created by ZHONGFEI on 2021/3/26.
//

#include <stack>
#include "N_NodePreOrderSln.h"

vector<int> N_NodePreOrderSln::preorder(class Node *root) {
    stack<Node> stk;
    stk.push(*root);
    vector<int> results;
    while (!stk.empty()) {
        auto cur = stk.top();
        results.push_back(cur.val);
        for (int i = cur.children.size() - 1; i >= 0; i--) {
            stk.push(*cur.children[i]);
        }
        stk.pop();
    }
    return results;
}