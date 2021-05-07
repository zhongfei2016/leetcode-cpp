//
// leetcode-cpp
//
//https://www.cnblogs.com/winter-bamboo/p/11493755.html
//https://www.zhihu.com/question/23995189/answer/613096905

#include "TurtleMovesSln.h"

int TurtleMovesSln::turtleMovesSteps(int n, int m, vector<int> moves, vector<int> cards) {
    vector<int> cardNums(5, 0);
    for (auto card: cards) {
        cardNums[card]++;
    }
    vector<vector<vector<vector<int>>>> dp(cardNums[1], vector<vector<vector<int>>>(cardNums[2],
                                                                                    vector<vector<int>>(cardNums[3],
                                                                                                        vector<int>(
                                                                                                                cardNums[4],
                                                                                                                0))));
    dp[0][0][0][0] = moves[0];
    for (int x1 = 0; x1 <= cardNums[1]; x1++) {
        for (int x2 = 0; x2 <= cardNums[2]; x2++) {
            for (int x3 = 0; x3 <= cardNums[3]; x3++) {
                for (int x4 = 0; x4 <= cardNums[4]; x4++) {
                    int step = 1 + x1 * 1 + x2 * 2 + x3 * 3 + x4 * 4;
                    if (x1>0) {
                        dp[x1][x2][x3][x4] = max(dp[x1][x2][x3][x4], dp[x1-1][x2][x3][x4] + moves[step]);
                    }
                    if (x2>0) {
                        dp[x1][x2][x3][x4] = max(dp[x1][x2][x3][x4], dp[x1][x2-1][x3][x4] + moves[step]);
                    }
                    if (x3>0) {
                        dp[x1][x2][x3][x4] = max(dp[x1][x2][x3][x4], dp[x1][x2][x3-1][x4] + moves[step]);
                    }
                    if (x4>0) {
                        dp[x1][x2][x3][x4] = max(dp[x1][x2][x3][x4], dp[x1][x2][x3][x4-1] + moves[step]);
                    }
                }
            }
        }
    }
    return dp[cardNums[1]][cardNums[2]][cardNums[3]][cardNums[4]];
}