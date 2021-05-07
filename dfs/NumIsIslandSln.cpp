//
// leetcode-cpp
//

#include "NumIsIslandSln.h"

int NumIsIslandSln::numIslands(vector<vector<char>> &grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

void NumIsIslandSln::dfs(vector<vector<char> > &grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
        return;
    }
    if (grid[x][y] != '1') {
        return;
    }
    grid[x][y] = '2';
    vector<vector<int>> dirs{{1,  0},
                             {-1, 0},
                             {0,  1},
                             {0,  -1}};
    for (auto dir : dirs) {
        dfs(grid, x + dir[0], y + dir[1]);
    }
}