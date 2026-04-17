class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = -1, r = nums.size();
    int last = nums.back();
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      // 在第一段
      if (nums[mid] > last)
        l = mid;
      else
        r = mid;
    }
    return nums[r];
  }
};
