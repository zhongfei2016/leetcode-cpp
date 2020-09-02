//
// Created by ZHONGFEI on 2020/4/6.
//

#ifndef LEETCODE_CPP_BROADSOLVESLN_H
#define LEETCODE_CPP_BROADSOLVESLN_H

#include <vector>

using namespace std;

class BroadSolveSln {
public:
    void solve(vector<vector<char>>& board);

    void bfs(vector<vector<char>>& board, int i, int j);
};


#endif //LEETCODE_CPP_BROADSOLVESLN_H
