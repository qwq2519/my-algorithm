class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> none{-1, -1};
    vector<int> ans{-1, -1};
    int l = -1, r = nums.size();

    if (r == 0)
      return none;

    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (nums[mid] <= target)
        l = mid;
      else
        r = mid;
    }
    if (r == 0 || nums[l] != target)
      return none;

    ans[1] = l;

    l = -1, r = nums.size();
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (nums[mid] < target)
        l = mid;
      else
        r = mid;
    }
    ans[0] = r;

    return ans;
  }
};
