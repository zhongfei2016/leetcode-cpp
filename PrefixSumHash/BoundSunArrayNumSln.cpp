//
// leetcode-cpp
//

#include "BoundSunArrayNumSln.h"

int BoundSunArrayNumSln::countSubArrayNum(vector<int> &A, int maxNum) {
    int count = 0;
    int result = 0;
    for (auto a : A) {
        if (a <= maxNum) {
            count++;
        } else {
            count = 0;
        }
        result += count;
    }
    return result;
}

// 求连续、非空且其中最大元素满足大于等于L 小于等于R的子数组个数。
// 这里的连续，是说子数组的数字在原数组的位置是连续的，并不是大小是连续的
int BoundSunArrayNumSln::numSubarrayBoundedMax(vector<int> &A, int L, int R) {
    if (A.size() == 0) { return 0; }
    int result = countSubArrayNum(A, R) - countSubArrayNum(A, L - 1);
    return result;
}
