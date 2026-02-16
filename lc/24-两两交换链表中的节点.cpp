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
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode *dummy = new ListNode(0, head);
    auto p = dummy;
    while (p->next && p->next->next) {
      auto p2 = p->next;
      auto p3 = p->next->next;
      auto next = p3->next;

      p->next = p3;
      p3->next = p2;
      p2->next = next;

      p = p2;
    }

    return dummy->next;
  }
};
