//
// Created by ZHONGFEI on 2020/11/1.
//

#include "TaskScheduleSln.h"

#include <queue>

int TaskScheduleSln::leastInterval(vector<char> task, int n) {
    vector<int> nums(26, 0);
    for (auto t:task) {
        nums[t - 'A']++;
    }
    priority_queue<pair<int, char>> que;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] <= 0)
            continue;
        que.push(std::make_pair(nums[i], i + 'A'));
    }
    int time = 0;
    while (!que.empty()) {
        vector<pair<int, char>> temp;
        for (int i = 0; i <= n; i++) {
            if (!que.empty()) {
                auto item = que.top();
                que.pop();
                if (item.first > 1) {
                    temp.emplace_back(item.first - 1, item.second);
                }
            }
            time++;
            if (que.empty() && temp.empty()) {
                break;
            }
        }
        if (!temp.empty()) {
            for (auto t:temp) {
                que.push(t);
            }
        }
    }
    return time;
}