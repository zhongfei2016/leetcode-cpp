//
// leetcode-cpp
// https://leetcode-cn.com/problems/redundant-connection-ii/

#ifndef LEETCODE_CPP_REDUDENTCONNECTIISLN_H
#define LEETCODE_CPP_REDUDENTCONNECTIISLN_H

#include <vector>

using namespace std;

class RedudentConnectIISln {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges);

    bool isCircle(vector<vector<int> > &edges, int idx);
};

class UniFound {
public:
    UniFound(int n) {
        m_parents.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            m_parents[i] = i;
        }
    }

    int findParent(int x);

    bool joinPoints(int x, int y);

private:
    vector<int> m_parents;
};


#endif //LEETCODE_CPP_REDUDENTCONNECTIISLN_H
