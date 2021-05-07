//
// leetcode-cpp
// 被围绕的区域 https://leetcode-cn.com/problems/surrounded-regions/
// 找出所有不被围绕的O置为特殊符号，剩下的就都是会被围绕的

#include "BroadSolveSln.h"

#include <queue>

struct Pos {
    int i;
    int j;

    Pos(int i, int j) {
        this->i = i;
        this->j = j;
    }
};

void BroadSolveSln::solve(vector<vector<char>> &board) {
    if (board.size() == 0) return;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 从边缘第一个是o的开始搜索
            bool isEdge = i == 0 || j == 0 || i == m - 1 || j == n - 1;
            if (isEdge && board[i][j] == 'O') {
                bfs(board, i, j);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
        }
    }
};

void BroadSolveSln::bfs(vector<vector<char>> &board, int i, int j) {
    std::queue<Pos> queue;
    queue.push(Pos(i, j));
    board[i][j] = '#';
    while (!queue.empty()) {
        Pos current = queue.front();
        queue.pop();
        // 上
        if (current.i - 1 >= 0
            && board[current.i - 1][current.j] == 'O') {
            queue.push(Pos(current.i - 1, current.j));
            board[current.i - 1][current.j] = '#';
            // 没有continue.
        }
        // 下
        if (current.i + 1 <= board.size() - 1
            && board[current.i + 1][current.j] == 'O') {
            queue.push(Pos(current.i + 1, current.j));
            board[current.i + 1][current.j] = '#';
        }
        // 左
        if (current.j - 1 >= 0
            && board[current.i][current.j - 1] == 'O') {
            queue.push(Pos(current.i, current.j - 1));
            board[current.i][current.j - 1] = '#';
        }
        // 右
        if (current.j + 1 <= board[0].size() - 1
            && board[current.i][current.j + 1] == 'O') {
            queue.push(Pos(current.i, current.j + 1));
            board[current.i][current.j + 1] = '#';
        }
    }
}
