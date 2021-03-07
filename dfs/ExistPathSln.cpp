//
// Created by ZHONGFEI on 2021/3/7.
// 矩阵中的路径 https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
//

#include "ExistPathSln.h"

#include <queue>

bool ExistPathSln::exist(vector<vector<char> > &board, std::string word) {
    char ch = word[0];
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (dfs(board, word, 0, i, j)) {
                return true;
            }
        }
    }
    return false;
}

bool ExistPathSln::dfs(vector<vector<char> > &board, string &endStr, int curIdx, int curX, int curY) {
    if (curX < 0 || curX >= board.size() || curY < 0 || curY >= board[0].size()) {
        return false;
    }
    if (board[curX][curY] != endStr[curIdx]) {
        return false;
    }
    if (curIdx == endStr.size() - 1) {
        return true;
    }
    // 创建visited数组的方式非常耗时且占空间，所以使用标记的方式
    char temp = board[curX][curY];
    board[curX][curY] = 0;
    bool res = dfs(board, endStr, curIdx + 1, curX + 1, curY)
               || dfs(board, endStr, curIdx + 1, curX - 1, curY)
               || dfs(board, endStr, curIdx + 1, curX, curY + 1)
               || dfs(board, endStr, curIdx + 1, curX, curY - 1);
    board[curX][curY] = temp;
    return res;
}