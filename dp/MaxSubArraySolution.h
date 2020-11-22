//
// Created by ZHONGFEI on 2020/1/30.
//
// 最大子序和 https://leetcode-cn.com/problems/maximum-subarray

#ifndef LEETCODE_MAXSUBARRAYSOLUTION_H
#define LEETCODE_MAXSUBARRAYSOLUTION_H

#include <vector>

using namespace std;

class MaxSubArraySolution {
public:
    int maxSubArray(vector<int>& nums);
    int maxSubArrayDP(vector<int>& nums);
};


#endif //LEETCODE_MAXSUBARRAYSOLUTION_H
