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
#include <cstddef>
#include <iterator>
class Solution {

private:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *prev = nullptr;
    auto cur = head;
    while (cur) {
      auto next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {

    if (!head || k <= 1) {
      return head;
    }

    ListNode *dummy = new ListNode(-1, head);

    auto p = dummy->next;
    auto prev = dummy;

    int cnt = 0;
    while (p) {
      ++cnt;
      auto next = p->next;
      if (cnt == k) {

        auto start = prev->next;

        prev->next = nullptr;
        p->next = nullptr;

        reverseList(start);

        prev->next = p;
        start->next = next;
        prev = start;
        cnt = 0;
      }
      p = next;
    }

    return dummy->next;
  }
};
