//
// leetcode-cpp
// https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/ N叉树前序遍历
// N叉树的遍历 https://www.cnblogs.com/vincent1997/p/11194100.html
//

#ifndef LEETCODE_CPP_N_NODEPREORDERSLN_H
#define LEETCODE_CPP_N_NODEPREORDERSLN_H

#include <Common.h>

using namespace std;

class N_NodePreOrderSln {
public:
    void dfs(class Node * root, vector<int>& result);
    vector<int> preorder(Node* root);
    vector<int> preorder2(Node* root);
};


#endif //LEETCODE_CPP_N_NODEPREORDERSLN_H
