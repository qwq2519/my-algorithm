class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // 完全背包
    vector<int> f(amount + 1, 1e9 + 1);
    f[0] = 0;

    int n = coins.size();
    for (int i = 0; i < n; i++) {
      int val = coins[i];
      for (int j = val; j <= amount; j++) {
        f[j] = min(f[j - val] + 1, f[j]);
      }
    }
    return f[amount] == 1e9 + 1 ? -1 : f[amount];
  }
};
