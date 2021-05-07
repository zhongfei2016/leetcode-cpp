//
// leetcode-cpp
// 任务调度器 https://leetcode-cn.com/problems/task-scheduler/  题解：https://leetcode-cn.com/problems/task-scheduler/solution/tong-zi-by-popopop/
// 计算所有任务所需要的时间，要保证相同任务间要有n个冷却时间
//
// 需要算两个数：
//
//1、NUM1：
// 记录最大任务数量 N，看一下任务数量并列最多的任务有多少个，即最后一个桶子的任务数 X
// 计算 NUM1=(N-1)*(n+1)+X
//2、NUM2：
// NUM2=tasks.size()
//输出其中较大值即可
//因为存在空闲时间时肯定是 NUM1大，不存在空闲时间时肯定是 NUM2>=NUM1

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