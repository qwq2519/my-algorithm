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
  public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *a = new ListNode(-1);
        ListNode *b = new ListNode(-1);
        auto p1 = a;
        auto p2 = b;

        auto p = head;
        while (p) {
            auto next = p->next;
            p->next = nullptr;
            if (p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = next;
        }
        p1->next = b->next;
        return a->next;
    }
};
