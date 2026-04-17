class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m; // value->pos
    m[nums[0]] = 0;
    for (int i = 1; i < nums.size(); i++) {
      int need = target - nums[i];
      auto it = m.find(need);
      if (it != m.end()) {
        return {it->second, i};
      }
      m[nums[i]] = i;
    }
    return {};
  }
};
