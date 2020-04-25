//
// Created by ZHONGFEI on 2020/2/1.
//

#include "MaxRecSolution.h"

#include <stack>

int maxRecMaxFun(int x, int y) {
    if (x > y) {
        return x;
    }
    return y;
}

int maxRecMinFun(int x, int y) {
    if (x < y) {
        return x;
    }
    return y;
}

int MaxRecSolution::maximalRectangle(vector<vector<char>> &matrix) {
    // 存最大面积
    int maxArea = 0;
    if (matrix.empty()) {
        return maxArea;
    }
    // 存matrix中每一个元素的最大宽度（存当前元素到左边的最大宽度）
    vector<vector<int>> widths(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == '1') {
                if (j == 0) {
                    // 在当前行的左边界，所以宽度只能为1
                    widths[i][j] = 1;
                } else {
                    // 宽度是前一个元素的宽度+1
                    widths[i][j] = widths[i][j - 1] + 1;
                }
            } else {
                // 当前元素是0，所以最大宽度就是0
                widths[i][j] = 0;
            }
            // 遍历当前元素上面的每一行当前列的元素（每一个元素代表他所代表的最大宽度）
            int minWidth = widths[i][j];
            for (int k = i; k >= 0; k--) {
                int height = i - k + 1;
                minWidth = maxRecMinFun(minWidth, widths[k][j]);
                maxArea = maxRecMaxFun(maxArea, minWidth * height);
            }
        }
    }
    return maxArea;
}

// 参考这个https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
int largestRectangleArea(vector<int> heights) {
    int maxArea = 0;
    stack<int> stack;
    int p = 0;
    while (p < heights.size()) {
        //栈空入栈
        if (stack.empty()) {
            stack.push(p);
            p++;
        } else {
            int top = stack.top();
            //当前高度大于栈顶，入栈
            if (heights[p] >= heights[top]) {
                stack.push(p);
                p++;
            } else {
                //保存栈顶高度
                int height = heights[stack.top()];
                stack.pop();
                //左边第一个小于当前柱子的下标
                int leftLessMin = stack.empty() ? -1 : stack.top();
                //右边第一个小于当前柱子的下标
                int RightLessMin = p;
                //计算面积
                int area = (RightLessMin - leftLessMin - 1) * height;
                maxArea = maxRecMaxFun(area, maxArea);
            }
        }
    }
    while (!stack.empty()) {
        //保存栈顶高度
        int height = heights[stack.top()];
        stack.pop();
        //左边第一个小于当前柱子的下标
        int leftLessMin = stack.empty() ? -1 : stack.top();
        //右边没有小于当前高度的柱子，所以赋值为数组的长度便于计算
        int RightLessMin = heights.size();
        int area = (RightLessMin - leftLessMin - 1) * height;
        maxArea = maxRecMaxFun(area, maxArea);
    }
    return maxArea;
}

int MaxRecSolution::maximalRectangle2(vector<vector<char>> &matrix) {
    if (matrix.empty()) return 0;
    vector<int> height(matrix[0].size(), 0);
    int maxRect = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < height.size(); ++j) {
            if (matrix[i][j] == '0') { height[j] = 0; }
            else { ++height[j]; }
        }
        maxRect = max(maxRect, largestRectangleArea(height));
        height.pop_back();
    }
    return maxRect;
}

int MaxRecSolution::largestRectangleArea(vector<int> &heights) {
    int maxArea = 0;
    stack<int> idxStack;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++) {
        while (!idxStack.empty() && heights[idxStack.top()] >= heights[i]) {
            int h = heights[idxStack.top()];
            idxStack.pop();
            int leftSideIdx = idxStack.empty() ? -1 : idxStack.top();
            maxArea = max(maxArea, h * (i - leftSideIdx - 1));
        }
        idxStack.push(i);
    }
    return maxArea;
}
