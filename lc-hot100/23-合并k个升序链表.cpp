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
  ListNode *mergeKLists(vector<ListNode *> &lists) {

    struct cmp {
      bool operator()(const ListNode *a, const ListNode *b) const {
        return a->val > b->val;
      }
    };

    priority_queue<ListNode *, vector<ListNode *>, cmp> q;

    for (auto it : lists) {
      if (it != nullptr) {
        q.push(it);
      }
    }

    ListNode *dummy = new ListNode(0);
    auto p = dummy;

    while (!q.empty()) {
      ListNode *t = q.top();
      q.pop();

      p->next = new ListNode(t->val);
      p = p->next;
      if (t->next) {
        q.push(t->next);
      }
    }

    return dummy->next;
  }
};
