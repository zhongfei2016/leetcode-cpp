//
// leetcode-cpp
//

#include "UniquePathWithObstacleSln.h"

int UniquePathWithObstacleSln::uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    // 如果是空数组，则没有路径
    if (obstacleGrid.size() == 0) {
        return 0;
    }
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    //如果左上或右下为1-有障碍，则没有路径，直接返回0
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1]==1) {
        return 0;
    }
    // 设置dp表，表示到达第m，n个格子的路径数
    long dp[m][n];
    // dp[0][0]作为基数，计算第一列和第一排的dp值
    dp[0][0] = 1;
    // 逐个给第一列赋值，如果当前格子是0，且前一个dp是1，说明当前的dp可以提供有效值，赋1
    for (int i = 1; i < m; i++) {
        dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
    }
    // 逐个给第一行赋值，如果当前格子是0，且前一个dp是1，说明当前的dp可以提供有效值，赋1
    for (int i = 1; i < n; i++) {
        dp[0][i] = (obstacleGrid[0][i] == 0 && dp[0][i - 1] == 1) ? 1 : 0;
    }
    // 计算其他dp值，如果ij对应格子为1，则dp[i][j]为0
    // 其他情况则dp值为左dp值+上dp值，即 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] != 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m-1][n-1];
}