//
// Created by ZHONGFEI on 2021/3/3.
//

#ifndef LEETCODE_CPP_LANDPEREMITERSLN_H
#define LEETCODE_CPP_LANDPEREMITERSLN_H

#include <vector>

using namespace std;

class LandPeremiterSln {
public:
    int islandPerimeter(vector<vector<int>> &grid);

private:
    int dfs(vector<vector<int>>& grid, int i, int j);
};


#endif //LEETCODE_CPP_LANDPEREMITERSLN_H
