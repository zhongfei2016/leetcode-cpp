//
// leetcode-cpp
// 根据字符出现频率排序 哈希 桶排序 优先队列 https://leetcode-cn.com/problems/sort-characters-by-frequency/
//

#include "FrequencySortSln.h"

#include <map>
#include <vector>
#include <queue>

std::string FrequencySortSln::frequencySort(std::string s) {
    map<char, int> count;
    for (auto ch : s) {
        count[ch]++;
    }
    vector<string> bucket(s.size() + 1, "");
    string res;
    for (auto iter = count.begin(); iter != count.end(); iter++) {
        for (int i = 0; i < iter->second; i++) {
            bucket[iter->second] += iter->first;
        }
    }
    for (int i = bucket.size() - 1; i >= 0; i--) {
        if (!bucket[i].empty()) {
            res += bucket[i];
        }
    }
    return res;
}

struct cmp {
    bool operator()(std::pair<char, int> &lhs, std::pair<char, int> &rhs) {
        return lhs.second < rhs.second;
    }
};

std::string FrequencySortSln::frequencySort2(std::string s) {
    map<char, int> count;
    for (auto ch : s) {
        count[ch]++;
    }
    priority_queue<std::pair<char, int>, vector<std::pair<char, int>>, cmp> que;
    for (auto iter = count.begin(); iter != count.end(); iter++) {
        que.push({iter->first, iter->second});
    }
    string res{};
    while (!que.empty()) {
        auto item = que.top();
        for (int i = 0; i < item.second; i++) {
            res += item.first;
        }
        que.pop();
    }
    return res;
}