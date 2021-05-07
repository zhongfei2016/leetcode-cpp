//
// leetcode-cpp
//
// 单词接龙 https://leetcode-cn.com/problems/word-ladder/

#ifndef LEETCODE_CPP_LADDERLENGTHSLN_HPP
#define LEETCODE_CPP_LADDERLENGTHSLN_HPP

class LadderLengthSln {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList);
};

bool IsSimilarWord(string &word1, string &word2) {
    int size1 = word1.size();
    int size2 = word2.size();
    int diffCnt = 0;
    int size = size1 < size2 ? size1 : size2;
    for (int i = 0; i < size; i++) {
        if (word1[i] != word2[i]) {
            diffCnt++;
            if (diffCnt > 1) {
                return false;
            }
        }
    }
    if (abs(size2 - size1) + diffCnt > 1) {
        return false;
    }
    return true;
}

int LadderLengthSln::ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    queue<string> que;
    que.push(beginWord);
    vector<bool> visited(wordList.size(), false);
    int step = 0;
    while (!que.empty()) {
        int queSize = que.size();
        step++;
        for (int i = 0; i < queSize; i++) {
            string curWord = que.front();
            que.pop();
            if (curWord == endWord) {
                return step;
            }
            for (int j = 0; j < wordList.size(); j++) {
                if (visited[j]) {
                    continue;
                }
                if (IsSimilarWord(curWord, wordList[j])) {
                    que.push(wordList[j]);
                    visited[j] = true;
                }
            }
        }
    }
    return 0;
}

#endif //LEETCODE_CPP_LADDERLENGTHSLN_HPP
