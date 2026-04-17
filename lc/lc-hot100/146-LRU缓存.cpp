class LRUCache {

private:
  struct Node {
    int k;
    int v;
    Node *next;
    Node *prev;
    Node(int K, int V) {
      k = K;
      v = V;
      next = prev = nullptr;
    }
  };

  int size;
  int cap;
  unordered_map<int, Node *> m;
  Node *dummy;

public:
  LRUCache(int capacity) {
    cap = capacity;
    size = 0;
    dummy = new Node(-1, -1);
    dummy->prev = dummy->next = dummy;
  }

  int get(int key) {
    auto it = m.find(key);
    if (it == m.end()) {
      return -1;
    }
    remove(it->second);
    addFront(it->second);
    return it->second->v;
  }

  void put(int key, int value) {
    auto it = m.find(key);
    if (it != m.end()) {
      it->second->v = value;
      remove(it->second);
      addFront(it->second);
      return;
    }

    if (size == cap) {
      auto last = dummy->prev;
      m.erase(last->k);
      remove(last);
      --size;
    }

    Node *p = new Node(key, value);
    m[key] = p;
    addFront(p);
    ++size;
  }

  void remove(Node *p) {
    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->next = p->prev = nullptr;
  }
  void addFront(Node *p) {
    auto head = dummy->next;
    dummy->next = p;
    head->prev = p;
    p->next = head;
    p->prev = dummy;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
