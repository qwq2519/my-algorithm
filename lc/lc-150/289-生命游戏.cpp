class Solution {

    const int d[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                         {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    int count(vector<vector<int>> &board, int x, int y, int n, int m) {
        int t = 0;

        for (int dir = 0; dir < 8; ++dir) {
            int dx = x + d[dir][0];
            int dy = y + d[dir][1];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m)
                continue;
            t += board[dx][dy];
        }

        return t;
    }

    void brute(vector<vector<int>> &board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = count(board, i, j, n, m);
                ans[i][j] = board[i][j];
                if (board[i][j] && x != 2 && x != 3) {
                    ans[i][j] = 0;
                } else if (!board[i][j] && x == 3) {
                    ans[i][j] = 1;
                }
            }
        }
        board = ans;
    }

    // 0: 00 死->死
    // 1: 01 活死
    // 2: 10 死->活
    // 3：11 活活

    int count2(vector<vector<int>> &board, int x, int y, int n, int m) {
        int t = 0;

        for (int dir = 0; dir < 8; ++dir) {
            int dx = x + d[dir][0];
            int dy = y + d[dir][1];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m)
                continue;
            t += board[dx][dy] == 1 || board[dx][dy] == 3;
        }
        return t;
    }

    void solution(vector<vector<int>> &board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = count2(board, i, j, n, m);
                if (board[i][j] == 0) {
                    if (x == 3)
                        board[i][j] = 2;
                } else {
                    if (x == 2 || x == 3)
                        board[i][j] = 3;
                    else
                        board[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = board[i][j] >= 2;
    }

  public:
    // 答案要原地，并且这个使用的是int而不是bool，原来只有0/1，可以扩展编码为0 1
    // 2 3来实现原地更新 因此需要至少遍历两次
    void gameOfLife(vector<vector<int>> &board) { solution(board); }
};
