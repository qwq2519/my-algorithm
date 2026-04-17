class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

    int n = matrix.size();
    int m = matrix[0].size();
    int cnt = n * m;

    int x = 0, y = 0, f = 0;
    for (int k = 0; k < m * n; ++k) {
      ans.push_back(matrix[x][y]);
      matrix[x][y] = INT_MAX;

      int xx = x + dx[f];
      int yy = y + dy[f];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m || matrix[xx][yy] == INT_MAX) {
        f = (f + 1) % 4;
      }

      x += dx[f];
      y += dy[f];
    }
    return ans;
  }
};
