//
// leetcode-cpp
//
#include <iostream>
#include "MaxSubArraySolution.h"
#include "UniquePathSolution.h"
#include "MinPathSumSolution.h"
#include "MinDistanceSolution.h"
#include "CoinChangeSln.h"
#include "CoinChangeIISln.h"
#include "MinCostTicketsSln.h"
#include "UniquePathWithObstacleSln.h"
#include "CountSubstrSln.h"
#include "LongestPalindromeSequenceSln.h"
#include "YangHuiTriangleSln.hpp"
#include "ClimbStairSolution.h"
#include "MaxRecSolution.h"
#include "MaxProfitSolution.h"
#include "WordBreakSln.h"
#include "MaxCoinsSln.h"

int main() {
// 最大子序和 https://leetcode-cn.com/problems/maximum-subarray
    MaxSubArraySolution maxSubArrSln;
    vector<int> maxSubArrVec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxSubArrSln.maxSubArrayDP(maxSubArrVec);

    // 不同路径 https://leetcode-cn.com/problems/unique-paths/
    UniquePathSolution uniPathSln;
    uniPathSln.uniquePaths(23, 12);

    // 最小路径和 https://leetcode-cn.com/problems/minimum-path-sum/
    MinPathSumSolution minPathSumSln;
    vector<vector<int>> minPathSumVec;
    vector<int> minPathSumVec1 = {1, 3, 1};
    vector<int> minPathSumVec2 = {1, 5, 1};
    vector<int> minPathSumVec3 = {4, 2, 1};
    minPathSumVec.push_back(minPathSumVec1);
    minPathSumVec.push_back(minPathSumVec2);
    minPathSumVec.push_back(minPathSumVec3);
    minPathSumSln.minPathSum(minPathSumVec);

    // 爬楼梯 https://leetcode-cn.com/problems/climbing-stairs/
    ClimbStairSolution climbStairSln;
    climbStairSln.climbStairs(3);

    // 编辑距离 https://leetcode-cn.com/problems/edit-distance/
    MinDistanceSolution minDistanceSln;
    int minDistance = minDistanceSln.minDistance("horse", "ros");

    // 最大矩形面积
    MaxRecSolution maxRecSolution;
    vector<int> largestRectVec = {2, 1, 5, 6, 2, 3};
    maxRecSolution.largestRectangleArea(largestRectVec);

    // 最大矩形 https://leetcode-cn.com/problems/maximal-rectangle/
    MaxRecSolution maxRecSln;
    vector<vector<char>> maxRecVec;
    vector<char> maxRecVec1 = {'1', '0', '1', '0', '0'};
    vector<char> maxRecVec2 = {'1', '0', '1', '1', '1'};
    vector<char> maxRecVec3 = {'1', '1', '1', '1', '1'};
    vector<char> maxRecVec4 = {'1', '0', '0', '1', '0'};
    maxRecVec.push_back(maxRecVec1);
    maxRecVec.push_back(maxRecVec2);
    maxRecVec.push_back(maxRecVec3);
    maxRecVec.push_back(maxRecVec4);
    maxRecSln.maximalRectangle(maxRecVec);
    maxRecSln.maximalRectangle2(maxRecVec);

    // 买股票最佳时机 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
    MaxProfitSolution maxProfitSln;
    vector<int> maxProfitVec = {7, 1, 5, 3, 6, 4};
    maxProfitSln.maxProfit(maxProfitVec);

    // 单词拆分 动态规划 https://leetcode-cn.com/problems/word-break/
    WordBreakSln wordBreakSln;
    string wordBreakWord = "leetcode";
    vector<string> wordBreakDict = {"leet", "code"};
    wordBreakSln.wordBreak(wordBreakWord, wordBreakDict);

    // 零钱兑换 https://leetcode-cn.com/problems/coin-change/solution/
    CoinChangeSln coinChangeSln;
    vector<int> coinChangeVec = {2, 5, 10, 1};
    coinChangeSln.coinChange(coinChangeVec, 27);

    // 零钱兑换 II https://leetcode-cn.com/problems/coin-change-2/
    CoinChangeIISln coinChangeIISln;
    vector<int> coinChangeIIVec = {1, 2, 5};
    coinChangeIISln.change(5, coinChangeIIVec);

    // 最低票价 https://leetcode-cn.com/problems/minimum-cost-for-tickets/
    MinCostTicketsSln minCostTicketsSln;
    vector<int> minCostTicketsVec = {1, 4, 6, 7, 8, 20};
    vector<int> minCostTicketsCostsVec = {2, 7, 15};
    minCostTicketsSln.mincostTickets(minCostTicketsVec, minCostTicketsCostsVec);

    // 不同路径 II https://leetcode-cn.com/problems/unique-paths-ii/
    UniquePathWithObstacleSln uniquePathWithObstacleSln;
    vector<vector<int>> uniPathObsVec = {{0, 0, 0},
                                         {0, 1, 0},
                                         {0, 0, 0}};
    std::cout << "UniquePathWithObstacleSln result: "
              << uniquePathWithObstacleSln.uniquePathsWithObstacles(uniPathObsVec) << std::endl;

    // 回文子串 https://leetcode-cn.com/problems/palindromic-substrings/
    CountSubstrSln countSubstrSln;
    countSubstrSln.countSubstrings("abc");

    // 最长回文子序列 https://leetcode-cn.com/problems/longest-palindromic-subsequence/
    LongestPalindromeSequenceSln longestPalindromeSequenceSln;
    longestPalindromeSequenceSln.longestPalindromeSubseq("bbbab");

    // 杨辉三角
    YangHuiTriangleSln yangHuiTriangleSln;
    yangHuiTriangleSln.generate(5);

    MaxCoinsSln maxCoinsSln;
    vector<int> maxCoinVec = {3,1,5,8};
    maxCoinsSln.maxCoins2(maxCoinVec);
    maxCoinsSln.maxCoins3(maxCoinVec);
    return 0;
}