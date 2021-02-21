//
// Created by ZHONGFEI on 2021/2/21.
//

#include "AlienOrderSln.h"

#include <unordered_map>
#include <unordered_set>
#include <queue>

void
GetInDegreeAndGraph(vector<std::string> &words, unordered_map<char, int> &inDegree,
                    std::unordered_map<char, unordered_set<char>> &graph) {
    // 单词已按照顺序排好，所以需要比较前一个单词和后一个单词同一位置的字母，统计出入度和邻接表
    // 但是单个单词的字母之前并没有排好序，所以入度表和邻接表是上下两个单词之间统计，而非在一个单词里统计
    // 注意：已经排序的是单词，而不是单词中的字母
    for (int i = 0; i < words.size() - 1; i++) {
        string word1 = words[i];
        string word2 = words[i + 1];
        int n1 = word1.size();
        int n2 = word2.size();
        int n = min(n1, n2);
        for (int j = 0; j < n; j++) {
            if (word1[j] == word2[j]) {
                continue;
            }
            if (graph.find(word1[j]) == graph.end() || graph[word1[j]].find(word2[j]) == graph[word1[j]].end()) {
                graph[word1[j]].insert(word2[j]);
                inDegree[word2[j]] ++; // 统计入度
                inDegree[word1[j]] += 0;// 统计入度为0的字母
                break;
            }
        }
    }
}

std::string AlienOrderSln::alienOrder(vector<std::string> &words) {
    if (words.empty()) { return ""; }
    if (words.size() == 1) {
        return words[0];
    }
    unordered_set<char> allChars;
    for (auto &word : words) {
        for (auto &ch : word) {
            allChars.insert(ch);
        }
    }
    unordered_map<char, int> inDegree(0);
    std::unordered_map<char, unordered_set<char>> graph;
    GetInDegreeAndGraph(words, inDegree, graph);
    queue<char> que;
    for (auto &deIter : inDegree) {
        if (deIter.second == 0) {
            que.push(deIter.first);
        }
    }
    string ans;
    while (!que.empty()) {
        auto ch = que.front();
        allChars.erase(ch);
        que.pop();
        ans += ch;
        auto neighbors = graph.find(ch);
        if (neighbors == graph.end()) {
            continue;
        }
        for (auto &neighbor : neighbors->second) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                que.push(neighbor);
            }
        }
    }
    if (ans.size() != inDegree.size()) {
        return "";
    }
    if (allChars.empty()) {
        return ans;
    }
    for (auto &ch : allChars) {
        ans += ch;
    }
    return ans;
}