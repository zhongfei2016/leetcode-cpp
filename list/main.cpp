//
// Created by ZHONGFEI on 2021/3/26.
//
#include "MergeKListsSolution.h"
#include "HasCycleSln.h"
#include "RotateListNodeSln.hpp"
#include "ReverseListSln.hpp"

int main() {
    // 合并 k 个排序链表，返回合并后的排序链表  https://leetcode-cn.com/problems/merge-k-sorted-lists/
    MergeKListsSolution *mkls = new MergeKListsSolution();
    ListNode *ln1 = new ListNode(1);
    ln1->next = new ListNode(4);
    ln1->next->next = new ListNode(5);
    ListNode *ln2 = new ListNode(1);
    ln2->next = new ListNode(3);
    ln2->next->next = new ListNode(4);
    vector<ListNode *> lns;
    lns.push_back(ln1);
    lns.push_back(ln2);
    mkls->mergeKLists(lns);
    delete[] mkls;

    // 环形链表 https://leetcode-cn.com/problems/linked-list-cycle/
    HasCycleSln hasCycleSln;
    ListNode *hasCycleNode1 = new ListNode(3);
    ListNode *hasCycleNode2 = new ListNode(2);
    ListNode *hasCycleNode3 = new ListNode(0);
    ListNode *hasCycleNode4 = new ListNode(-4);
    hasCycleNode1->next = hasCycleNode2;
    hasCycleNode2->next = hasCycleNode3;
    hasCycleNode3->next = hasCycleNode4;
    hasCycleNode4->next = hasCycleNode2;
    hasCycleSln.hasCycle(hasCycleNode1);

    // 旋转链表
    RotateListNodeSln rotateListNodeSln;
    ListNode rotateListNode1(1);
    ListNode rotateListNode2(2);
    ListNode rotateListNode3(3);
    ListNode rotateListNode4(4);
    ListNode rotateListNode5(5);
    rotateListNode1.next = &rotateListNode2;
    rotateListNode2.next = &rotateListNode3;
    rotateListNode3.next = &rotateListNode4;
    rotateListNode4.next = &rotateListNode5;
    rotateListNodeSln.rotateRight(&rotateListNode1, 3);

    // 翻转链表
    ReverseListSln reverseListSln;
    ListNode reverseListNode1(1);
    ListNode reverseListNode2(2);
    ListNode reverseListNode3(3);
    ListNode reverseListNode4(4);
    ListNode reverseListNode5(5);
    reverseListNode1.next = &reverseListNode2;
    reverseListNode2.next = &reverseListNode3;
    reverseListNode3.next = &reverseListNode4;
    reverseListNode4.next = &reverseListNode5;
    reverseListSln.reverseList(&reverseListNode1);
    return 0;
}