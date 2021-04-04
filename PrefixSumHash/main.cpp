//
// Created by ZHONGFEI on 2021/3/26.
//
#include "SubArraySumSln.hpp"
#include "CheckSubArraySumSln.hpp"
#include "PathSumIIISln.h"
#include <vector>
using namespace std;

int main() {
    // 前缀和Hash 和为K的子数组 https://leetcode-cn.com/problems/subarray-sum-equals-k/
    SubArraySumSln subArraySumSln;
    vector<int> subArraySumVec = {1, 5, 4, 3, 6, 2, 8, 6};
    subArraySumSln.subarraySum2(subArraySumVec, 10);

    // 连续子数组的和 https://leetcode-cn.com/problems/continuous-subarray-sum/
    CheckSubArraySumSln checkSubArraySumSln;
    vector<int> checkSubArraySumVec = {23, 2, 4, 6, 7};
    checkSubArraySumSln.checkSubarraySum(checkSubArraySumVec, 6);

    TreeNode treeNode(10);
    TreeNode treeNodeL(5);
    TreeNode treeNodeR(-3);
    TreeNode treeNodeLL(3);
    TreeNode treeNodeLLL(3);
    TreeNode treeNodeLLR(-2);
    TreeNode treeNodeLR(2);
    TreeNode treeNodeLRR(1);
    TreeNode treeNodeRR(11);
    treeNode.left = &treeNodeL;
    treeNode.right = &treeNodeR;
    treeNodeL.left = &treeNodeLL;
    treeNodeL.right = &treeNodeLR;
    treeNodeLL.left = &treeNodeLLL;
    treeNodeLL.right = &treeNodeLLR;
    treeNodeLR.right = &treeNodeLRR;
    treeNodeR.right = &treeNodeRR;
    PathSumIIISln pathSumIiiSln;
    int pathSum1 = pathSumIiiSln.pathSum(&treeNode, 8);
    int pathSum2 = pathSumIiiSln.pathSum2(&treeNode, 8);
    return 0;
}