//
// Created by ZHONGFEI on 2021/5/4.
// 山峰编号1~N
// 站在编号为奇数的山峰上向左看，统计可以看到的山峰数
// 站在编号为偶数的山峰上向右看，统计可以看到的山峰数
// 不包含当前所站的山峰，从所站位置往预期放向看是递增数列，举例：16,5,3,10,21,7

#include <stack>
#include "NumberOfMountainSeenSln.h"

int NumberOfMountainSeenSln::odd(vector<int> &mountains) {
    stack<int> stk;
    int nums = 0;
    for (int i = 0; i < mountains.size(); i++) {
        if (i % 2 == 0) {// 奇数向左看
            nums += stk.size();
        }
        // 保证从左往右是递减数列，从右往左看才能看得到
        while (!stk.empty() && stk.top() <= mountains[i]) {
            stk.pop();
        }
        stk.push(mountains[i]);
    }
    return nums;
}

int NumberOfMountainSeenSln::even(vector<int> &mountains) {
    stack<int> stk;
    int nums = 0;
    for (int i = mountains.size() - 1; i >= 0; i--) {
        if (i % 2 == 1) {// 偶数向右看
            nums += stk.size();
        }
        // 保证从右往左是递减数列，从左往右才能看到
        while (!stk.empty() && stk.top() <= mountains[i]) {
            stk.pop();
        }
        stk.push(mountains[i]);
    }
    return nums;
}

int NumberOfMountainSeenSln::NumberOfMountainSeen(vector<int> &mountains) {
    int res = odd(mountains) + even(mountains);
    return res;
}