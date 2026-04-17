class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n);
    vector<int> lmul(n);
    vector<int> rmul(n);

    lmul[0] = nums[0];
    for (int i = 1; i < n; i++) {
      lmul[i] = lmul[i - 1] * nums[i];
    }

    rmul[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      rmul[i] = rmul[i + 1] * nums[i];
    }

    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        ans[i] = rmul[1];
      } else if (i == n - 1) {
        ans[i] = lmul[n - 2];
      } else {
        ans[i] = lmul[i - 1] * rmul[i + 1];
      }
    }

    return ans;
  }
};
