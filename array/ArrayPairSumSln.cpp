//
// leetcode-cpp
//

#include "ArrayPairSumSln.h"

#include <algorithm>

int arrayPairSum(vector<int> &nums) {
    int size = nums.size();
    int odd = size % 2;
    sort(nums.begin(), nums.end());
    int result = 0;
    for (int i = 0; i < size; i += 2) {
        result += nums[i];
    }
    if (odd == 1) {
        result += nums[size - 1];
    }
    return result;
}