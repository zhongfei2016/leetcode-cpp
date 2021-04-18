//
// Created by ZHONGFEI on 2021/4/18.
//

#ifndef LEETCODE_CPP_BROADSOLVESLN_H
#define LEETCODE_CPP_BROADSOLVESLN_H

#include "vector"

using namespace std;

class BroadSolveSln {
public:
    void solve(vector<vector<char>> &board);

    void dfs(vector<vector<char>> &board, int x, int y);

    void dfs2(vector<vector<char>> &board, int x, int y);
};


#endif //LEETCODE_CPP_BROADSOLVESLN_H
