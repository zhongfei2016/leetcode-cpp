//
// Created by ZHONGFEI on 2021/3/3.
//

#include "LandPeremiterSln.h"

int LandPeremiterSln::islandPerimeter(vector<vector<int>> &grid) {
    if (grid.empty()) {
        return 0;
    }
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                return dfs(grid, i, j);
            }
        }
    }
    return 0;
}

int LandPeremiterSln::dfs(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
        return 1;
    }
    if (grid[i][j] == 0) {
        return 1;
    }

    if (grid[i][j] == 2) {
        return 0;
    }
    grid[i][j] = 2;
    return dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
}