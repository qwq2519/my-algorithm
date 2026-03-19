class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int ans = 1e9;
        int n = nums.size();
        int l = 0;
        int sum = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return ans == 1e9 ? 0 : ans;
    }
};
