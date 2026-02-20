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
    ListNode *prev = nullptr;
    while (cur) {
      auto nxt = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nxt;
    }
    return prev;
  }

public:
  bool isPalindrome(ListNode *head) {
    auto fast = head;
    auto slow = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    slow = reverse(slow);

    auto p1 = head;
    auto tail = slow;

    while (tail) {
      if (tail->val != p1->val) {
        return false;
      }
      p1 = p1->next;
      tail = tail->next;
    }
    return true;
  }
};
