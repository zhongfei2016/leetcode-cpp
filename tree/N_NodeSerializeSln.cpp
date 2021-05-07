//
// leetcode-cpp
// 力扣428 N叉树的序列化和反序列化 https://www.cnblogs.com/xym4869/p/12856123.html
//

#include <sstream>
#include <stack>
#include <iostream>
#include "N_NodeSerializeSln.h"

// 生成形如1(3(5 6) 2 4)的字符串
string N_NodeSerializeSln::serialize(Node *root) {
    string result;
    dfs(root, result);
    result.pop_back();
    std::cout << "serialize result: " << result << std::endl;
    return result;
}

int getNum(string data) {
    stringstream ss(data);
    double num;
    ss >> num;
    return static_cast<int>(num);
}

Node *N_NodeSerializeSln::deserialize(string data) {
    Node *root = nullptr;
    Node *curNode = nullptr;
    stack<Node *> stk;
    string strVal;
    for (auto& ch : data) {
        switch (ch) {
            case '(':
                if (!strVal.empty()) {
                    curNode = new Node(std::stoi(strVal));
                    strVal.clear();
                }
                if (root == nullptr) {
                    root = curNode;
                }
                stk.push(curNode);
                break;
            case ')': {
                if (!strVal.empty()) {
                    curNode = new Node(std::stoi(strVal));
                    strVal.clear();
                    stk.top()->children.push_back(curNode);
                }
                auto *sonNode = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    stk.top()->children.push_back(sonNode);
                }
                break;
            }
            case ' ':
                if (strVal.empty()) {
                    break;
                }
                curNode = new Node(std::stoi(strVal));
                strVal.clear();
                stk.top()->children.push_back(curNode);
                break;
            default:
                strVal += ch;
        }
    }
    return root;
}

void N_NodeSerializeSln::dfs(Node *node, string &result) {
    if (node == nullptr) {
        return;
    }
    result.append(std::to_string(node->val));
    if (node->children.empty()) {
        result.append(" ");
        return;
    }
    result.append("(");
    for (auto *child : node->children) {
        dfs(child, result);
    }
    result.pop_back();
    result.append(")").append(" ");
}
