//
// leetcode-cpp
//

#include "RedudentConnectSln.h"


vector<int> RedudentConnectSln::findRedundantConnection(vector<vector<int>> &edges) {
    // visited用于记录每轮访问过的节点
    vector<bool> visited(edges.size() + 1, false);
    // map标记关联关系
    map<int, vector<int>> relationMap;
    for (auto &edge:edges) {
        std::fill(visited.begin(), visited.end(), false);
        if (dfs(edge[0], edge[1], visited, relationMap)) {
            return edge;
        }
        relationMap[edge[0]].push_back(edge[1]);
        relationMap[edge[1]].push_back(edge[0]);
    }
    return {};
}

// 通过递归方式预期找到x和y相同，不同就递归x的子节点，看x的子节点里是不是有y，有则说明x和y想通
// 还要维护一个map，如果x和y没有相通，且执行了dfs方法，则将这两者关联起来
// 如果edges里后面再有涉及x和y的点，说明x和y不仅相通而且构成环路了
// 这个edges点就是要找的破坏了树结构的结果
bool RedudentConnectSln::dfs(int x, int y, vector<bool> &visited, map<int, vector<int>> &relationMap) {
    if (x == y) {
        return true;
    }
    auto relationIter = relationMap.find(x);
    // 如果已访问过则x/y的关系不再重复查询
    // 如果map中没有x说明x还没有和任何元素有关系，也可以不再查询
    if (visited[x] || relationIter == relationMap.end()) {
        return false;
    }
    visited[x] = true;
    for (auto &child:relationIter->second) {
        if (dfs(child, y, visited, relationMap)) {
            return true;
        }
    }
    return false;
}