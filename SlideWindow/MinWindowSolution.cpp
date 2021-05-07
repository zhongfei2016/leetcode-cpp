//
// leetcode-cpp
//

#include "MinWindowSolution.h"
#include <unordered_map>
#include <climits>

// 滑动窗口方式处理，基本思路：
//int left = 0, right = 0;
//
//while (right < s.size()) {
//    window.add(s[right]);
//    right++;
//
//    while (valid) {
//        window.remove(s[left]);
//        left++;
//    }
//}
string MinWindowSolution::minWindow(string s, string t) {
    if (t.length() > s.length()) {
        return "";
    }
    // 窗口的左右指针
    int left = 0;
    int right = 0;
    // 记录当前窗口中匹配到t中字符的个数
    int match = 0;
    // 记录最短子串的起始位和长度
    int start = 0, minLen = INT_MAX;
    // 窗口中所含有效字符及个数
    unordered_map<char, int> windowMap;
    // t字符串中要求的所需字符及个数
    unordered_map<char, int> needMap;
    // 统计t字符串中要求的所需字符及个数
    for (char c : t) {
        needMap[c]++;
    }
    // 右指针右移，直到到达s的末尾
    while (right < s.size()) {
        char cr = s[right];
        // 判断当前字符是否是要求的字符，是的话windowMap中加入此字符并将个数加1
        // map的count表示判断是否包含这个key
        if (needMap.count(cr)) {
            windowMap[cr]++;
            // 如果windowMap中的当前字符达到要求的个数，匹配个数match加1
            if (windowMap[cr] == needMap[cr]) {
                match++;
            }
        }
        right++;

        // 如果匹配字符类型个数match和要求的字符类型数相同了，记录最小字符子串的起始位和长度
        while (match == needMap.size()) {
            if (right - left < minLen) {
                start = left;
                minLen = right - left;
            }
            // 尝试将左指针右移，看是否仍符合match == needMap.size()的要求
            char cl = s[left];
            // 取左指针对应的值判断是否在needMap中
            if (needMap.count(cl)) {
                // 如果在那左指针右移会丢掉这个值，所以在windowMap中删除一次计数
                windowMap[cl]--;
                if (windowMap[cl] < needMap[cl]) {
                    // 如果此字符在windowMap中的计数达不到needMap的要求，match就要减1
                    match--;
                }
            }
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}