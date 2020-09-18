//
// Created by ZHONGFEI on 2020/9/13.
//

#include "LeastestIntervalSln.h"

#include <algorithm>

int LeastestIntervalSln::leastInterval(vector<char> &tasks, int n) {
    vector<int> times(26, 0);
    for (auto task:tasks) {
        times[task - 'A']++;
    }
    std::sort(times.begin(), times.end(), [](int &x, int &y) { return x > y; });
    int maxTaskNum = times[0];
    int cnt = 1;
    while (cnt < times.size() && times[cnt] == times[0]) cnt++;
    int interval = cnt + (n + 1) * (maxTaskNum - 1);
    return tasks.size() > interval ? tasks.size() : interval;
}