//
// leetcode-cpp
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
#include "CheckPossibleSln.h"
#include "RemoveKdigitsSln.h"
#include "SmallSubSeqSln.h"
#include "RemoveDuplicateLetterSln.h"
#include "NumberOfMountainSeenSln.h"
#include "CycleMountainSeenSln.h"

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
    vector<int> nextGreatEleVec = {1, 2, 1};
    nextGreatElementSln.nextGreaterElements(nextGreatEleVec);

    CheckPossibleSln checkPossibleSln;
    vector<int> checkPossibleVec = {3, 4, 2, 3};
    checkPossibleSln.checkPossibility(checkPossibleVec);

    RemoveKdigitsSln removeKdigitsSln;
    removeKdigitsSln.removeKdigits("1432219", 3);
    removeKdigitsSln.removeKdigits("10200", 1);

    SmallSubSeqSln smallSubSeqSln;
    smallSubSeqSln.smallestSubsequence("bcabc");// abc
    smallSubSeqSln.smallestSubsequence("cbacdcbc"); // acdb
    smallSubSeqSln.smallestSubsequence("cbaacabcaaccaacababa"); // abc
    smallSubSeqSln.smallestSubsequence("bcbcbcababa"); // bca

    RemoveDuplicateLetterSln removeDuplicateLetterSln;
    removeDuplicateLetterSln.removeDuplicateLetters("bcabc"); // abc
    removeDuplicateLetterSln.removeDuplicateLetters("cbacdcbc"); // acdb

    vector<int> mountains = {16,5,3,10,21,7}; // 8
    NumberOfMountainSeenSln numberOfMountainSeenSln;
    numberOfMountainSeenSln.NumberOfMountainSeen(mountains);

    CycleMountainSeenSln cycleMountainSeenSln;
    cycleMountainSeenSln.countCycleMountainSeen({3,1,2,4,5});
    return 0;
}