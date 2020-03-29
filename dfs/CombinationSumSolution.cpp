//
// Created by ZHONGFEI on 2020/1/5.
//
#include <algorithm>
#include "CombinationSumSolution.h"

void merge(vector<int> &nums, int start, int mid, int end) {
    vector<int> temp;
    int left = start;
    int right = mid + 1;
    while (left <= mid && right <= end) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= end) {
        temp.push_back(nums[right]);
        right++;
    }
    int cnt = start;
    for (int i = 0; i < temp.size(); i++,cnt++) {
        nums[cnt] = temp[i];
    }
}

void mergeSort(vector<int> &nums, int start, int end) {
    if (start == end) {
        return;
    }
    int mid = (start + end) >> 1;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid+1, end);
    merge(nums, start, mid, end);
}

void BackTrack(const vector<int> &candidates, vector<vector<int>> &res, vector<int> &path, int startPos, int target) {
    if (target == 0) {
        res.push_back(path);
        return;
    }

    for (int i = startPos; i < candidates.size() && target - candidates[i] >= 0; i++) {
        path.push_back(candidates[i]);
        BackTrack(candidates, res, path, i, target - candidates[i]);
        path.pop_back();
    }
}

vector<vector<int> > CombinationSumSolution::combinationSum(vector<int> &candidates, int target) {
    vector<int> tempCandidates = candidates;
    mergeSort(tempCandidates, 0, tempCandidates.size() - 1);
//    std::sort(tempCandidates.begin(), tempCandidates.end());
    vector<vector<int>> res;
    vector<int> path;
    BackTrack(tempCandidates, res, path, 0, target);
    return res;
}