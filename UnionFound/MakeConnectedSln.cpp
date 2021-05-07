//
// leetcode-cpp
//

// https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/
// 连通网络的操作次数

#include "MakeConnectedSln.h"

class UnionFound {
public:
    UnionFound(int n) : count(n), rest(0), parent(vector<int>(n)), rank(vector<int>(n)) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    ~UnionFound() = default;

    void Merge(int x, int y) {
        int parentX = Find(x);
        int parentY = Find(y);
        if (parentX != parentY) {
            if (rank[parentX] < rank[parentY]) {
                std::swap(parentX, parentY);
            }
            parent[parentY] = parentX;
            if (rank[parentX] == rank[parentY]) {
                rank[parentX]++;
            }
            count--;
        } else {
            rest++;
        }
    }

    int Find(int x) {
        while (parent[x] != x) {
            x = parent[x];
        }
        return parent[x];
    }

    int GetCount() {
        return count;
    }

    int GetRest() {
        return rest;
    }

private:
    // 父节点数组
    vector<int> parent;
    // 当前父节点的深度
    vector<int> rank;
    // 剩余的连通量
    int count;
    // 多余的连通线
    int rest;
};

int MakeConnectedSln::makeConnected(int n, vector<vector<int> > &connections) {
    UnionFound unionFound{n};
    for (int i = 0; i < connections.size(); i++) {
        unionFound.Merge(connections[i][0], connections[i][1]);
    }
    return unionFound.GetRest() >= (unionFound.GetCount() - 1) ? (unionFound.GetCount() - 1) : -1;
}