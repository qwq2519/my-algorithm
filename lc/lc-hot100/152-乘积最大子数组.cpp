class Solution {
public:
  int maxProduct(vector<int> &nums) {
    // 负负得正
    int n = nums.size();
    int ans = nums[0];
    int minMul = nums[0];
    int maxMul = nums[0];

    for (int i = 1; i < n; i++) {
      int a = maxMul * nums[i];
      int b = minMul * nums[i];
      minMul = min({nums[i], a, b});
      maxMul = max({nums[i], a, b});
      ans = max(ans, maxMul);
    }

    return ans;
  }
};
