//
// leetcode-cpp
// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]

#include "GroupAnagramsSolution.h"
#include <map>
#include <algorithm>

vector<vector<string>> GroupAnagramsSolution::groupAnagrams(vector<string> &strs) {
    map<string, vector<string>> map;
    vector<vector<string>> ans;
    for (string str : strs) {
        string temp = str;
        sort(temp.begin(), temp.end());
        map[temp].push_back(str);
    }
    for (auto item : map) {
        ans.push_back(item.second);
    }
    return ans;
}