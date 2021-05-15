//
// leetcode-cpp
//
#include "SolutionCountSmaller.h"
#include "SearchSolution.h"
#include "SearchRangeSolution.h"
#include "SearchMatrixSln.hpp"
#include "SolutionFindMedianSortedArrays.h"
#include "SnowMountainSln.h"
#include "ReversePairSln.h"
#include "FindInMountainArraySln.h"

int main() {
// 计算右侧小于当前元素的个数 https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
    std::vector<int> nums = {5, 3, 6, 1};
    SolutionCountSmaller cs;
    vector<int> calNums = cs.countSmaller(nums);
    for (int i = 0; i < calNums.size(); i++) {
        cout << calNums[i] << endl;
    }
    nums = {5, 3, 6, 1};
    calNums = cs.countSmaller2(nums);

    // 两数组中位数 https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
    std::vector<int> nums1 = {5, 3, 6, 1};
    std::vector<int> nums2 = {2, 4};
    SolutionFindMedianSortedArrays fmsa;
    double fmsaRes = fmsa.findMedianSortedArrays(nums1, nums2);
    double fmsaRes2 = fmsa.findMedianSortedArrays2(nums1, nums2);
    cout << fmsaRes << "," << fmsaRes2 << endl;

    //搜索旋转排序数组 https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
    SearchSolution ss;
    vector<int> ssVec = {4, 5, 6, 7, 1, 2};
    ss.search(ssVec, 1);

    // 在排序数组中查找元素的第一个和最后一个位置 https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    SearchRangeSolution srs;
    vector<int> srsVec = {4, 5, 6, 7, 7, 2};
    srs.searchRange(srsVec, 7);

    SearchMatrixSln searchMatrixSln;
    vector<vector<int>> searchMatrixVec = {{1,  4,  7,  11, 15},
                                           {2,  5,  8,  12, 19},
                                           {3,  6,  9,  16, 22},
                                           {10, 13, 14, 17, 24},
                                           {18, 21, 23, 26, 30}
    };
    searchMatrixSln.searchMatrix(searchMatrixVec, 5);

    SnowMountainSln snowMountainSln;
//    int mountainCost = snowMountainSln.snowMountainCost({5,1,4,3,8},3);
    int mountainCost = snowMountainSln.snowMountainCost({1, 2, 99999, 3, 100000}, 3);

    ReversePairSln reversePairSln;
    vector<int> reversePairVec = {7, 5, 6, 4};
    int reverseNum = reversePairSln.reversePairs(reversePairVec);
    vector<int> reversePairVec3 = {7, 5, 6, 4};
    int reverseNum3 = reversePairSln.reversePairs3(reversePairVec3);

    FindInMountainArraySln findInMountainArraySln;
    MountainArray mountainArray({1, 5,2});
    findInMountainArraySln.findInMountainArray(2, mountainArray);
    return 0;
}