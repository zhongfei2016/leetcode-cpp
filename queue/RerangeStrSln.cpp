//
// Created by ZHONGFEI on 2020/10/30.
//
//https://www.cnblogs.com/FdWzy/p/12389956.html
//

#include "RerangeStrSln.h"

#include <vector>
#include <queue>

struct CharItem {
    char ch;
    int times;
};

struct cmp {
    bool operator()(CharItem &item1, CharItem &item2) {
        return item1.times > item2.times;
    }
};

std::__cxx11::string RerangeStrSln::rearrangeString(std::__cxx11::string s, int k) {
    // 统计字符种类及对应个数
    vector<int> map(26, 0);
    for (auto ch : s) {
        map[ch - 'a'] += 1;
    }
    // 优先队列排序，按个数排
    priority_queue<pair<int, char>> que;
    for (int i=0;i<map.size();i++) {
        que.push(std::make_pair(map[i], i + 'a'));
    }
    //
    string res = "";
    while (res.size() < s.size()) {
        // 暫存剩余字符pair
        vector<pair<int, char>> tempVec;
        int minSize = min(k, static_cast<int>(que.size()));
        for (int i = 0; i < minSize; i++) {
            auto item = que.top();
            que.pop();
            res.push_back(item.second);
            item.first--;
            if (item.first > 0) {
                tempVec.push_back(item);
            }
        }
        //字符串剩余的字符种类，小于k，如果此时剩余字符没有都补在res后面，那再剩下的，就不能保证剩下的字符和前一个同类字符间隔是k了
        if (minSize < k && res.size() != s.size()) {
            return "";
        }
        for (auto vecItem:tempVec) {
            que.push(vecItem);
        }
    }
    return res;
}