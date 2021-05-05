//
// Created by ZHONGFEI on 2021/5/5.
// 必须先严格单调增再严格单调减，才算有效山峰

#include "ValidMountainSln.h"

bool ValidMountainSln::validMountainArray(vector<int> &arr) {
    int size = arr.size();
    int i = 0;
    while (i + 1 < size && arr[i] < arr[i + 1]) {
        i++;
    }
    if (i == 0 || i == size - 1) {
        return false;
    }
    while (i + 1 < size && arr[i] > arr[i + 1]) {
        i++;
    }
    return i == size - 1;
}