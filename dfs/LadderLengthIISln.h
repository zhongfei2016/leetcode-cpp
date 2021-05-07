//
// leetcode-cpp
// bfs+dfs https://leetcode-cn.com/problems/word-ladder-ii/

#ifndef LEETCODE_CPP_LADDERLENGTHIISLN_H
#define LEETCODE_CPP_LADDERLENGTHIISLN_H

#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

class LadderLengthIISln {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList);

private:
    vector<string> findNeighbors(string word, set<string> &dict);

    void findNeighborMapByBfs(string beginWord, string endWord, set<string> &dict, map<string, vector<string>>& neighborMap, map<string, int>& distance);

    void findLaddersByDfs(string beginWord, string endWord,map<string, vector<string>>& neighborMap, map<string, int>& distance, vector<string>& tempRes, vector<vector<string>>& results);
};


#endif //LEETCODE_CPP_LADDERLENGTHIISLN_H
