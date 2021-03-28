//
// Created by ZHONGFEI on 2021/3/26.
//
#include "SubArraySumSln.hpp"
#include "CheckSubArraySumSln.hpp"
#include <vector>
using namespace std;

int main() {
    // 前缀和Hash 和为K的子数组 https://leetcode-cn.com/problems/subarray-sum-equals-k/
    SubArraySumSln subArraySumSln;
    vector<int> subArraySumVec = {1, 5, 4, 3, 6, 2, 8, 6};
    subArraySumSln.subarraySum2(subArraySumVec, 10);

    // 连续子数组的和 https://leetcode-cn.com/problems/continuous-subarray-sum/
    CheckSubArraySumSln checkSubArraySumSln;
    vector<int> checkSubArraySumVec = {23, 2, 4, 6, 7};
    checkSubArraySumSln.checkSubarraySum(checkSubArraySumVec, 6);
    return 0;
}