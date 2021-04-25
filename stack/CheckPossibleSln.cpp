//
// Created by ZHONGFEI on 2021/4/24.
// 非递减数列 https://leetcode-cn.com/problems/non-decreasing-array/

#include <stack>
#include "CheckPossibleSln.h"

// 正向去掉最多一个是否非严格递增
bool CheckPossibleSln::forwardCheck(vector<int> &nums) {
    stack<int> stk;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        while (!stk.empty() && i < nums.size() && stk.top() > nums[i]) {
            i++;
            count++;
            if (count > 1) {
                return false;
            }
        }
        if (i < nums.size()) {
            stk.push(nums[i]);
        }
    }
    return true;
}

// 负向去掉最多一个是否非严格递减
bool CheckPossibleSln::backwardCheck(vector<int> &nums) {
    stack<int> stk;
    int count = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!stk.empty() && i >= 0 && stk.top() < nums[i]) {
            i--;
            count++;
            if (count > 1) {
                return false;
            }
        }
        if (i >= 0) {
            stk.push(nums[i]);
        }
    }
    return true;
}

bool CheckPossibleSln::checkPossibility(vector<int> &nums) {
    bool res = forwardCheck(nums) || backwardCheck(nums);
    return res;
}