class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.empty())
      return 0;
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); ++i) {
      s.insert(nums[i]);
    }

    int ans = 1;

    for (int it : s) {
      // 不是最佳的开始
      if (s.find(it - 1) != s.end()) {
        continue;
      }
      int len = 0;
      while (s.find(it) != s.end()) {
        ++it;
        ++len;
      }
      ans = max(ans, len);
    }

    return ans;
  }
};
