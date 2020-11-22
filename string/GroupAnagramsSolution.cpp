//
// Created by ZHONGFEI on 2020/1/29.
//

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