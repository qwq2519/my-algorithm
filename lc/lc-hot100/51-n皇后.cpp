class Solution {

  vector<vector<string>> ans;
  vector<string> path;
  vector<char> col, diag1, diag2;
  int N;

  /* 用两个对角线数组优化了这个判断
  bool check(int x, int y) {
    int i = x - 1, j = y - 1;
    for (; i >= 0 && j >= 0; i--, j--) {
      if (path[i][j] == 'Q')
        return false;
    }
    for (i = x - 1, j = y + 1; i >= 0 && j < N; i--, j++) {
      if (path[i][j] == 'Q')
        return false;
    }
    return true;
  }*/

  void dfs(int r) {
    if (r == N) {
      ans.push_back(path);
      return;
    }
    for (int c = 0; c < N; ++c) {
      int d1 = r + c;
      int d2 = r - c + (N - 1);
      if (col[c] || diag1[d1] || diag2[d2])
        continue;
      path[r][c] = 'Q';
      col[c] = diag1[d1] = diag2[d2] = 1;
      dfs(r + 1);
      path[r][c] = '.';
      col[c] = diag1[d1] = diag2[d2] = 0;
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    N = n;
    ans.clear();
    path.assign(n, string(n, '.'));
    col.assign(n, 0);
    diag1.assign(2 * n - 1, 0);
    diag2.assign(2 * n - 1, 0);
    dfs(0);
    return ans;
  }
};
