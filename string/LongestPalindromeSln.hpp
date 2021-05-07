//
// leetcode-cpp
//
// 最长回文串 取给定字符串的字符凑最长回文串 https://leetcode-cn.com/problems/longest-palindrome/

#ifndef LEETCODE_CPP_LONGESTPALINDROMESLN_HPP
#define LEETCODE_CPP_LONGESTPALINDROMESLN_HPP

#include <unordered_map>

class LongestPalindromeSln {
public:
    int longestPalindrome(string s);
};

int LongestPalindromeSln::longestPalindrome(string s) {
    // map用来存每个字母及其出现的次数
    unordered_map<char, int> map;
    for (char ch : s) {
        map[ch]++;
    }
    int ans = 0;
    for (auto mapIter : map) {
        // 按位与1就是取二进制最后一位看是1还是0，是1说明是奇数，0说明是偶数
        if (mapIter.second & 1 == 1) {
            // 奇数就取个数减1，相当于取了偶数个，可能是0个
            ans += mapIter.second - 1;
        } else {
            // 偶数取所有
            ans += mapIter.second;
        }
    }
    // 长度不够说明减了某个或某几个奇数，可以取一个放在中间，所以加1
    if(ans < s.size()) {
        return ans + 1;
    }
    return ans;
}

#endif //LEETCODE_CPP_LONGESTPALINDROMESLN_HPP
