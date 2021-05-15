//
// leetcode-cpp
//

#ifndef LEETCODE_CPP_COMMON_H
#define LEETCODE_CPP_COMMON_H

#include <clocale>
#include <vector>
#include <string>
#include <queue>

using namespace std;

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

class StrNode {
public:
    string val;
    std::vector<StrNode *> children;

    StrNode() {}

    StrNode(string _val) {
        val = _val;
    }

    StrNode(string _val, std::vector<StrNode *> _children) {
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


TreeNode *convertToTreeNode(vector<int> nodes);

#endif //LEETCODE_CPP_COMMON_H
