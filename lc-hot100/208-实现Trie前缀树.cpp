// Node*数组，后可以改map
/*
class Trie {
  struct Node {
    Node *child[26];
    bool end;
    Node() : end(false), child{} {}
  };
  Node *root;

public:
  Trie() { root = new Node(); }

  void insert(string word) {
    Node *p = root;
    for (char ch : word) {
      int idx = ch - 'a';
      if (!p->child[idx])
        p->child[idx] = new Node();
      p = p->child[idx];
    }
    p->end = true;
  }

  bool search(string word) {
    Node *p = root;
    for (char ch : word) {
      int idx = ch - 'a';
      p = p->child[idx];
      if (!p)
        return false;
    }
    return p->end;
  }

  bool startsWith(string prefix) {
    Node *p = root;
    for (char ch : prefix) {
      int idx = ch - 'a';
      p = p->child[idx];
      if (!p)
        return false;
    }
    return true;
  }
};
**/
class Trie {
  struct Node {
    array<int, 26> nxt;
    bool end = false;
    Node() { nxt.fill(-1); }
  };
  vector<Node> t;

public:
  Trie() { t.emplace_back(); }

  void insert(string word) {
    int p = 0;
    for (char ch : word) {
      int idx = ch - 'a';
      if (t[p].nxt[idx] == -1) {
        t[p].nxt[idx] = t.size();
        t.emplace_back();
      }
      p = t[p].nxt[idx];
    }
    t[p].end = true;
  }

  bool search(string word) {
    int p = 0;
    for (char ch : word) {
      int idx = ch - 'a';
      p = t[p].nxt[idx];
      if (p == -1)
        return false;
    }
    return t[p].end;
  }

  bool startsWith(string prefix) {
    int p = 0;
    for (char ch : prefix) {
      int idx = ch - 'a';
      p = t[p].nxt[idx];
      if (p == -1)
        return false;
    }
    return true;
  }
};
