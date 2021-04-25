//
// Created by ZHONGFEI on 2021/2/13.
// https://leetcode-cn.com/problems/create-maximum-number/
//

#include "MaxNumSln.h"

bool compare(vector<int> vec1, int idx1, vector<int> vec2, int idx2) {
    while (idx1 < vec1.size() && idx2 < vec2.size()) {
        int res = vec1[idx1] - vec2[idx2];
        if (res != 0) {
            return res > 0;
        }
        idx1++;
        idx2++;
    }
    if (idx1 == vec1.size()) {
        return false;
    }
    return true;
}

vector<int> merge(vector<int> vec1, vector<int> vec2) {
    int size1 = vec1.size();
    int size2 = vec2.size();
    if (size1 == 0) {
        return vec2;
    }
    if (size2 == 0) {
        return vec1;
    }
    vector<int> res(size1 + size2, 0);
    int i = 0;
    int idx1 = 0;
    int idx2 = 0;
    while (i < (size1 + size2)) {
        int bRes = compare(vec1, idx1, vec2, idx2);
        if (bRes) {
            res[i++] = vec1[idx1++];
        } else {
            res[i++] = vec2[idx2++];
        }
    }
    return res;
}


vector<int> findMaxNums(vector<int> nums, int k) {
    vector<int> res;
    // 表示可以丢弃消耗的数字个数
    int remains = nums.size() - k;
    for (int i = 0; i < nums.size(); i++) {
        while (remains > 0 && res.size() > 0 && res.back() < nums[i]) {
            // 从结果里弹出丢弃，可丢弃数减1
            res.pop_back();
            remains--;
        }
        if (res.size() < k) {
            res.push_back(nums[i]);
        } else {
            // 未加入结果集，自动丢弃，可丢弃数也减1
            remains--;
        }
    }
    return res;
}

vector<int> MaxNumSln::maxNumber(vector<int> nums1, vector<int> nums2, int k) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    vector<int> result;
    for (int i = 0; i <= size1; i++) {
        if (i > k) {
            break;
        }
        if (k - i > size2) {
            continue;
        }
        vector<int> vec1 = findMaxNums(nums1, i);
        vector<int> vec2 = findMaxNums(nums2, k - i);
        vector<int> res = merge(vec1, vec2);
        result = max(res, result);
    }
    return result;
}