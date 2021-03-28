//
// Created by ZHONGFEI on 2021/3/26.
//
#include "SolutionLengthOfLongestSubstring.h"

#include "MinWindowSolution.h"
#include "EqualSubStrSln.hpp"
#include "MinSubArrayLenSln.h"

using namespace std;

int main() {
// 最长不重复子串 https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
    string str = "abcabdcdd";
    SolutionLengthOfLongestSubstring lols;
    int maxLen = lols.lengthOfLongestSubstring(str);

    // 最小覆盖子串 https://leetcode-cn.com/problems/minimum-window-substring/
    MinWindowSolution minWindowSln;
    string minWindowStr = minWindowSln.minWindow("ADOBECODEBANC", "ABC");

    // 滑动窗口 尽可能使字符串相等 https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
    EqualSubStrSln equalSubStrSln;
    equalSubStrSln.equalSubstring("pxezla", "loewbi", 25);

    MinSubArrayLenSln minSubArrayLenSln;
    vector<int> minSubArrayLenVec = {1, 2, 1, 3, 4};
    minSubArrayLenSln.minSubArrayLen(7, minSubArrayLenVec);
    return 0;
}