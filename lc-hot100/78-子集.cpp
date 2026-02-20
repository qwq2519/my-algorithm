class Solution {
  vector<vector<int>> ans;
  int n;
  void dfs(int pos, vector<int> &v, vector<int> &nums) {
    if (pos == n) {
      ans.push_back(v);
      return;
    }
    v.push_back(nums[pos]);
    dfs(pos + 1, v, nums);
    v.pop_back();
    dfs(pos + 1, v, nums);
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> v;
    n = nums.size();
    dfs(0, v, nums);
    return ans;
  }
};
