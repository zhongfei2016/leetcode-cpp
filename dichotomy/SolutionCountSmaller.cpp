//
// Created by fei on 2019/12/21.
//
#include "SolutionCountSmaller.h"

vector<int> SolutionCountSmaller::countSmaller(vector<int> &nums) {
    vector<int> count;
    vector<pair<int, int>> vec;
    for (int i = 0; i < nums.size(); i++) {
        vec.push_back(make_pair(nums[i], i));
        count.push_back(0);
    }
    merge(vec, count);
    return count;
}

void SolutionCountSmaller::mergeTwo(vector<pair<int, int>> &sub_vec1, vector<pair<int, int>> &sub_vec2,
                                    vector<pair<int, int>> &vec, vector<int> &count) {
    int i = 0;
    int j = 0;
    while (i < sub_vec1.size() && j < sub_vec2.size()) {
        if (sub_vec1[i].first <= sub_vec2[j].first) {
            vec.push_back(sub_vec1[i]);
            // 只计算左侧，因为左侧天然符合索引小于右侧，且两边天然有序，不需要考虑左侧当前数和其他数的大小关系
            // 这时候只需判断，如果右侧小就赋值，但是要累加，因为每层都会统计，右侧大j+1，等待下一次右侧小累加
            count[sub_vec1[i].second] += j;//这句话和下面注释的地方就是这道题和归并排序的主要不同之处
            i++;
        } else {
            vec.push_back(sub_vec2[j]);
            j++;
        }
    }

    for (; i < sub_vec1.size(); ++i) {
        // 如果左侧有剩余，那都要累加j，因为左侧此时剩余的数都有j个他右侧的数比他小
        vec.push_back(sub_vec1[i]);
        count[sub_vec1[i].second] += j;// -。-
    }
    for (; j < sub_vec2.size(); ++j) {
        vec.push_back(sub_vec2[j]);
    }
}

void SolutionCountSmaller::merge(vector<pair<int, int>> &vec, vector<int> &count) {
    if (vec.size() < 2) {
        return;
    }
    int len = vec.size();
    int mid = len / 2;
    vector<pair<int, int>> subVec1;
    vector<pair<int, int>> subVec2;
    for (int i = 0; i < mid; i++) {
        subVec1.push_back(vec[i]);
    }
    for (int i = mid; i < len; i++) {
        subVec2.push_back(vec[i]);
    }
    merge(subVec1, count);
    merge(subVec2, count);
    vec.clear();
    mergeTwo(subVec1, subVec2, vec, count);
}

vector<int> SolutionCountSmaller::countSmaller2(vector<int> &nums) {
    if (nums.size() < 2) {
        return {0};
    }
    vector<pair<int, int>> num2Idxs;
    for (int i = 0; i < nums.size(); i++) {
        num2Idxs.push_back(std::make_pair(nums[i], i));
    }
    vector<int> count(nums.size(), 0);
    merge(num2Idxs, 0, nums.size() - 1, count);
    return count;
}

void SolutionCountSmaller::merge(vector<pair<int, int>> &vec, int start, int end, vector<int> &count) {
    if (start == end) {
        return;
    }
    int mid = start + ((end - start) >> 1);
    // 排序并合并左半边
    merge(vec, start, mid, count);
    // 排序并合并右半边
    merge(vec, mid + 1, end, count);
    int left = start;
    int right = mid + 1;
    int idx = 0;
    vector<pair<int, int>> temp(end - start + 1);
    while (left <= mid && right <= end) {
        // 因为此时左右两边已经有序，所以找到右边第一个比左边数大的值，右边所有比这个值小的都小于左边值
        count[vec[left].second] += vec[left].first <= vec[right].first ? right - (mid + 1) : 0;
        temp[idx++] = vec[left].first <= vec[right].first ? vec[left++] : vec[right++];
    }
    while (left <= mid) {
        // 如果左边数有剩余，说明此时右边剩余的值都比左边当前值小，直接累加
        count[vec[left].second] += right - (mid + 1);
        temp[idx++] = vec[left++];
    }
    while (right <= end) {
        temp[idx++] = vec[right++];
    }
    std::copy(temp.begin(), temp.end(), vec.begin() + start);
}