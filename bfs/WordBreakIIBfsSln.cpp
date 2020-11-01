//
// Created by ZHONGFEI on 2020/11/1.
//

#include "WordBreakIIBfsSln.h"

void WordBreakIIBfsSln::dfs(unordered_map<int, vector<string>> &res, string &s, int start, unordered_set<string> &dict) {
    if (res.count(start)) {
        return;
    }
    if (start >= s.size()) {
        res[start] = {""};
        return;
    }
    res[start] = {};
    for (int newStart = start + 1; newStart <= s.size(); newStart++) {
        string word = s.substr(start, newStart - start);
        if (dict.count(word)) {
            dfs(res, s, newStart, dict);
            for (string temp : res[newStart]) {
                res[start].push_back(temp.empty() ? word : word + " " + temp);
            }
        }
    }
}

vector<string> WordBreakIIBfsSln::wordBreak(string s, vector<string> wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    // 使用hash表暂存以每一个idx起始的string数组
    unordered_map<int, vector<string>> res;
    dfs(res, s, 0, dict);
    return res[0];
}