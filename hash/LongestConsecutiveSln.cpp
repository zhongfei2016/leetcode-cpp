//
// Created by ZHONGFEI on 2020/3/8.
//

#include "LongestConsecutiveSln.h"
#include <unordered_set>
int LongestConsecutiveSln::longestConsecutive(vector<int>& nums)
{
    // 将所有数字放入set去重
    unordered_set<int> numsSet;
    int maxLen = 1;
    numsSet.insert(nums.begin(), nums.end());
    //set的size小于2时直接返回set的大小，其他情况最少长度也是1
    if (numsSet.size() < 2) {
        return numsSet.size();
    }
    // 找连续序列中最小位置的数开始统计，避免找到中间或者最大位置的数有重复统计的情况
    // 比如当前是num，如果找到比他小1的数，就继续遍历set的下一个，直到找到一个没有比他小1的数字，再开始统计
    for (int num : numsSet) {
        if(numsSet.find(num - 1) != numsSet.end()) {
            continue;
        }
        int curMaxLen = 1;
        // 找到比num大1的数字，len就+1，num也+1，并计算当前最大len，直到找不到再找下一个数字
        while (numsSet.find(num+1) != numsSet.end()) {
            curMaxLen ++;
            num ++;
            maxLen = max(curMaxLen, maxLen);
        }
    }
    return maxLen;
}