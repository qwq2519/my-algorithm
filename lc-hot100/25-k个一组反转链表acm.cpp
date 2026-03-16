#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next = nullptr;
    Node(int V) : val(V) {}
};

void print(Node *head) {
    auto p = head;
    while (p) {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
}

Node *reverse(Node *head) {
    auto p = head;
    Node *pre = nullptr;
    while (p) {
        auto next = p->next;
        p->next = pre;
        pre = p;
        p = next;
    }
    return pre;
}

Node *reverseK(Node *head, int k) {
    int cnt = 0;
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *pre = dummy;
    auto p = dummy->next;

    while (p) {
        auto next = p->next;
        ++cnt;
        if (cnt == k || next == nullptr) {
            // pre ... start ...p ....next
            auto start = pre->next;
            pre->next = nullptr;
            p->next = nullptr;

            // pre start<-p next
            reverse(start);
            pre->next = p;
            start->next = next;
            pre = start;
            cnt = 0;
        }
        p = next;
    }
    return dummy->next;
}

int main() {
    int n, k;
    cin >> n >> k;

    Node *dummy = new Node(-1);
    auto p = dummy;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        p->next = new Node(x);
        p = p->next;
    }

    print(dummy->next);
    dummy->next = reverseK(dummy->next, k);
    print(dummy->next);
}
