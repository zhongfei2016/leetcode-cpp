//
// Created by ZHONGFEI on 2020/1/29.
//

#include "TrapSolution.h"
#include <stack>

int TrapSolution::trap(vector<int> &height) {
    // 用于存索引
    stack<int> st;
    int current = 0,  ans = 0;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int curTop = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }
            int len = current - st.top() - 1;
            int hei = min(height[current],height[st.top()]) - height[curTop];
            ans += len * hei;
        }
        st.push(current++);
    }
    return ans;
}