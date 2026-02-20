class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    int fresh = 0;

    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        } else if (grid[i][j] == 1) {
          ++fresh;
        }
      }
    }
    if (fresh == 0) {
      return 0;
    }

    int time = 0;
    while (!q.empty()) {
      int sz = q.size();
      bool flag = false;
      while (sz--) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
          int xx = x + dx[i];
          int yy = y + dy[i];
          if (xx < 0 || xx >= n || yy < 0 || yy >= m || grid[xx][yy] != 1) {
            continue;
          }
          grid[xx][yy] = 2;
          --fresh;
          flag = true;
          q.push({xx, yy});
        }
      }
      if (flag) {
        ++time;
      }
      if (fresh == 0) {
        return time;
      }
    }
    return -1;
  }
};
