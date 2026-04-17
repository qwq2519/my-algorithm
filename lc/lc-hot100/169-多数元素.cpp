class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int ans = 0, count = 0;

        for (auto i : nums) {
            if (count == 0) {
                ans = i;
                count = 1;
            } else {
                count += i == ans ? 1 : -1;
            }
        }
        return ans;
    }
};
