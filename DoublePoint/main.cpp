//
// Created by ZHONGFEI on 2021/3/26.
//
#include "SortColorSolution.h"
#include "SolutionMaxArea.h"
#include "SolutionThreeSum.h"
int main() {
// 盛水最多的容器 https://leetcode-cn.com/problems/container-with-most-water/
    SolutionMaxArea ma;
    vector<int> maVec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int maxArea = ma.maxArea(maVec);

    // 三数之和 https://leetcode-cn.com/problems/3sum/
    SolutionThreeSum ts;
    vector<int> numsTs = {0, 0, 0};
    ts.threeSum(numsTs);

    // 颜色分类 https://leetcode-cn.com/problems/sort-colors/
    SortColorSolution sortColorSln;
    vector<int> sortColorVec = {2, 2, 1, 0, 0, 1, 2, 2};
    sortColorSln.sortColors(sortColorVec);
    return 0;
}