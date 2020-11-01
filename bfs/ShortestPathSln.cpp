//
// Created by ZHONGFEI on 2020/11/1.
// https://leetcode-cn.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
//

#include "ShortestPathSln.h"

#include <queue>

vector<vector<int>> ShortestPathSln::dirs = {{1,  0},
                                             {-1, 0},
                                             {0,  1},
                                             {0,  -1}};

struct Step {
    int x;
    int y;
    int k;

    Step(int x, int y, int k) : x(x), y(y), k(k) {}
};

int ShortestPathSln::shortestPath(vector<vector<int>> grid, int k) {
    if (grid.empty()) {
        return 0;
    }
    if (grid.size() <= 1 && grid[0].size() <= 1) {
        return 0;
    }
    queue<Step> que;
    que.push(Step(0, 0, k));
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
    visited[0][0][k] = true;
    int step = 0;
    while (!que.empty()) {
        step++;
        int size = que.size();
        for (int i = 0; i < size; i++) {
            auto item = que.front();
            que.pop();
            for (auto dir:dirs) {
                int temX = item.x + dir[0];
                int temY = item.y + dir[1];
                if (temX < 0 || temX >= grid.size() || temY < 0 || temY >= grid[0].size()) {
                    continue;
                }
                if (temX == m - 1 && temY == n - 1) {
                    return step;
                }
                if (visited[temX][temY][item.k]) {
                    continue;
                }
                if (grid[temX][temY] == 0) {
                    que.push(Step(temX, temY, item.k));
                    visited[temX][temY][item.k] = true;
                } else {
                    if (item.k <= 0) {
                        continue;
                    } else {
                        // 需要判断新产生的这个是否访问过
                        if (visited[temX][temY][item.k - 1]) {
                            continue;
                        }
                        que.push(Step(temX, temY, item.k - 1));
                        visited[temX][temY][item.k - 1] = true;
                    }
                }
            }
        }
    }
    return -1;
}