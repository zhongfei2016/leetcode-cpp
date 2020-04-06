//
// Created by ZHONGFEI on 2020/4/6.
//

#include "BroadSolveSln.h"

#include <queue>

void BroadSolveSln::solve(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();
    queue<pair<int, int>> que;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                que.push(make_pair(i, j));
            }
        }
    }
    queue<pair<int, int>> queTemp;
    while (!que.empty()) {
        auto loc = que.front();
        que.pop();
        if (loc.first == 0 || loc.first == m - 1 || loc.second == 0 || loc.second == n - 1) {
            board[loc.first][loc.second] = 'Y';
        } else {
            queTemp.push(loc);
        }
    }
    while (!queTemp.empty()) {
        auto loc = queTemp.front();
        queTemp.pop();
        if (board[loc.first - 1][loc.second] == 'Y' || board[loc.first + 1][loc.second] == 'Y'
            || board[loc.first][loc.second - 1] == 'Y' || board[loc.first][loc.second + 1] == 'Y') {
            board[loc.first][loc.second] = 'Y';
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'Y') {
                board[i][j] = 'O';
            }
        }
    }
}