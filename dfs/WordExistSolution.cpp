//
// leetcode-cpp
//

#include "WordExistSolution.h"

bool backtrack(int i, int j, int idx, vector<vector<char>> &board, string &word) {
    // 索引越界返回false
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || idx >= word.size()) {
        return false;
    }
    // 当前元素与预期不符，返回false
    if (word[idx] != board[i][j]) {
        return false;
    }
    // 当前字符符合要求且已经是最后一个字符，返回true
    if (idx == word.size() - 1 && word[idx] == board[i][j]) {
        return true;
    }

    // 继续遍历下一层，并把当前的字符改为一个无效字符#，保证向四个方向遍历时不会误遍历到已遍历过的字符
    char temp = board[i][j];
    board[i][j] = '#';
    if (backtrack(i, j + 1, idx + 1, board, word) || backtrack(i, j - 1, idx + 1, board, word)
        || backtrack(i + 1, j, idx + 1, board, word) || backtrack(i - 1, j, idx + 1, board, word)) {
        return true;
    }
    board[i][j] = temp;
    return false;
}

bool WordExistSolution::exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (backtrack(i, j, 0, board, word)) {
                return true;
            }
        }
    }
    return false;
}