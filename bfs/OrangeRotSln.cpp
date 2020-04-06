//
// Created by ZHONGFEI on 2020/4/6.
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