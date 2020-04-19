//
// Created by ZHONGFEI on 2020/4/12.
//

#include "DominantIndexSln.h"
#include <algorithm>

static bool Sort(pair<int, int> &n1, pair<int, int> &n2) {
    return n1.first < n2.first;
}

int DominantIndexSln::dominantIndex(vector<int> &nums) {
    if (nums.size() == 0)
        return -1;
    if (nums.size() == 1)
        return 0;
    int size = nums.size();
    vector<pair<int, int>> idxNums(size);
    for (int i = 0; i < nums.size(); i++) {
        idxNums[i].first = nums[i];
        idxNums[i].second = i;
    }
    sort(idxNums.begin(), idxNums.end(), Sort);
    if (idxNums[size - 1].first >= 2 * idxNums[size - 2].first) {
        return idxNums[size - 1].second;
    }
    return -1;
}