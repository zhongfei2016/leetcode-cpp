//
// leetcode-cpp
// 必须先严格单调增再严格单调减，才算有效山峰

#include "ValidMountainSln.h"

bool ValidMountainSln::validMountainArray(vector<int> &arr) {
    int size = arr.size();
    int i = 0;
    // size至少是3，否则没法构成山峰
    while (i + 1 < size && arr[i] < arr[i + 1]) {
        i++;
    }
    // 如果刚开始就是递减，或者一直递增到最后，都不行
    if (i == 0 || i == size - 1) {
        return false;
    }
    while (i + 1 < size && arr[i] > arr[i + 1]) {
        i++;
    }
    // 只有递减到最后才算合法山峰数组
    return i == size - 1;
}