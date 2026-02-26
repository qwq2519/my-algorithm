class Solution {

  struct Node {
    int nxt[26];
    bool end = false;
    Node() { fill(nxt, nxt + 26, -1); }
  };

  bool TrieSolution(string s, vector<string> &wordDict) {
    int n = s.size();
    vector<Node> tr;
    tr.emplace_back(); // root;
    for (const auto &w : wordDict) {
      int p = 0;
      for (char ch : w) {
        int c = ch - 'a';
        if (tr[p].nxt[c] == -1) {
          tr[p].nxt[c] = tr.size();
          tr.emplace_back();
        }
        p = tr[p].nxt[c];
      }
      tr[p].end = true;
    }

    vector<char> f(n + 1, 0);
    f[0] = 1;

    for (int j = 0; j < n; j++) {
      if (!f[j])
        continue;
      int p = 0;
      for (int pos = j; pos < n; pos++) {
        int c = s[pos] - 'a';
        p = tr[p].nxt[c];
        if (p == -1)
          break;
        if (tr[p].end) {
          f[pos + 1] = 1;
        }
      }
    }
    return f[n];
  }

public:
  bool wordBreak(string s, vector<string> &wordDict) {
    return TrieSolution(s, wordDict);
    // 完全背包
    int n = s.size();
    int m = wordDict.size();
    vector<char> f(n + 1, 0); // 前i个字符 [0...i-1]
    f[0] = 1;

    /*逆推
    for (int i = 1; i <= n; i++) {
      for (const string &str : wordDict) {
        int k = (int)str.size();
        if (k <= i && f[i - k] && s.compare(i - k, k, str) == 0) {
          f[i] = 1;
          break;
        }
    }
    }*/
    // 顺推
    for (int i = 0; i < n; i++) {
      if (!f[i])
        continue;
      for (const string &w : wordDict) {
        int k = w.size();
        if (i + k <= n && s.compare(i, k, w) == 0)
          f[i + k] = 1;
      }
    }

    return f[n];
  }
};
