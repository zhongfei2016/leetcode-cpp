//
// Created by ZHONGFEI on 2020/5/1.
//
// 并查集 朋友圈 https://leetcode-cn.com/problems/friend-circles/

#ifndef LEETCODE_CPP_UNIONFOUNDSLN_HPP
#define LEETCODE_CPP_UNIONFOUNDSLN_HPP

#include <vector>

using namespace std;
// 朋友圈 https://leetcode-cn.com/problems/friend-circles/
class UnionFoundSln {
public:
    int findCircleNum(vector<vector<int>> &M);

    void CreateUnion(int count);

    /**
     * 连通p和q节点，也就是将其挂在同一个根节点上
     * @param p
     * @param q
     */
    void unionPoint(int p, int q);

    /**
     * 查找p的根节点
     * @param p
     * @return
     */
    int findParent(int p);

    /**
     * 判断两节点是否连通
     * @param p
     * @param q
     * @return
     */
    bool isConnected(int p, int q);

private:
    /**
     * 连通数
     */
    vector<int> m_parents;
    /**
     * 连通分量个数
     */
    int m_count;

    /**
     * 加一个称重，避免每次union的时候把子节点都挂到同一个root上
     */
    vector<int> m_size;
};

int UnionFoundSln::findCircleNum(vector<vector<int> > &M) {
    int count = M.size();
    CreateUnion(count);
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < i; j++) {
            if(M[i][j] == 1) {
                unionPoint(i, j);
            }
        }
    }
    return m_count;
}

void UnionFoundSln::CreateUnion(int count) {
    // 构造连通分量和连通树
    m_count = count;
    for (int i = 0; i < count; i++) {
        // 起初每个节点的根节点都是自己，各不相连
        m_parents.push_back(i);
        m_size.push_back(1);
    }
}

int UnionFoundSln::findParent(int p) {
    // 暂存到parent中
    int parent = p;
    // 寻找当前节点的根节点，直到m_parents[parent] == parent说明找到了根节点
    while (m_parents[parent] != parent) {
        // 当前节点的父节点的父节点也是当前节点的父节点，所以可以直接越一级挂上去
        // 这样在find的同时也能压缩路径
        m_parents[parent] = m_parents[m_parents[parent]];
        parent = m_parents[parent];
    }
    return parent;
}

void UnionFoundSln::unionPoint(int p, int q) {
    // 联合p/q，即要求p/q同源，其父节点也要求同源
    int rootP = findParent(p);
    int rootQ = findParent(q);
    // 所以需要把一个父节点挂在另一个父节点上，为保证平衡，要把多的挂在少的上
    if (rootP != rootQ) {
        // 以rootQ为根的节点个数多余以rootP为根的节点个数
        // 所以rootQ认新的节点rootP作为父节点，并将其子节点数都挂着rootP下
        // 并且少了一个分支，连通数减1
        if (m_size[rootQ] > m_size[rootP]) {
            m_parents[rootP] = rootQ;
            m_size[rootP] += m_size[rootQ];
            m_count--;
        } else {
            // 两者权重相同，则可以随便挂
            // 此处是将rootP认新的节点rootQ作为父节点，并将其子节点数都挂着rootQ下
            // 并且少了一个分支，连通数减1
            m_parents[rootQ] = rootP;
            m_size[rootQ] += m_size[rootP];
            m_count--;
        }
    }
    return;
}

bool UnionFoundSln::isConnected(int p, int q) {
    int rootP = findParent(p);
    int rootQ = findParent(q);
    return rootP == rootQ;
}

#endif //LEETCODE_CPP_UNIONFOUNDSLN_HPP
