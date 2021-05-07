//
// leetcode-cpp
//
#include <vector>
#include <set>
#include "SolutionLengthOfLongestSubstring.h"

int SolutionLengthOfLongestSubstring::lengthOfLongestSubstring(string s) {
    set<char> sets;
    int res = 0;
    // 定义左位为连续不重复子串的起始索引，右位为连续不重复子串的结束索引
    // 右位减左位即连续不重复子串的长度
    int i = 0, j = 0;

    while (i < s.size() && j < s.size()) {
        // 如果塞进去无重复值，则右位+1，更新最大长度
        if (sets.emplace(s[j]).second) {
            j++;
            res = max(res, j - i);
        } else {
            // 否则将左位删掉，左位+1
            sets.erase(s[i]);
            i++;
        }
    }

    return res;
}