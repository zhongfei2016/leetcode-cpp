//
// Created by ZHONGFEI on 2020/5/2.
//
// 滑动窗口 尽可能使字符串相等 https://leetcode-cn.com/problems/get-equal-substrings-within-budget/

#ifndef LEETCODE_CPP_EQUALSUBSTRSLN_HPP
#define LEETCODE_CPP_EQUALSUBSTRSLN_HPP

class EqualSubStrSln {
public:
    int equalSubstring(string s, string t, int maxCost);
};

int EqualSubStrSln::equalSubstring(std::__cxx11::string s, std::__cxx11::string t, int maxCost) {
    int left = 0, right = 0;
    int len = s.size();
    int maxLen = 0;
    int curCost = 0;
    while (right < len) {
        // 计算一次当前值
        curCost += abs(s[right] - t[right]);
        // 如果超出了最值要求
        while (curCost > maxCost) {
            // 则左指针右移，并减去左值，不断重复直到满足最值要求
            curCost -= abs(s[left] - t[left]);
            left++;
        }
        // 计算此时满足要求的最大长度，然后右指针再次右移
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

#endif //LEETCODE_CPP_EQUALSUBSTRSLN_HPP
