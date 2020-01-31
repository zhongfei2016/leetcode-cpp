//
// Created by ZHONGFEI on 2020/1/1.
//

#ifndef LEETCODE_MERGEKLISTSSOLUTION_H
#define LEETCODE_MERGEKLISTSSOLUTION_H

#include <cstring>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 *
 */
struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
     };

class MergeKListsSolution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists);
};


#endif //LEETCODE_MERGEKLISTSSOLUTION_H
