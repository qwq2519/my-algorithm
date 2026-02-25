class Solution {
  int f[105][10007];

public:
  int numSquares(int n) {
    return Solution2(n);
    // 完全背包
    for (int i = 0; i <= n; i++) {
      f[0][i] = INT_MAX; // 用0不能凑出任何数
    }
    f[0][0] = 0; // 凑出0需要0个数

    for (int i = 1; i * i <= n; i++) {
      int square = i * i;
      for (int j = 0; j <= n; j++) {
        if (j < square) // 不能选
          f[i][j] = f[i - 1][j];
        else
          f[i][j] = min(
              f[i - 1][j],
              f[i][j - square] +
                  1); // 如果是f[i-1][j-square]就代表只能选一次了，这是0/1背包
      }
    }
    return f[(int)sqrt(n)][n];
  }

  int Solution2(int n) {
    vector<int> dp(n + 1, 1e9);

    dp[0] = 0;
    for (int i = 1; i * i <= n; i++) {
      int square = i * i;
      for (int j = square; j <= n; j++) {
        // 滚动数组优化，j是递增的，保证状态是从i-1层转移到第i层
        dp[j] = min(dp[j], dp[j - square] + 1);
      }
    }

    return dp[n];
  }
};
