//
// Created by ZHONGFEI on 2021/3/30.
//

#ifndef LEETCODE_CPP_N_NODEPOSTORDERSLN_H
#define LEETCODE_CPP_N_NODEPOSTORDERSLN_H

#include <Common.h>
using namespace std;
class N_NodePostOrderSln {
public:
    void dfs(class Node * root, vector<int>& result);
    vector<int> postorder(Node* root);
    vector<int> postorder2(Node* root);
};


#endif //LEETCODE_CPP_N_NODEPOSTORDERSLN_H
