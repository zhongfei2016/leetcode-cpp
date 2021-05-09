//
// leetcode-cpp
//

#include "DominantIndexSln.h"
#include <algorithm>

static bool Sort(pair<int, int> &n1, pair<int, int> &n2) {
    return n1.first < n2.first;
}

// 求最大数至少是其他数字的两倍
int DominantIndexSln::dominantIndex(vector<int> &nums) {
    if (nums.size() == 0)
        return -1;
    if (nums.size() == 1)
        return 0;
    int size = nums.size();
    vector<pair<int, int>> idxNums(size);
    // 记一下索引和对应值
    for (int i = 0; i < nums.size(); i++) {
        idxNums[i].first = nums[i];
        idxNums[i].second = i;
    }
    // 排序，然后最大的大于次大的两倍，就表示符合条件
    sort(idxNums.begin(), idxNums.end(), Sort);
    if (idxNums[size - 1].first >= 2 * idxNums[size - 2].first) {
        return idxNums[size - 1].second;
    }
    return -1;
}