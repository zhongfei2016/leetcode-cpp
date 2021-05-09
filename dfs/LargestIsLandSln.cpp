//
// leetcode-cpp
// 最大岛屿面积 https://leetcode-cn.com/problems/making-a-large-island/
// 解法：https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-lei-wen-ti-de-tong-yong-jie-fa-dfs-bian-li-/
//

#include "LargestIsLandSln.h"

#include <unordered_map>
#include <unordered_set>

int dfsArea(vector<vector<int> > &grid, int x, int y, int idx, vector<vector<int> > &idxVec) {
    if (x < 0 || x >= idxVec.size() || y < 0 || y >= idxVec.size()) {
        return 0;
    }
    if (grid[x][y] != 1) {
        return 0;
    }
    idxVec[x][y] = idx;
    grid[x][y] = 2;
    return 1 + dfsArea(grid, x + 1, y, idx, idxVec) + dfsArea(grid, x - 1, y, idx, idxVec) +
           dfsArea(grid, x, y + 1, idx, idxVec) + dfsArea(grid, x, y - 1, idx, idxVec);
}

int LargestIsLandSln::largestIsland(vector<vector<int> > &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int size = min(m, n);
    // 用于存每一片岛屿对应的编号
    vector<vector<int> > idxVec(size, vector<int>(size, 0));
    int idx = 0;
    // 用于存每一个编号对应的岛屿面积
    unordered_map<int, int> idxAreaMap;
    int maxArea = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 1) {
                idx++;
                idxAreaMap[idx] = dfsArea(grid, i, j, idx, idxVec);
            }
        }
    }
    vector<vector<int>> dirs{{1,  0},
                             {-1, 0},
                             {0,  1},
                             {0,  -1}};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] != 0) {
                continue;
            }
            // 遍历每一个为0的坐标，看他的四个方向有没有岛屿，有就可以连接起来，并计算出本轮面积值
            unordered_set<int> seen;
            int area = 1;
            for (auto dir : dirs) {
                int tempX = i + dir[0];
                int tempY = j + dir[1];
                if (tempX < 0 || tempX >= idxVec.size() || tempY < 0 || tempY >= idxVec.size()) {
                    continue;
                }
                if (idxVec[tempX][tempY] != 0) {
                    // 本轮四个方向的当前方向的岛屿标号本轮之前未访问则计入本轮面积
                    if (seen.insert(idxVec[tempX][tempY]).second) {
                        area += idxAreaMap[idxVec[tempX][tempY]];
                    }
                }
            }
            maxArea = max(maxArea, area);
        }
    }
    return maxArea == 0 ? size * size : maxArea;
}