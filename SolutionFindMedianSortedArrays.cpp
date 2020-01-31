//
// Created by fei on 2019/12/22.
//

#include "SolutionFindMedianSortedArrays.h"

void SolutionFindMedianSortedArrays::mergeVec(vector<int> &vec, int left, int mid, int right) {
    int pLeft = left;
    int pRight = mid + 1;
    vector<int> temp;
    while (pLeft <= mid && pRight <= right) {
        temp.push_back(vec[pLeft] < vec[pRight] ? vec[pLeft++] : vec[pRight++]);
    }
    while (pLeft <= mid) {
        temp.push_back(vec[pLeft++]);
    }

    while (pRight <= right) {
        temp.push_back(vec[pRight++]);
    }
    for (int i = left, cnt = 0; cnt < temp.size(); i++, cnt++) {
        vec[i] = temp[cnt];
    }
}

void SolutionFindMedianSortedArrays::merge(vector<int> &vec, int left, int right) {
    if (right == left) {
        return;
    }
    int mid = left + ((right - left) >> 1);
    merge(vec, left, mid);
    merge(vec, mid + 1, right);
    mergeVec(vec, left, mid, right);
}

double SolutionFindMedianSortedArrays::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> temp;
    double res = 0.0;
    temp.insert(temp.end(), nums1.begin(), nums1.end());
    temp.insert(temp.end(), nums2.begin(), nums2.end());
    int size = temp.size();

    merge(temp, 0, size - 1);
    if (temp.size() % 2 == 0) {
        int mid = temp.size() / 2;
        res = (temp[mid - 1] + temp[mid]) / 2.0;
    } else {
        int mid = temp.size() / 2;
        res = temp[mid];
    }
    return res;
}
