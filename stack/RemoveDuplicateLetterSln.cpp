//
// leetcode-cpp
//

#include <stack>
#include <set>
#include <vector>
#include "RemoveDuplicateLetterSln.h"

string RemoveDuplicateLetterSln::removeDuplicateLetters(string s) {
    vector<char> stk;
    // 统计所有字符数量
    vector<int> charNums(26, 0);
    for (auto &ch : s) {
        charNums[ch - 'a']++;
    }
    // 判断是否访问过，也可以用vector<bool> visited
    set<char> resultSet;
    for (auto &ch : s) {
        // 已访问过则不再访问，说明当前结果集里的当前字符已符合要求
        // 不符合会在后面的逻辑里剔除，后面再遇到自然可以访问
        if (resultSet.find(ch) != resultSet.end()) {
            charNums[ch - 'a']--;
            continue;
        }
        // 单调栈，发现递减趋势就判断是否可以剔除，后续还有就可以剔除
        while (!stk.empty() && ch < stk.back() && charNums[stk.back() - 'a'] > 0) {
            resultSet.erase(stk.back());
            stk.pop_back();
        }
        stk.push_back(ch);
        resultSet.insert(ch);
        charNums[ch - 'a']--;
    }
    string result(stk.begin(), stk.end());
    return result;
}