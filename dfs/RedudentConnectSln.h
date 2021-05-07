//
// leetcode-cpp
// dfs 深度优先遍历 https://leetcode-cn.com/problems/redundant-connection/

#ifndef LEETCODE_CPP_REDUDENTCONNECTSLN_H
#define LEETCODE_CPP_REDUDENTCONNECTSLN_H
#include <vector>
#include <map>

using namespace std;

class RedudentConnectSln {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges);

    bool dfs(int x, int y, vector<bool>& visited, map<int,vector<int>>& relationMap);
};


#endif //LEETCODE_CPP_REDUDENTCONNECTSLN_H
