//
// Created by ZHONGFEI on 2021/1/24.
//

#include "FindLenOfLCISSln.h"

#include <stack>

int FindLenOfLCISSln::findLengthOfLCIS(vector<int> &nums) {
    int maxLen = 0;
    vector<int> idxStack;
    for (int i = 0; i < nums.size(); i++) {
        if (!idxStack.empty() && nums[i] <= nums[idxStack.back()]) {
            maxLen = max(maxLen, (int) idxStack.size());
            idxStack.clear();
        }
        idxStack.push_back(i);
    }
    maxLen = max(maxLen, (int) idxStack.size());
    return maxLen;
}
