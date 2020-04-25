//
// Created by ZHONGFEI on 2020/1/29.
//

#include "TrapSolution.h"
#include <stack>

int TrapSolution::trap(vector<int> &height) {
    // 用于存索引
    stack<int> st;
    int current = 0, ans = 0;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int curTop = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }
            int len = current - st.top() - 1;
            int hei = min(height[current], height[st.top()]) - height[curTop];
            ans += len * hei;
        }
        st.push(current++);
    }
    return ans;
}

int TrapSolution::trap2(vector<int> &height) {
    // 存索引，维持一个单调递减的栈
    stack<int> idxStack;
    int volume = 0;
    for (int i = 0; i < height.size(); i++) {
        // 索引stack不为空且当前height大于之前的height
        while (!idxStack.empty() && height[idxStack.top()] < height[i]) {
            // 弹出栈顶开始向前遍历计算
            int topIdx = idxStack.top();
            idxStack.pop();
            if (idxStack.empty()) {
                break;
            }
            int distance = i - idxStack.top() - 1;
            volume += distance * (min(height[i], height[idxStack.top()]) - height[topIdx]);
        }
        idxStack.push(i);
    }
    return volume;
}