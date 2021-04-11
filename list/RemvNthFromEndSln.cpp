//
// Created by ZHONGFEI on 2021/4/11.
//

#include "RemvNthFromEndSln.h"

ListNode *RemvNthFromEndSln::removeNthFromEnd(ListNode *head, int n) {
    ListNode *virtualNode = new ListNode(0);
    // 构建一个虚拟节点，方便删除头结点时，返回null
    virtualNode->next = head;
    ListNode *slow = virtualNode;
    ListNode *fast = virtualNode;
    int diff = 0;// 快慢节点差
    while (fast != nullptr) {
        fast = fast->next;
        diff++;
        if (diff > n + 1) {// 大于n+1，保证fast变为null时，slow是倒数n+1个点，方便删掉倒数第n个点
            slow = slow->next;
            diff--;
        }
    }
    slow->next = slow->next->next;
    ListNode *validNode = virtualNode->next;
    delete virtualNode;// 申请的内存要释放
    return validNode;
}
