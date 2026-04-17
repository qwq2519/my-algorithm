class Solution {
  vector<string> ans;
  int len;

  void dfs(string &str, int pos, int count) {
    if (pos == len) {
      if (count == 0) {
        ans.push_back(str);
      }
      return;
    }
    if (count < 0) {
      return;
    }
    str.push_back('(');
    dfs(str, pos + 1, count + 1);
    str.pop_back();
    str.push_back(')');
    dfs(str, pos + 1, count - 1);
    str.pop_back();
  }

public:
  vector<string> generateParenthesis(int n) {
    ans.clear();
    len = n * 2;
    string str = "";
    str.reserve(len);
    dfs(str, 0, 0);
    return ans;
  }
};
