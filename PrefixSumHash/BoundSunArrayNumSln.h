//
// Created by ZHONGFEI on 2021/4/5.
// 区间子数组个数 https://leetcode-cn.com/problems/number-of-subarrays-with-bounded-maximum/

#ifndef LEETCODE_CPP_BOUNDSUNARRAYNUMSLN_H
#define LEETCODE_CPP_BOUNDSUNARRAYNUMSLN_H

#include <vector>

using namespace std;

class BoundSunArrayNumSln {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R);
    int countSubArrayNum(vector<int> &A, int maxNum);
};


#endif //LEETCODE_CPP_BOUNDSUNARRAYNUMSLN_H
