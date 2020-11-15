//
// Created by ZHONGFEI on 2020/11/15.
//

#include "ReorganizeStrSln.h"

#include <vector>
#include <queue>

struct ReorgStrCmp {
    bool operator()(pair<int, char> &a, pair<int, char> &b) {
        return a.first < b.first;
    }
};

std::string ReorganizeStrSln::reorganizeString(std::string S) {
    vector<int> counts(26, 0);
    int maxCount = 0;
    for (int i = 0; i < S.size(); i++) {
        counts[S[i] - 'a']++;
        maxCount = max(maxCount, counts[S[i] - 'a']);
    }
    // 单个字母的最大个数小于S长度的一半，则无解
    if (maxCount > (S.size() + 1) / 2) {
        return "";
    }
    priority_queue<pair<int, char>, vector<pair<int, char>>, ReorgStrCmp> que;
    for (int i = 0; i < counts.size(); i++) {
        if (counts[i] > 0) {
            que.push(std::make_pair(counts[i], i + 'a'));
        }
    }
    string ans;
    while (que.size() > 1) {
        vector<pair<int, char>> temp;
        int tempCount = 2;
        // 只需要隔开即可，所以每轮遍历2次，多出来的元素先暂存，再放入que用于下一轮遍历
        while (tempCount--) {
            auto item = que.top();
            que.pop();
            ans += item.second;
            if (item.first > 1) {
                temp.push_back(std::make_pair(item.first - 1, item.second));
            }
        }
        for (auto t:temp) {
            que.push(t);
        }
    }
    while (!que.empty()) {
        if (que.top().first > 1) {
            return "";
        }
        ans += que.top().second;
        que.pop();
    }
    return ans;
}