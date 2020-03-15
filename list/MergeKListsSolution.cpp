//
// Created by ZHONGFEI on 2020/1/1.
//

#include "MergeKListsSolution.h"

ListNode* MergeTwoList(ListNode *p1, ListNode *p2) {
    ListNode * head = new ListNode(0);
    ListNode * p = head;
    while (p1 && p2){
        if(p1->val< p2->val){
            p->next = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p2 = p2->next;
        }
        p=p->next;
    }
    while (p1){
        p->next = p1;
        p1 = p1->next;
        p=p->next;
    }
    while (p2){
        p->next = p2;
        p2 = p2->next;
        p = p->next;
    }
    return head->next;
}

ListNode *MergeKListsSolution::mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) {
        return NULL;
    }
    if (lists.size() == 1) {
        return lists[0];
    }
    ListNode *p = lists[0];
    for (int i = 1; i < lists.size(); i++) {
        p = MergeTwoList(p, lists[i]);
    }
    return p;
}