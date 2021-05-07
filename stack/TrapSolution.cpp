//
// leetcode-cpp
//

#include "TrapSolution.h"
#include <stack>
#include <cmath>

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

/**
 * 双指针解法
 * @param height
 * @return
 */
int TrapSolution::trap3(vector<int> &height) {
    //特殊情况1
    if (height.size() < 3) return 0;
    int l = 0, r = height.size() - 1;
    // 找到左右第一个不为0的边界
    while (height[l] == 0) ++l;
    while (height[r] == 0) --r;
    //特殊情况2
    if (abs(l - r) <= 1) return 0;

    //general case
    int lastH = min(height[l], height[r]);
    int ans = (r - l - 1) * lastH;
    while (l <= r) {
        if (height[l] <= height[r]) {
            ++l;
            if (l == r) break;
            ans -= height[l] > lastH ? lastH : height[l];
        } else {
            --r;
            if (l == r) break;
            ans -= height[r] > lastH ? lastH : height[r];
        }
        int currentH = min(height[l], height[r]);
        if (currentH > lastH) {
            ans += (r - l - 1) * (currentH - lastH);
            lastH = currentH;
        }
    }
    return ans;
}