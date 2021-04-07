//
// Created by ZHONGFEI on 2021/4/7.
//

#include "MiddleNodeSln.h"

ListNode *MiddleNodeSln::middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}