//
// leetcode-cpp
//

#include "LadderLengthIISln.h"

#include <queue>
#include <unordered_set>

vector<vector<std::string>>
LadderLengthIISln::findLadders(std::string beginWord, std::string endWord, vector<std::string> wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) {
        return vector<vector<string>>(0);
    }
    // 存放可能的路径
    queue<vector<string>> que;
    vector<vector<string>> results;
    // 当前路径
    vector<string> path;
    path.push_back(beginWord);
    que.push(path);
    unordered_set<string> visited;
    visited.emplace(beginWord);
    // 本轮循环（本层）有到达endWord的标志
    bool isShortest = false;
    while (!que.empty()) {
        int size = que.size();
        // subVisited用于判断本轮循环是否访问过，visited存本轮之前所有循环已访问过的单词
        unordered_set<string> subVisited;
        for (int i = 0; i < size; i++) {
            auto tempPath = que.front();
            que.pop();
            string &curEndStr = tempPath.back();
            unordered_set<string> neighbours = findNeighbours(curEndStr, dict);
            for (auto &neighbour : neighbours) {
                if (visited.count(neighbour)) {
                    continue;
                }
                if (neighbour == endWord) {
                    isShortest = true;
                    tempPath.push_back(neighbour);
                    results.push_back(tempPath);
                    tempPath.erase(tempPath.end() - 1);
                }
                // tempPath先放进去当前neighbour，塞入队列后再弹出，方便判断同层级的下一个neighbour
                tempPath.push_back(neighbour);
                que.push(tempPath);
                subVisited.insert(neighbour);
                tempPath.erase(tempPath.end() - 1);
            }
        }
        visited.insert(subVisited.begin(), subVisited.end());
        if (isShortest) {
            break;
        }
    }
    return results;
}

unordered_set<string> LadderLengthIISln::findNeighbours(string &word, unordered_set<string> &dict) {
    unordered_set<string> neighbours;
    for (char i = 'a'; i <= 'z'; i++) {
        for (int j = 0; j < word.size(); j++) {
            if (i == word[j]) {
                continue;
            }
            char oldChar = word[j];
            word[j] = i;
            if (dict.count(word)) {
                neighbours.insert(word);
            }
            word[j] = oldChar;
        }
    }
    return neighbours;
}