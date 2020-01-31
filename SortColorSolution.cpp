//
// Created by ZHONGFEI on 2020/1/31.
//

#include "SortColorSolution.h"

void countFun(vector<int> &nums) {
    // 计数法，统计每种数字个数，然后直接填值
    int nums0 = 0;
    int nums1 = 0;
    int nums2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 1) {
            nums0++;
        } else if (nums[i] < 2) {
            nums1++;
        } else {
            nums2++;
        }
    }
    for (int i = 0; i < nums0; i++) {
        nums[i] = 0;
    }
    for (int i = nums0; i < nums0 + nums1; i++) {
        nums[i] = 1;
    }
    for (int i = nums0 + nums1; i < nums0 + nums1 + nums2; i++) {
        nums[i] = 2;
    }
}

void cursorFun(vector<int> &nums)
{

}

void SortColorSolution::sortColors(vector<int> &nums) {
    countFun(nums);
}