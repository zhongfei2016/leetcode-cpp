//
// Created by ZHONGFEI on 2020/1/1.
//
// 合并 k 个排序链表，返回合并后的排序链表  https://leetcode-cn.com/problems/merge-k-sorted-lists/

#ifndef LEETCODE_MERGEKLISTSSOLUTION_H
#define LEETCODE_MERGEKLISTSSOLUTION_H

#include <cstring>
#include <vector>
#include "ListCommon.h"

using namespace std;

/**
 * Definition for singly-linked list.
 *
 */

class MergeKListsSolution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists);
};


#endif //LEETCODE_MERGEKLISTSSOLUTION_H
