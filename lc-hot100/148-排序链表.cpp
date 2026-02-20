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
private:
  ListNode *mergeList(ListNode *p1, ListNode *p2) {
    ListNode *dummy = new ListNode(0);
    auto p = dummy;

    while (p1 && p2) {
      if (p1->val > p2->val) {
        p->next = p2;
        p2 = p2->next;
      } else {
        p->next = p1;
        p1 = p1->next;
      }
      p = p->next;
    }
    p->next = p1 ? p1 : p2;

    return dummy->next;
  }

  ListNode *sort(ListNode *head) {
    // 空链表或者只有一个节点
    if (!head || !head->next) {
      return head;
    }
    auto mid = findMidandSplit(head);
    return mergeList(sort(head), sort(mid));
  }

  ListNode *findMidandSplit(ListNode *head) {
    auto fast = head;
    auto slow = head;
    ListNode *prev = nullptr;
    while (fast && fast->next) {
      prev = slow;
      fast = fast->next->next;
      slow = slow->next;
    }
    prev->next = nullptr;
    return slow;
  }

public:
  ListNode *sortList(ListNode *head) { return sort(head); }
};
