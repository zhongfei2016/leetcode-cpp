//
// leetcode-cpp
//
// 单词拆分 https://leetcode-cn.com/problems/word-break/

#ifndef LEETCODE_CPP_WORDBREAKBFSSLN_HPP
#define LEETCODE_CPP_WORDBREAKBFSSLN_HPP
// 单词拆分 https://leetcode-cn.com/problems/word-break/
class WordBreakBfsSln {
public:
    bool wordBreak(string s, vector<string> &wordDict);
};

bool WordBreakBfsSln::wordBreak(string s, vector<string> &wordDict) {
    // 定义索引队列
    queue<int> idxQue;
    // 当前索引是否访问过的标志数组
    vector<bool> visited(s.size() + 1, false);
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    idxQue.push(0);
    while (!idxQue.empty()) {
        int queSize = idxQue.size();
        for (int i = 0; i < queSize; i++) {
            int idx = idxQue.front();
            idxQue.pop();
            if (visited[idx]) {
                continue;
            }
            // 以当前索引位加1开始，判断s字符串的子串是否在dict中，子串以idx开始，截取end-idx长度
            for (int end = idx + 1; end <= s.size(); end++) {
                if (wordSet.find(s.substr(idx, end - idx)) != wordSet.end()) {
                    // 如果直接取到最终位了，直接返回成功
                    // 因为只要s用空格分出的所有单词都在dict中即可，不需要dict中的单词都在s中
                    if (end == s.size()) { return true; }
                    idxQue.push(end);
                }
            }
            visited[idx] = true;
        }
    }
    return false;
}

#endif //LEETCODE_CPP_WORDBREAKBFSSLN_HPP
