class Solution {
  vector<vector<int>> ans;
  int n;
  void dfs(vector<int> &chosed, int pos, int remain, const vector<int> &nums) {
    if (remain == 0) {
      ans.push_back(chosed);
      return;
    }
    for (int i = pos; i < n; ++i) {
      if (nums[i] > remain) {
        break;
      }
      chosed.push_back(nums[i]);
      dfs(chosed, i, remain - nums[i], nums);
      chosed.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    ans.clear();
    n = candidates.size();
    vector<int> chosed;
    dfs(chosed, 0, target, candidates);
    return ans;
  }
};
