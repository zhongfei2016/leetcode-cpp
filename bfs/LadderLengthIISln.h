//
// Created by ZHONGFEI on 2020/11/14.
//单词接龙II https://leetcode-cn.com/problems/word-ladder-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-3-3/


#ifndef LEETCODE_CPP_LADDERLENGTHIISLN_H
#define LEETCODE_CPP_LADDERLENGTHIISLN_H

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class LadderLengthIISln {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> wordList);

private:
    unordered_set<string> findNeighbours(string& word, unordered_set<string>& dict);
};


#endif //LEETCODE_CPP_LADDERLENGTHIISLN_H
