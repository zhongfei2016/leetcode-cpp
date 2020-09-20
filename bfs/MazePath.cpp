//
// Created by ZHONGFEI on 2020/9/20.
//

#include "MazePath.h"
#include <queue>
#include <climits>

// 迷宫I https://michael.blog.csdn.net/article/details/107215680

bool MazePath::hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
    vector<vector<int>> dirs = {{0,  -1},
                                {0,  1},
                                {-1, 0},
                                {1,  0}};
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<vector<int>> que;
    visited[start[0]][start[1]] = true;
    que.push(start);
    while (!que.empty()) {
        int curX = que.front()[0];
        int curY = que.front()[1];
        que.pop();
        if (curX == destination[0] && curY == destination[1]) {
            return true;
        }
        for (int i = 0; i < dirs.size(); i++) {
            while (curX + dirs[i][0] >= 0 && curX + dirs[i][0] < m && curY + dirs[i][1] >= 0 && curY + dirs[i][1] < n &&
                   maze[curX + dirs[i][0]][curY + dirs[i][1]] == 0) {
                curX += dirs[i][0];
                curY += dirs[i][1];
            }
            if (!visited[curX][curY]) {
                visited[curX][curY] = true;
                que.emplace(curX, curY);
            }
        }
    }
    return false;
}

int MazePath::hasPathII(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
    vector<vector<int>> dirs = {{0,  -1},
                                {0,  1},
                                {-1, 0},
                                {1,  0}};
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<vector<int>> que;
    visited[start[0]][start[1]] = true;
    que.push(start);
    vector<vector<int>> steps(m, vector<int>(n, INT_MAX));
    steps[start[0]][start[1]] = 0;
    while (!que.empty()) {
        int curX = que.front()[0];
        int curY = que.front()[1];
        que.pop();
        if (curX == destination[0] && curY == destination[1]) {
            return steps[destination[0]][destination[1]] == INT_MAX ? -1 : steps[destination[0]][destination[1]];
        }
        for (int i = 0; i < dirs.size(); i++) {
            int delta = 0;
            int curTempX = curX;
            int curTempY = curY;
            while (curTempX + dirs[i][0] >= 0 && curTempX + dirs[i][0] < m && curTempY + dirs[i][1] >= 0 &&
                   curTempY + dirs[i][1] < n &&
                   maze[curTempY + dirs[i][0]][curTempY + dirs[i][1]] == 0) {
                curTempY += dirs[i][0];
                curTempY += dirs[i][1];
                delta++;
            }
            if (!visited[curTempY][curTempY]) {
                visited[curTempY][curTempY] = true;
                que.emplace(curTempY, curTempY);
                steps[curTempX][curTempY] = steps[curX][curY] + delta;
            }
        }
    }
    return steps[destination[0]][destination[1]] == INT_MAX ? -1 : steps[destination[0]][destination[1]];
}