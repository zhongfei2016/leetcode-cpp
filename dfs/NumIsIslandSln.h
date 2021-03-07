//
// Created by ZHONGFEI on 2021/2/28.
// https://leetcode-cn.com/problems/number-of-islands/ 岛屿的数量
//

#ifndef LEETCODE_CPP_NUMISISLANDSLN_H
#define LEETCODE_CPP_NUMISISLANDSLN_H

#include <vector>
using namespace std;

class NumIsIslandSln {
public:
    int numIslands(vector<vector<char>>& grid);
    void dfs(vector<vector<char>>& grid, int x, int y);
};


#endif //LEETCODE_CPP_NUMISISLANDSLN_H
