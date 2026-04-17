class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        text1 = ' ' + text1;
        text2 = ' ' + text2;
        int n = text1.size() - 1;
        int m = text2.size() - 1;

        vector<vector<int>> f(
            n + 1,
            vector<int>(
                m + 1,
                0)); // f[i][j] 1...i 1...j 字符组成的公共子序列集合的最大长度

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (text1[i] == text2[j])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        return f[n][m];
    }
};
