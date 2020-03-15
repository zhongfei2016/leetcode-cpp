//
// Created by ZHONGFEI on 2020/3/15.
//

#include "HasCycleSln.h"

using namespace std;

bool HasCycleSln::hasCycle(struct ListNode * head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    // 设置一个慢者（一次走一步）一个快者（一次走两步）
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            //fast和slow不等且fast下一步就要结束时，说明没有环形，否则fast和slow一定可以相遇
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}