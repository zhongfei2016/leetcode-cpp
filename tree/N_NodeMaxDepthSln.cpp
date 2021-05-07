//
// leetcode-cpp
//

#include "N_NodeMaxDepthSln.h"
// https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/

int N_NodeMaxDepthSln::maxDepth(class Node *root) {
    int maxDepth = dfs(root, 0);
    return maxDepth;
}

int N_NodeMaxDepthSln::maxDepth2(Node *root) {
    int maxDepth = dfs2(root);
    return maxDepth;
}

// 自顶而下方式计算最大深度
// 每次dfs返回本层节点的最大深度
int N_NodeMaxDepthSln::dfs(Node *node, int curDepth) {
    if (node == nullptr) {
        return curDepth;//为空则本次不计算深度
    }
    if (node->children.empty()) {
        return curDepth + 1;//无子节点则只计入当前节点并返回此时对应的深度
    }
    // 计算所有子节点对应的深度并取最大深度
    int maxDepth = curDepth + 1;
    for (auto *child : node->children) {
        maxDepth = max(maxDepth, dfs(child, curDepth + 1));
    }
    return maxDepth;
}

// 自下而上方式计算最大深度
int N_NodeMaxDepthSln::dfs2(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->children.empty()) {
        return 1;
    }
    int maxDepth = 0;
    // 先计算所有子层所能提供的最大深度
    for (auto *child : node->children) {
        maxDepth = max(maxDepth, dfs2(child));
    }
    // 最后将结果加上本层提供的深度作为结果返回
    return maxDepth + 1;
}
