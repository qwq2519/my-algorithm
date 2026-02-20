class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int ans = 0;

    // sum->count
    unordered_map<int, int> m;

    int nowsum = 0;
    m[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      nowsum += nums[i];
      ans += m[nowsum - k];
      ++m[nowsum];
    }

    return ans;
  }
};
