class RotateListNodeSln {
public:
    ListNode *rotateRight(ListNode *head, int k);
};

// 1->2->3->4->5 -----> 3->4->5->1->2
ListNode *RotateListNodeSln::rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *p = head;
    // 第一次遍历算一下链表个数
    int n = 1;
    while (p->next != nullptr) {
        n++;
        p = p->next;
    }
    // 将链表首尾相接
    p->next = head;
    // 为避免越界除以n取余，此时得到的k是有效的翻转个数
    k = k % n;
    // 新尾部的索引
    int newTailIdx = n - k - 1;
    // 重新从head开始，拿到新的tail和head
    ListNode *newTail = head;
    for (int i = 0; i < newTailIdx; i++) {
        newTail = newTail->next;
    }
    ListNode *newHead = newTail->next;
    // 在新的tail处打断
    newTail->next = nullptr;
    return newHead;
}