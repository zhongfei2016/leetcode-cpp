//
// Created by ZHONGFEI on 2021/4/4.
//

#ifndef LEETCODE_CPP_SORTARRAYTOBSTSLN_H
#define LEETCODE_CPP_SORTARRAYTOBSTSLN_H

#include <vector>
#include <Common.h>

class SortArrayToBSTSln {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums);

private:
    TreeNode * BuildBST(vector<int>& nums, int left, int right);
};


#endif //LEETCODE_CPP_SORTARRAYTOBSTSLN_H
