//
// leetcode-cpp
//
#include "SolutionLengthOfLongestSubstring.h"

#include "MinWindowSolution.h"
#include "EqualSubStrSln.hpp"
#include "MinSubArrayLenSln.h"
#include "TotalFruitSln.h"
#include "SubArrWithDistinctSln.h"
#include "MaxSpecialStrSln.h"

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

    TotalFruitSln totalFruitSln;
    vector<int> fruitVec = {1, 2, 1};
    totalFruitSln.totalFruit(fruitVec);
    fruitVec = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    totalFruitSln.totalFruit(fruitVec);

    vector<int> subArrDistinctVec = {1, 2, 1, 2, 3};
    SubArrWithDistinctSln subArrWithDistinctSln;
    subArrWithDistinctSln.subarraysWithKDistinct(subArrDistinctVec, 2);

    MaxSpecialStrSln maxSpecialStrSln;
    maxSpecialStrSln.GetMaxSpecialStr("70016"); // 7001
    maxSpecialStrSln.GetMaxSpecialStr("abbbccccccdee"); // abbbccccccdee
    return 0;
}