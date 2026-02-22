/* 朴素暴力
class Solution {
  string str;
  vector<vector<string>> ans;
  int len;

  bool check(int x, int y) {
    if (x > y)
      return false;
    for (int i = x, j = y; i < j; i++, j--) {
      if (str[i] != str[j]) {
        return false;
      }
    }
    return true;
  }

  void addAns(vector<pair<int, int>> &t) {
    vector<string> a;
    for (auto [x, y] : t) {
      a.push_back(str.substr(x, y - x + 1));
    }
    ans.emplace_back(a);
  }

  void dfs(int pre, int now, vector<pair<int, int>> &t) {
    if (now == len) {
      if (check(pre, now - 1)) {
        t.push_back({pre, now - 1});
        addAns(t);
        t.pop_back();
      }
      return;
    }

    dfs(pre, now + 1, t);

    if (check(pre, now)) {
      t.push_back({pre, now});
      dfs(now + 1, now + 1, t);
      t.pop_back();
    }
  }

public:
  vector<vector<string>> partition(string s) {
    ans.clear();
    len = s.size();
    str = s;
    vector<pair<int, int>> t;
    dfs(0, 0, t);
    return ans;
  }
};
**/
class Solution {
  vector<vector<char>> pal;
  vector<vector<string>> ans;
  vector<string> path;
  int n;

  void dfs(int start, const string &str) {
    if (start == n) {
      ans.push_back(path);
      return;
    }

    for (int end = start; end < n; end++) {
      if (!pal[start][end])
        continue;
      path.push_back(str.substr(start, end - start + 1));
      dfs(end + 1, str);
      path.pop_back();
    }
  }

public:
  vector<vector<string>> partition(string s) {
    ans.clear();
    path.clear();
    n = s.size();
    pal.assign(n, vector<char>(n, 0));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; j++) {
        if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
          pal[i][j] = 1;
        }
      }
    }
    dfs(0, s);
    return ans;
  }
};
