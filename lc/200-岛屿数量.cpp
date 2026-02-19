class Solution {
  int n, m;

  void dfs(vector<vector<char>> &grid, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != '1') {
      return;
    }
    grid[x][y] = '2';
    dfs(grid, x + 1, y);
    dfs(grid, x, y + 1);
    dfs(grid, x - 1, y);
    dfs(grid, x, y - 1);
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    n = grid.size();
    m = grid[0].size();

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '1') {
          ++ans;
          dfs(grid, i, j);
        }
      }
    }

    return ans;
  }
};
