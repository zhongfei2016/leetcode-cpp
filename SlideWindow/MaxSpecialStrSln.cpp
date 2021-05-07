//
// leetcode-cpp
// 给定一个字符串，获取其中只有两个字符个数为1个（其他字符无要求）的最长子字符串

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "MaxSpecialStrSln.h"

std::string MaxSpecialStrSln::GetMaxSpecialStr(std::string inputStr) {
    std::unordered_set<char> satisfiedChars;
    std::unordered_map<char, int> charTotalNum;
    // 统计每个字符的个数
    for (auto &ch : inputStr) {
        charTotalNum[ch]++;
    }
    int left = 0;
    int right = 0;
    int startPos = INT_MAX;
    int maxLen = 0;
    while (right < inputStr.size()) {
        // 为1的计入符合要求的集合中
        if (charTotalNum[inputStr[right]] == 1) {
            satisfiedChars.insert(inputStr[right]);
        }
        // 不符合要求了则要从左开始剔除元素
        while (satisfiedChars.size() > 2) {
            if (charTotalNum[inputStr[left]] == 1) {
                satisfiedChars.erase(inputStr[left]);
            }
            left++;
        }

        // 满足要求，则计算长度和起始位置，保证最后可以取到结果字符串
        if (satisfiedChars.size() == 2) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                startPos = left;
            }
        }
        right++;
    }
    string res = startPos == INT_MAX ? "" : inputStr.substr(startPos, maxLen);
    return res;
}