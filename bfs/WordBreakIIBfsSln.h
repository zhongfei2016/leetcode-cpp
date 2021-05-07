//
// leetcode-cpp
// 单词拆分
//

#ifndef LEETCODE_CPP_WORKBREAKBFSSLN_H
#define LEETCODE_CPP_WORKBREAKBFSSLN_H

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class WordBreakIIBfsSln {
public:
    void dfs(unordered_map<int, vector<string>> &res, string &s, int start, unordered_set<string> &dict);

    vector<string> wordBreak(string s, vector<string> wordDict);
};


#endif //LEETCODE_CPP_WORKBREAKBFSSLN_H
