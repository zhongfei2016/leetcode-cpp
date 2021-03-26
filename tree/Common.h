//
// Created by ZHONGFEI on 2020/2/2.
//

#ifndef LEETCODE_CPP_COMMON_H
#define LEETCODE_CPP_COMMON_H

#include <clocale>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //LEETCODE_CPP_COMMON_H
