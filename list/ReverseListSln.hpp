class ReverseListSln {
public:
    ListNode *reverseList(ListNode *head);
};
//  默认NULL
ListNode *ReverseListSln::reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // pre是虚拟的前一个node，cur是当前node
    ListNode *newHead = nullptr, *cur = head;
    while (cur != nullptr) {
        // 将cur->next暂存
        ListNode *temp = cur->next;
        // 将cur的next指向前面的node，即pre
        cur->next = newHead;
        // 再将cur赋给pre这个node作为下一轮的pre，将cur的next，即temp赋给cur作为下一轮的cur node
        newHead = cur;
        cur = temp;
    }
    return newHead;
}