class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      if (r < i) {
        return false;
      }
      l = i;
      r = max(r, i + nums[i]);
      if (r >= n - 1) {
        return true;
      }
    }
    return false;
  }
};
