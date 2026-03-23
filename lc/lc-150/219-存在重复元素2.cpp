class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        int l = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++) {
            m[nums[r]]++;

            if (r - l > k) {
                m[nums[l]]--;
                l++;
            }

            if (m[nums[r]] == 2) {
                return true;
            }
        }
        return false;
    }
};
