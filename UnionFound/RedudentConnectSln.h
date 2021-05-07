//
// leetcode-cpp
// 并查集 https://leetcode-cn.com/problems/redundant-connection/

#ifndef LEETCODE_CPP_REDUDENTCONNECTSLN_H
#define LEETCODE_CPP_REDUDENTCONNECTSLN_H

#include <vector>

using namespace std;

class RedudentConnectSln {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges);

private:
    void unionNode(int p, int q);

    int findParent(int node);

    vector<int> m_parents;
    vector<int> m_parentsSonSize;
    int m_connectCnt;
};


#endif //LEETCODE_CPP_REDUDENTCONNECTSLN_H
