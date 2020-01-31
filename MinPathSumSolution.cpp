//
// Created by ZHONGFEI on 2020/1/30.
//

#include "MinPathSumSolution.h"

void backtrack(int a, int b, vector<vector<int>> &grid, int &sum, int &min) {
    sum += grid[a][b];
    if (a == (grid.size() - 1) && b == (grid[0].size() - 1)) {
        if (min < 0) {
            min = sum;
        }
        if (min > sum) {
            min = sum;
        }
        return;
    }
    if (a < (grid.size() - 1)) {
        backtrack(a + 1, b, grid, sum, min);
        sum -= grid[a + 1][b];
    }
    if (b < (grid[0].size() - 1)) {
        backtrack(a, b + 1, grid, sum, min);
        sum -= grid[a][b + 1];
    }
}

int minFun(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int MinPathSumSolution::minPathSum(vector<vector<int>> &grid) {
    int sum = 0;
    int min = -1;
    //递归方式，超时
//    backtrack(0, 0, grid, sum, min);
    int dp[grid.size()][grid[0].size()];
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else if (i > 0 && j == 0) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            } else if (i == 0 && j > 0) {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            } else if (i > 0 && j > 0) {
                dp[i][j] = minFun(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }
    min = dp[grid.size()-1][grid[0].size()-1];
    return min;
}
