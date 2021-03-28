//
// Created by ZHONGFEI on 2021/3/26.
//
#include <iostream>
#include "DailyTempSln.h"
#include "FindLenOfLCISSln.h"
#include "MaxNumSln.h"
#include "MostCompetitiveSln.h"
#include "NextGreatElementSln.h"
#include "SolutionBracketValid.h"
#include "LongValidBracketSolution.h"
#include "TrapSolution.h"
#include "IncDecArraySln.h"

using namespace std;

int main() {
// 判断有效的括号，比如{}[]()  [[()]]
    SolutionBracketValid sbv;
    std::cout << sbv.isValid(")}{({))[{{[}") << std::endl;

    // 最长有效括号  https://leetcode-cn.com/problems/longest-valid-parentheses/
    LongValidBracketSolution lvbs;
    lvbs.longestValidParentheses("(()");

    // 接雨水 https://leetcode-cn.com/problems/trapping-rain-water/
    TrapSolution trapSln;
    vector<int> trapSlnVec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    trapSln.trap(trapSlnVec);

    // 给定一个数组，如果去掉一个数后数组非严格单调增/减，则求出这个数，如果有多种方案，求最小值
    IncDecArraySln incDecArraySln;
    vector<int> incDecArrayVec = {5, 3, 4, 4, 5};
    incDecArraySln.GetIncDecNum(incDecArrayVec);

    DailyTempSln dailyTempSln;
    vector<int> dailyTempVec = {73, 74, 75, 71, 69, 72, 76, 73};
    dailyTempSln.dailyTemperatures(dailyTempVec);

    FindLenOfLCISSln findLenOfLcisSln;
    vector<int> findLenOfLcisVec = {1, 3, 5, 4, 7};
    findLenOfLcisSln.findLengthOfLCIS(findLenOfLcisVec);

    MaxNumSln maxNumSln;
    maxNumSln.maxNumber({3, 4, 6, 5}, {9, 1, 2, 5, 8, 3}, 5);
    maxNumSln.maxNumber({6, 7}, {6, 0, 4}, 5);

    MostCompetitiveSln mostCompetitiveSln;
    vector<int> mostCompetitiveVec = {3, 5, 2, 6};
    mostCompetitiveSln.mostCompetitive(mostCompetitiveVec, 2);

    NextGreatElementSln nextGreatElementSln;
    vector<int> nextGreatEleVec = {1,2,1};
    nextGreatElementSln.nextGreaterElements(nextGreatEleVec);
    return 0;
}