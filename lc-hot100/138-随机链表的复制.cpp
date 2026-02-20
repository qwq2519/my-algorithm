/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node *copyRandomList(Node *head) {

    if (head == nullptr) {
      return head;
    }

    // 复制节点
    auto p = head;
    while (p) {
      auto t = new Node(p->val);
      t->next = p->next;
      p->next = t;
      p = p->next->next;
    }

    // 复制random指针
    p = head;
    while (p) {
      auto r = p->random;
      if (r) {
        p->next->random = r->next;
      }
      p = p->next->next;
    }

    // 拆分节点
    Node *dummy = new Node(-1);
    auto cur = dummy;
    p = head;
    while (p) {
      cur->next = p->next;

      cur = cur->next;
      p->next = p->next->next;
      p = p->next;
    }

    return dummy->next;
  }
};
