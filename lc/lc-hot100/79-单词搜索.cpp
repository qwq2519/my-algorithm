class Solution {
  int n, m;
  bool flag;
  int len;

  void dfs(int x, int y, const string &str, int pos,
           vector<vector<char>> &board) {
    if (pos == len) {
      flag = true;
    }
    if (flag) {
      return;
    }
    if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '0') {
      return;
    }

    if (board[x][y] != str[pos]) {
      return;
    }
    char temp = board[x][y];
    board[x][y] = '0';
    dfs(x + 1, y, str, pos + 1, board);
    dfs(x, y + 1, str, pos + 1, board);
    dfs(x - 1, y, str, pos + 1, board);
    dfs(x, y - 1, str, pos + 1, board);
    board[x][y] = temp;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    n = board.size();
    m = board[0].size();
    len = word.size();
    if (len == 0) {
      return true;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == word[0]) {
          flag = false;
          dfs(i, j, word, 0, board);
          if (flag) {
            return true;
          }
        }
      }
    }

    return false;
  }
};
