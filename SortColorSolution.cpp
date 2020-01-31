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

void sortColorSwap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void cursorFun(vector<int> &nums) {
    // 双指针法，从左右两边向中间靠近，p1指向0的右边界，p2指向2的左边界，1就会天然在中间
    int p1 = 0;
    int p2 = nums.size() - 1;
    // 当前索引，向p2靠近
    int cur = 0;
    while (cur <= p2) {
        if (nums[cur] == 0) {
            // 遇到0就将cur和p1对应的值调换，0的右边界右移
            // cur此时肯定是换成了他左边或者他自己的值，所以cur对应的值肯定大于等于0且小于2，所以可以右移
            sortColorSwap(&(nums[cur++]), &(nums[p1++]));
        } else if (nums[cur] == 2) {
            // 遇到2就将cur和p2对应的值调换，2的左边界左移
            // cur不能动，因为此时cur变成了从右边换过来的值，不确定是几，需要下一轮再判断一次才能移动
            sortColorSwap(&(nums[cur]), &(nums[p2--]));
        } else {
            // 如果是1直接右移不用考虑
            cur++;
        }
    }
}

void SortColorSolution::sortColors(vector<int> &nums) {
//    countFun(nums);
    cursorFun(nums);
}