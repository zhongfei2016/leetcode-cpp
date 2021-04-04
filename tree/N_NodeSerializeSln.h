//
// Created by ZHONGFEI on 2021/4/3.
//

#ifndef LEETCODE_CPP_N_NODESERIALIZESLN_H
#define LEETCODE_CPP_N_NODESERIALIZESLN_H


#include "Common.h"

class N_NodeSerializeSln {
public:
    string serialize(Node *root);

    Node *deserialize(string data);

private:
    void dfs(Node* node, string& result);
};


#endif //LEETCODE_CPP_N_NODESERIALIZESLN_H
