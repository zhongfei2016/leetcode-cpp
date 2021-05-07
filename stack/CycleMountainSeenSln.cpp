//
// leetcode-cpp
// https://blog.csdn.net/qq_33369979/article/details/111056334
// 一个不含有负数的数组可以代表环形一圈的山峰
// 山峰 A 和 山峰 B 能够相互看见的条件为:
//如果 A 和 B 是同一座山，认为不能相互看见。
//如果 A 和 B 是不同的山，并且在环中相邻，认为可以相互看见。
//如果 A 和 B 是不同的山，并且在环中不相邻，假设两座山高度的最小值为 min
// 如果 A 通过 next 方向到 B 的途中没有高度比 min 大的山峰
// 或者 A 通过 last 方向到 B 的途中没有高度比 min 大的山峰，认为 A 和 B 可以相互看见。

// 问题：给定一个含有负数可能有重复值的数组 arr，请问有多少对山峰能够相互看见？

#include <stack>
#include "CycleMountainSeenSln.h"

// 无重复点
int CycleMountainSeenSln::countCycleMountainSeen(vector<int> mountains) {
    // 由于最高的可以看到所有山峰，所有在所有山峰遍历完之前不能弹出，所以要最先入栈
    stack<int> stk;
    int maxIdx = 0;
    for (int i = 0; i < mountains.size(); i++) {
        if (mountains[i] > mountains[maxIdx]) {
            maxIdx = i;
        }
    }
    int count = 0;
    stk.push(mountains[maxIdx]);
    for (int i = 0; i < mountains.size(); i++) {
        if (mountains[i] == mountains[maxIdx]) {
            continue;
        }
        // 如果有递增的，则弹出一个，弹出的元素与即将入栈和当前栈顶元素均互相可见，所以加2
        while (!stk.empty() && stk.top() < mountains[i]) {
            count += 2;
            stk.pop();
        }
        stk.push(mountains[i]);
    }
    // 全处理完后剩余单调递减，如果大于2个，则栈顶元素即与前一个元素可见，又与栈顶元素可见，所以加2后弹出
    while (stk.size() > 2) {
        count += 2;
        stk.pop();
    }
    // 直到剩余2个，就相互可见即可
    if (stk.size() == 2) {
        count += 1;
    }
    return count;
}

// 有重复点
int CycleMountainSeenSln::countCycleMountainSeen2(vector<int> mountains) {
}