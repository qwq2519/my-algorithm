class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        bitset<9> r[9], c[9], a[3][3];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch == '.')
                    continue;
                int x = ch - '0' - 1;

                if (r[i][x] || c[j][x] || a[i / 3][j / 3][x])
                    return false;

                r[i][x] = 1;
                c[j][x] = 1;
                a[i / 3][j / 3][x] = 1;
            }
        }

        return true;
    }
};
