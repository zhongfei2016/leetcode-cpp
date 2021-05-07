//
// leetcode-cpp
//  下一个更大元素 II https://leetcode-cn.com/problems/next-greater-element-ii/
//

#include "NextGreatElementSln.h"

#include <stack>

vector<int> NextGreatElementSln::nextGreaterElements(vector<int> &nums) {
    vector<int> result(nums.size(), -1);
    // 单调递减的栈，遇到大的值就弹出
    stack<int> idxStack;
    for (int i = 0; i < nums.size() * 2; i++) {
        int idx = i % nums.size();
        while (!idxStack.empty() && nums[idx] > nums[idxStack.top()]) {
            result[idxStack.top()] = nums[idx];
            idxStack.pop();
        }
        idxStack.push(idx);
    }
    return result;
}