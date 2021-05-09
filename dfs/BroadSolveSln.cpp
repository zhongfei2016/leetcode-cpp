//
// leetcode-cpp
// 被围绕的区域 https://leetcode-cn.com/problems/surrounded-regions/

#include <stack>
#include "BroadSolveSln.h"

void BroadSolveSln::solve(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && (board[i][j] == 'O')) {
                dfs(board, i, j);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if (board[i][j] == '*') {
                board[i][j] = 'O';
            }
        }
    }
}

// 使用递归方式实现dfs
void BroadSolveSln::dfs(vector<vector<char> > &board, int x, int y) {
    if (board[x][y] == 'O') {
        board[x][y] = '*';
    } else {
        return;
    }
    if (x > 0) {
        dfs(board, x - 1, y);
    }
    if (x < board.size() - 1) {
        dfs(board, x + 1, y);
    }
    if (y > 0) {
        dfs(board, x, y - 1);
    }
    if (y < board[0].size() - 1) {
        dfs(board, x, y + 1);
    }
}

// 使用栈的方式实现dfs
void BroadSolveSln::dfs2(vector<vector<char> > &board, int x, int y) {
    stack<std::pair<int, int>> stk;
    stk.push(std::make_pair(x, y));
    board[x][y] = '*';
    while (!stk.empty()) {
        auto item = stk.top();
        int curX = item.first;
        int curY = item.second;
        if (curX > 0 && board[curX - 1][curY] == 'O') {
            board[curX - 1][curY] = '*';
            stk.push(std::make_pair(curX - 1, curY));
            continue;// dfs就是要将当前分支走到底再试其他分支
        }
        if (curX < board.size() - 1 && board[curX + 1][curY] == 'O') {
            board[curX + 1][curY] = '*';
            stk.push(std::make_pair(curX + 1, curY));
            continue;
        }
        if (curY > 0 && board[curX][curY - 1] == 'O') {
            board[curX][curY - 1] = '*';
            stk.push(std::make_pair(curX, curY - 1));
            continue;
        }
        if (curY < board[0].size() - 1 && board[curX][curY + 1] == 'O') {
            board[curX][curY + 1] = '*';
            stk.push(std::make_pair(curX, curY + 1));
            continue;
        }
        stk.pop();
    }
}