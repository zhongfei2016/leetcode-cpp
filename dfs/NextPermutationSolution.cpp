//
// Created by ZHONGFEI on 2020/1/1.
//

#include "NextPermutationSolution.h"

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 数组翻转
 * @param vec
 */
void reverse(vector<int> &vec) {
    if (vec.size() <= 1) {
        return;
    }
    // 两边元素一边互换一边向中间靠拢
    for (int i = 0, j = vec.size() - 1; i < j; i++, j--) {
        swap(&vec[i], &vec[j]);
    }
}

void NextPermutationSolution::nextPermutation(vector<int> &nums) {
    if (nums.size() <= 1) {
        return;
    }
    int k = -1;
    int l = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        // 从前往后找，前小于后就记录下前的索引k
        if (nums[i] < nums[i + 1]) {
            k = i;
        }
        // 找不到k说明前总大于等于后，直接翻转即可
        if(k==-1){
            continue;
        }
        // 找到第一个比nums[k]大的值得索引
        if (nums[i] > nums[k]) {
            l = i;
        }
    }
    if (k == -1) {
        reverse(nums);
        return;
    }
    //总能找到，最大l索引是size-1
    if (nums[nums.size() - 1] > nums[k]) {
        l = nums.size() - 1;
    }
    swap(&nums[k], &nums[l]);
    if (k + 1 == nums.size() - 1) {
        return;
    }
    // 如果l不是size-1，就翻转k后面的所有元素
    for (int i = k + 1, j = nums.size() - 1; i < j; i++, j--) {
        swap(&nums[i], &nums[j]);
    }
}