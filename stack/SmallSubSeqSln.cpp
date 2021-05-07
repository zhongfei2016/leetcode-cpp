//
// leetcode-cpp
// https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters/

#include <vector>
#include <stack>
#include <set>
#include "SmallSubSeqSln.h"

/**
 * 结果不能有重复字母，
 * 需要维护一个单调递增的栈，所以栈顶元素大于当前元素，就要考虑将栈顶元素弹出
 * 弹出前提是个数大于1，否则不能弹
 * @param s
 * @return
 */
std::string SmallSubSeqSln::smallestSubsequence(std::string s) {
    vector<int> charNums(26, 0);
    for (auto &ch : s) {
        charNums[ch - 'a']++;
    }
    vector<char> stk;
    std::set<char> resSet;
    for (auto &ch : s) {
        // 已经存在的不再添加，因为当前存在说明当前是升序，而新来的这个相同值，也没有再小的升序的可能
        // 如果有的话，后面的while循环会将其从set中弹出，就可以继续往下走了
        if (resSet.find(ch) != resSet.end()) {
            charNums[ch - 'a']--;
            continue;
        }
        while (!stk.empty() && stk.back() > ch) {
            auto item = stk.back();
            if (charNums[item - 'a'] > 1) {
                charNums[item - 'a']--;
                stk.pop_back();
                resSet.erase(item);
            } else {
                break;
            }
        }
        stk.push_back(ch);
        resSet.insert(ch);
    }
    string result(stk.begin(), stk.end());
    return result;
}