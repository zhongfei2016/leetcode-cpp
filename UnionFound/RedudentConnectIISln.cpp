//
// Created by ZHONGFEI on 2021/4/11.
//

#include "RedudentConnectIISln.h"

vector<int> RedudentConnectIISln::findRedundantDirectedConnection(vector<vector<int> > &edges) {
    // 使用拓扑排序统计入度
    vector<int> inDegree(edges.size() + 1, 0);
    for (auto &edge:edges) {
        inDegree[edge[1]]++;
    }
    // 有入度为2的一定会导致构不成树，所以倒序排除一个，排除的时候要判断剔除后是否就是树了
    // 如果剔除了还是环，说明不止有入度为2的，还有有向环
    for (int i = edges.size() - 1; i >= 0; i--) {
        if (inDegree[edges[i][1]] == 2) {
            if (!isCircle(edges, i)) {
                return edges[i];
            }
        }
    }
    for (int i = edges.size() - 1; i >= 0; i--) {
        if (inDegree[edges[i][1]] == 1) {
            if (!isCircle(edges, i)) {
                return edges[i];
            }
        }
    }
    return {};
}

bool RedudentConnectIISln::isCircle(vector<vector<int>> &edges, int idx) {
    UniFound uniFound(edges.size());
    for (int i = 0; i < edges.size(); i++) {
        if (i == idx) {
            continue;
        }
        // 如果能连通，说明之前未通，当前两个点可以构成有效树结构
        // 如果已经连通，就不能再连通了，返回false，说明这个边是构成环的边
        // 说明此时剔除掉idx边，还是会成为环
        if (!uniFound.joinPoints(edges[i][0], edges[i][1])) {
            return true;
        }
    }
    return false;
}

int UniFound::findParent(int x) {
    int p = m_parents[x];
    while (p != m_parents[p]) {
        m_parents[p] = m_parents[m_parents[p]];
        p = m_parents[p];
    }
    return p;
}
// 如果父节点不同，则可以连通，返回true，如果父节点相同，无法再次连通，返回false
bool UniFound::joinPoints(int x, int y) {
    int xP = findParent(x);
    int yP = findParent(y);
    if (xP == yP) {
        return false;
    }
    m_parents[xP] = yP;
    return true;
}
