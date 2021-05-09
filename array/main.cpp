//
// leetcode-cpp
//

#include "CenterIndexSln.h"
#include "DominantIndexSln.h"
#include "RemoveElementSln.h"
#include "PlusOneSln.h"
#include "RotateSln.hpp"
#include "MergeIntervalSolution.h"
#include "RotateSolution.h"


int main()
{
    // 旋转图像 https://leetcode-cn.com/problems/rotate-image/
    RotateSolution rotateSln;
    vector<vector<int>> rotateVec;
    vector<vector<int>> rotateVecReverse;
    vector<int> rotateVec1 = {1, 2, 3};
    vector<int> rotateVec2 = {4, 5, 6};
    vector<int> rotateVec3 = {7, 8, 9};
    rotateVec.push_back(rotateVec1);
    rotateVec.push_back(rotateVec2);
    rotateVec.push_back(rotateVec3);
    rotateVecReverse = rotateVec;
    rotateSln.rotate(rotateVec);
    rotateSln.rotate2(rotateVecReverse);

    // 合并区间 https://leetcode-cn.com/problems/merge-intervals/
    MergeIntervalSolution *mergeIntervalSln = new MergeIntervalSolution();
    vector<vector<int>> mergeIntervalVec;
    vector<int> mergeIntervalVec1 = {1, 3};
    vector<int> mergeIntervalVec2 = {2, 6};
    vector<int> mergeIntervalVec3 = {8, 11};
    mergeIntervalVec.push_back(mergeIntervalVec1);
    mergeIntervalVec.push_back(mergeIntervalVec2);
    mergeIntervalVec.push_back(mergeIntervalVec3);
    mergeIntervalSln->merge(mergeIntervalVec);
    delete[] mergeIntervalSln;

    // 寻找中位数 https://leetcode-cn.com/problems/find-pivot-index/
    CenterIndexSln centerIndexSln;
    vector<int> pivotIndexVec = {1, 2, 3};
    centerIndexSln.pivotIndex(pivotIndexVec);

    // 至少是其他数字两倍的最大数 https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/
    DominantIndexSln dominantIndexSln;
    vector<int> dominantIndexVec = {0, 0, 2, 3};
    dominantIndexSln.dominantIndex(dominantIndexVec);

    // 加一 https://leetcode-cn.com/problems/plus-one/
    PlusOneSln plusOneSln;
    vector<int> plusOneVec = {9, 9};
    plusOneSln.plusOne(plusOneVec);

    // 使用快慢双指针移除指定元素
    RemoveElementSln removeElementSln;
    vector<int> rmEleVec = {6, 1, 4, 5, 7, 6, 2, 6};
    removeElementSln.removeElement(rmEleVec, 6);

    // 旋转数组 https://leetcode-cn.com/problems/rotate-array/
    RotateSln rotateArrSln;
    vector<int> rotateArrVec = {1, 2, 3, 4, 5, 6, 7};
    rotateArrSln.rotate(rotateArrVec, 3);

    MergeIntervalSolution mergeIntervalSolution;
    vector<vector<int>> removeIntervals = {{1,4},{3,6},{2,8}};
    mergeIntervalSolution.removeCoveredIntervals(removeIntervals);
    vector<vector<int>> removeIntervals2 = {{1,2},{1,4},{3,4}};
    mergeIntervalSolution.removeCoveredIntervals(removeIntervals2);
    return 0;
}