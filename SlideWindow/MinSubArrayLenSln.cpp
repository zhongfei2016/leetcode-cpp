//
// leetcode-cpp
// 长度最小的子数组 https://leetcode-cn.com/problems/minimum-size-subarray-sum/
//

#include <climits>
#include "MinSubArrayLenSln.h"

int MinSubArrayLenSln::minSubArrayLen(int s, vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int left = 0;
    int right = 0;
    int minLen = INT_MAX;
    int curRes = 0;
    while (right < nums.size()) {
        // 先加一次计算一次
        if (curRes < s) {
            curRes += nums[right];
            right++;
        }
        // 如果满足，则计算一次结果，并将左值移一次直到不满足条件，再进入下一轮循环
        while (curRes >= s) {
            minLen = std::min(minLen, right - left);
            curRes -= nums[left];
            left++;
        }
    }
    if (minLen == INT_MAX) {
        return 0;
    }
    return minLen;
}