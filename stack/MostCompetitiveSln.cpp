//
// Created by ZHONGFEI on 2021/2/15.
//

#include "MostCompetitiveSln.h"

#include <stack>

vector<int> MostCompetitiveSln::mostCompetitive(vector<int> &nums, int k) {
    stack<int> numStack;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        while (!numStack.empty() && numStack.top() > nums[i] && ((n - 1 - i) >= k - static_cast<int>(numStack.size()))) {
            numStack.pop();
        }
        if (numStack.size() < k) {
            numStack.push(nums[i]);
        }
    }
    vector<int> res(k,0);
    while (k > 0) {
        res[--k] = numStack.top();
        numStack.pop();
    }
    return res;
}