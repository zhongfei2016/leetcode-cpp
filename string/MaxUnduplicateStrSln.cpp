//
// Created by ZHONGFEI on 2020/10/25.
//

#include "MaxUnduplicateStrSln.h"

#include <map>
#include <set>

// https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/   最长不含重复字符的子字符串
//"abcabcbb"
//"bbbbb"
int MaxUnduplicateStrSln::lengthOfLongestSubstring(std::__cxx11::string s) {
    if (s.size() <= 1) {
        return s.size();
    }
    int left = 0, right = 0;
    int res = 1;
    set<char> set;
    set.emplace(s[left]);
    while (right < s.size() - 1) {
        right++;
        if (set.count(s[right]) == 0) {
            res = max(res, right - left + 1);
        } else {
            // 右值存在，则暂存右值，将其在set中从第一个left查找，找一个删一个，直到直到set中不含右值为止
            char temp = s[right];
            while (set.count(temp) != 0) {
                set.erase(s[left++]);
            }
        }
        // 将本次的右值放入set
        set.emplace(s[right]);
    }
    return res;
}

// "abba"
int MaxUnduplicateStrSln::lengthOfLongestSubstring2(string s) {
    int res = 0;
    int i = -1;
    map<char, int> map;
    for (int j = 0; j < s.size(); j++) {
        if (map.count(s[j])) {
            i = max(i, map[s[j]]);// 要找最大的左边界
        }
        res = max(res, j - i);
        map[s[j]] = j;
    }
    return res;
}