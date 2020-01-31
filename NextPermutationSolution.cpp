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

void reverse(vector<int> &vec) {
    if (vec.size() <= 1) {
        return;
    }
    for (int i = 0, j = vec.size() - 1; i < j; i++, j--) {
        swap(&vec[i], &vec[j]);
    }
}

void NextPermutationSolution::nextPermutation(vector<int> &nums) {
    if (nums.size() <= 1) {
        return;
    }
    int temp = nums[0];
    int k = -1;
    int l = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] < nums[i + 1]) {
            k = i;
        }
        if(k==-1){
            continue;
        }
        if (nums[i] > nums[k]) {
            l = i;
        }
    }
    if (k == -1) {
        reverse(nums);
        return;
    }
    if (nums[nums.size() - 1] > nums[k]) {
        l = nums.size() - 1;
    }
    swap(&nums[k], &nums[l]);
    if (k + 1 == nums.size() - 1) {
        return;
    }
    for (int i = k + 1, j = nums.size() - 1; i < j; i++, j--) {
        swap(&nums[i], &nums[j]);
    }
}