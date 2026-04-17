class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> f(n); // 前i件最大价值和

    if (n == 1) {
      return nums[0];
    }
    f[0] = nums[0];
    f[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
      f[i] = max(f[i - 1], f[i - 2] + nums[i]);
    }

    return f[n - 1];
  }
};
