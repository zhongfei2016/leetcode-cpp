//
// Created by ZHONGFEI on 2021/4/10.
//

#include "RedudentConnectSln.h"


vector<int> RedudentConnectSln::findRedundantConnection(vector<vector<int>> &edges) {
    m_parents.resize(edges.size()+1, 0);
    m_parentsSonSize.resize(edges.size()+1, 0);
    for (int i = 1; i <= edges.size(); i++) {
        m_parents[i] = i;
        m_parentsSonSize[i] = 1;
    }
    for (auto &edge:edges) {
        int pParent = findParent(edge[0]);
        int qParent = findParent(edge[1]);
        if (pParent == qParent) {
            return edge;
        }
        unionNode(edge[0], edge[1]);
    }
    return vector<int>();
}

void RedudentConnectSln::unionNode(int p, int q) {
    int pParent = findParent(p);
    int qParent = findParent(q);
    if (pParent != qParent) {
        if (m_parentsSonSize[pParent] >= m_parentsSonSize[qParent]) {
            m_parents[pParent] = qParent;
            m_parentsSonSize[qParent] += m_parentsSonSize[pParent];
            m_parentsSonSize[pParent] = 0;
        } else {
            m_parents[qParent] = pParent;
            m_parentsSonSize[pParent] += m_parentsSonSize[qParent];
            m_parentsSonSize[qParent] = 0;
        }
        m_connectCnt--;
    }
}

int RedudentConnectSln::findParent(int node) {
    int parent = node;
    // 子节点的父节点的父节点也是子节点的父节点，找父节点时顺便缩短一下路径，方便后续查找
    while (m_parents[parent] != parent) {
        m_parents[parent] = m_parents[m_parents[parent]];
        parent = m_parents[parent];
    }
    return parent;
}
