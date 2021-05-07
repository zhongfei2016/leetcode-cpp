//
// leetcode-cpp
//

#include "OrangeRotSln.h"
#include <queue>

int OrangeRotSln::orangesRotting(vector<vector<int>> &grid) {
    queue<pair<int, int>> que;
    int refresh = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                que.push(make_pair(i, j));
            } else if (grid[i][j] == 1) {
                refresh++;
            }
        }
    }
    int round = 0;
    while (refresh > 0 && !que.empty()) {
        round++;
        int curSize = que.size();
        for (int i = 0; i < curSize; i++) {
            auto item = que.front();
            que.pop();
            if (item.first < m - 1 && grid[item.first + 1][item.second] == 1) {
                grid[item.first + 1][item.second] = 2;
                que.push(make_pair(item.first + 1, item.second));
                refresh--;
            }
            if (item.first > 0 && grid[item.first - 1][item.second] == 1) {
                grid[item.first - 1][item.second] = 2;
                que.push(make_pair(item.first - 1, item.second));
                refresh--;
            }
            if (item.second < n - 1 && grid[item.first][item.second + 1] == 1) {
                grid[item.first][item.second + 1] = 2;
                que.push(make_pair(item.first, item.second + 1));
                refresh--;
            }
            if (item.second > 0 && grid[item.first][item.second - 1] == 1) {
                grid[item.first][item.second - 1] = 2;
                que.push(make_pair(item.first, item.second - 1));
                refresh--;
            }
        }
    }
    if (refresh > 0) {
        return -1;
    }
    return round;
}

struct Orange {
    int x;
    int y;

    Orange(int x, int y) : x(x), y(y) {};
};

vector<vector<int>> OrangeRotSln::dirs = {{0,  1},
                            {0,  -1},
                            {1,  0},
                            {-1, 0}};

int OrangeRotSln::orangesRotting2(vector<vector<int>> &grid) {
    queue<Orange> que;
    int fresh = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 2) {
                que.push(Orange(i, j));
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int step = 0;
    while (fresh > 0 && !que.empty()) {
        int size = que.size();
        step++;
        for (int i = 0; i < size; i++) {
            auto orange = que.front();
            que.pop();
            for (auto dir : dirs) {
                int tempX = orange.x + dir[0];
                int tempY = orange.y + dir[1];
                if (tempX < 0 || tempX >= grid.size() || tempY < 0 || tempY >= grid[0].size() ||
                    grid[tempX][tempY] != 1) {
                    continue;
                }
                if (grid[tempX][tempY] == 1) {
                    grid[tempX][tempY] = 2;
                    que.push(Orange(tempX, tempY));
                    fresh--;
                }
            }
        }
    }
    if (fresh > 0) {
        return -1;
    }
    return step;
}