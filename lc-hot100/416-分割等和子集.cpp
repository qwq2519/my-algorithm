class Solution {

  int n;
  bool Solution1(vector<int> &nums, int target) {
    vector<vector<char>> dp(n, vector<char>(target + 1, 0));

    dp[0][0] = 1; // 不选任何数
    if (nums[0] <= target)
      dp[0][nums[0]] = 1;
    // dp[0][>0]=false;

    for (int i = 1; i < n; i++) {
      int x = nums[i];
      for (int j = 0; j <= target; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= x)
          dp[i][j] |= dp[i - 1][j - x];
      }
    }

    return dp[n - 1][target];
  }

  bool Solution2(vector<int> &nums, int target) {
    vector<char> f(target + 1, 0);
    f[0] = 1;
    //    if (nums[0] <= target)
    //    f[nums[0]] = 1;

    for (int i = 1; i < n; i++) {
      int x = nums[i];
      for (int j = target; j >= x; j--) {
        f[j] |= f[j - x];
      }
    }
    return f[target];
  }

public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    n = nums.size();
    for (auto x : nums) {
      sum += x;
    }

    if (sum & 1)
      return false;

    // 从nums选出一些数，使得和为target，01背包
    int target = sum / 2;
    return Solution2(nums, target);
  }
};
