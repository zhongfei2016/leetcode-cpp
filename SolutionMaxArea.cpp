//
// Created by fei on 2019/12/22.
//

#include "SolutionMaxArea.h"

int SolutionMaxArea::maxArea(vector<int> &height) {
    if (height.size() < 2) {
        return 0;
    }
    int i = 0;
    int j = height.size() - 1;
    int minHeight = 0;
    int maxArea = 0;
    while (i < j) {
        maxArea = max(maxArea, height[i] < height[j] ? ((j - i) * height[i++]) : ((j - i) * height[j--]));
    }
    return maxArea;
}