//
// leetcode-cpp
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
    // 从岛屿跨到边界，则边界+1
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
        return 1;
    }
    // 从岛屿跨到海洋，边界也+1
    if (grid[i][j] == 0) {
        return 1;
    }

    if (grid[i][j] == 2) {
        return 0;
    }
    // 访问过的岛屿面积置为2，避免重复访问
    grid[i][j] = 2;
    // 由当前点向四个方向再跨一步，继续尝试
    return dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
}