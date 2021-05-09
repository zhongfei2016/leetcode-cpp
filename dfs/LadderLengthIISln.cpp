//
// leetcode-cpp
// 单词接龙 II bfs+dfs https://leetcode-cn.com/problems/word-ladder-ii/


#include <queue>
#include "LadderLengthIISln.h"

vector<vector<string>> LadderLengthIISln::findLadders(string beginWord, string endWord, vector<string> &wordList) {
    set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end()) {
        return {};
    }
    map<string, vector<string>> neighborMap;
    map<string, int> distance;
    findNeighborMapByBfs(beginWord, endWord, dict, neighborMap, distance);
    vector<string> tempRes;
    tempRes.push_back(beginWord);
    vector<vector<string>> results;
    findLaddersByDfs(beginWord, endWord, neighborMap, distance, tempRes, results);
    return results;
}

void LadderLengthIISln::findLaddersByDfs(string beginWord, string endWord, map<string, vector<string>> &neighborMap,
                                         map<string, int> &distance,
                                         vector<string> &tempRes,
                                         vector<vector<string>> &results) {
    if (beginWord == endWord) {
        results.push_back(tempRes);
        return;
    }
    auto iter = neighborMap.find(beginWord);
    auto neighbors = iter == neighborMap.end() ? vector<string>() : iter->second;
    for (auto &neighbor:neighbors) {
        if (distance.find(beginWord)->second + 1 == distance.find(neighbor)->second) {
            tempRes.push_back(neighbor);
            findLaddersByDfs(neighbor, endWord, neighborMap, distance, tempRes, results);
            tempRes.pop_back();
        }
    }
}

void LadderLengthIISln::findNeighborMapByBfs(string beginWord, string endWord, set<string> &dict,
                                             map<string, vector<string>> &neighborMap, map<string, int> &distance) {
    queue<string> que;
    que.push(beginWord);
    int depth = 0;
    distance[beginWord] = 0;
    bool isShortest = false;
    while (!que.empty()) {
        auto size = que.size();
        depth++;
        for (int i = 0; i < size; i++) {
            auto word = que.front();
            auto neighbors = findNeighbors(word, dict);
            for (auto iter = neighbors.begin(); iter != neighbors.end();iter++) {
                if (distance.find(*iter) == distance.end()) {
                    if (*iter == endWord) {
                        isShortest = true;
                    }
                    que.push(*iter);
                    distance[*iter] = depth;
                }
            }
            neighborMap[word] = neighbors;
            que.pop();
        }
        if (isShortest) {
            break;
        }
    }
}

vector<string> LadderLengthIISln::findNeighbors(string word, set<string> &dict) {
    vector<string> neighbors;
    for (int i = 0; i < word.size(); i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            if (word[i] == j) {
                continue;
            }
            char oldChar = word[i];
            word[i] = j;
            if (dict.find(word) != dict.end()) {
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
    }
    return neighbors;
}
