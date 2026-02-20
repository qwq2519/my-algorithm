
class Solution {
  int n;
  vector<vector<int>> ans;
  void dfs(vector<int> &v, vector<char> &used, vector<int> &nums) {
    if (v.size() == n) {
      ans.push_back(v);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (used[i])
        continue;
      used[i] = true;
      v.push_back(nums[i]);
      dfs(v, used, nums);
      used[i] = false;
      v.pop_back();
    }
  }

  void dfs2(int pos, vector<int> &nums) {
    if (pos == n) {
      ans.push_back(nums);
      return;
    }
    for (int i = pos; i < n; ++i) {
      swap(nums[pos], nums[i]);
      dfs2(pos + 1, nums);
      swap(nums[pos], nums[i]);
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    premute2(nums);
    return ans;
  }
  void permute1(vector<int> &nums) {
    ans.clear();
    n = nums.size();
    vector<int> v;
    v.reserve(n);
    vector<char> used(n, 0);
    dfs(v, used, nums);
  }

  void premute2(vector<int> &nums) {
    ans.clear();
    n = nums.size();
    dfs2(0, nums);
  }
};
