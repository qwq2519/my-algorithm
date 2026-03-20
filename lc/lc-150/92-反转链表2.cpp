/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

    ListNode *reverse(ListNode *head) {
        auto cur = head;
        ListNode *pre = nullptr;
        while (cur) {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

  public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (head == nullptr || left == right) {
            return head;
        }

        ListNode *dummy = new ListNode(-1, head);

        ListNode *pre = dummy;
        auto start = dummy;
        auto end = dummy;
        for (int i = 0; i <= left; ++i) {
            pre = start;
            start = start->next;
        }
        for (int i = 0; i <= right; ++i)
            end = end->next;

        auto next = end->next;
        end->next = nullptr;
        pre->next = nullptr;
        reverse(start);

        pre->next = end;
        start->next = next;

        return dummy->next;
    }
};
