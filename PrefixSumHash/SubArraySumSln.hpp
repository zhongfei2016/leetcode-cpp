//
// Created by ZHONGFEI on 2020/5/2.
//
// 前缀和Hash 和为K的子数组 https://leetcode-cn.com/problems/subarray-sum-equals-k/

#ifndef LEETCODE_CPP_SUBARRAYSUMSLN_HPP
#define LEETCODE_CPP_SUBARRAYSUMSLN_HPP

#include <unordered_map>
#include <vector>

using namespace std;

class SubArraySumSln {
public:
    int subarraySum(vector<int> &nums, int k);

    int subarraySum2(vector<int> &nums, int k);
};

// 暴力法，直接两次遍历，左边界从0-n-1，右边界从左边界到n-1
int SubArraySumSln::subarraySum(vector<int> &nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum == k) {
                count++;
            }
        }
    }
    return count;
}

int SubArraySumSln::subarraySum2(vector<int> &nums, int k) {
    unordered_map<int, int> map;
    // 求从0开始的前缀和
    int sum = 0;
    // 存放和等于k的连续子数组个数
    int count = 0;
    // map[0]表示sum第一次等于k的情况，刚开始map是空的话，就会漏统计这一次
    map[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        // 计算前缀和
        sum += nums[i];
        // 如果map中有sum-k的key，说面在当前的这个前缀和sum之前，有另一个前缀和sum'，满足sum' = sum - k
        // 那sum-sum'就等于k，那sum-sum'就是符合条件的连续子数组的和，count就可以+map中sum'当前的value
        // 如下，sum'是1,5,4,3,6，k是10，sum是1,5,4,3,6,2,8
        // |----sum----|
        // |--sum'--|  |
        // 1,5,4,3,6,2,8,6
        if (map.find(sum - k) != map.end()) {
            // 即便有sum相同的情况，由于每次sum都累加了新的值，所以sum的含义与前面与之相同的sum并不相同
            // 所以每次sum-k都对应的不是相同意义上的一个值，所以可以累加
            count += map[sum - k];
        }
        map[sum]++;
    }
    return count;
}

#endif //LEETCODE_CPP_SUBARRAYSUMSLN_HPP
