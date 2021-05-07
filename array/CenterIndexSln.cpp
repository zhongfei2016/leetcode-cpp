//
// leetcode-cpp
//

#include "CenterIndexSln.h"

// 前缀和，不断循环算左边和，然后总和减左边和再减去当前数就是右边和，判断左边和与右边和是否相等

int CenterIndexSln::pivotIndex(vector<int> &nums) {
    int sum = 0;
    for (int n : nums) {
        sum += n;
    }
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (leftSum == sum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}