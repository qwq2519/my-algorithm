class Solution {
public:
  void moveZeroes0(vector<int> &nums) {
    int l = 0;
    for (int r = 0; r < nums.size(); ++r) {
      if (nums[r] != 0) {
        swap(nums[l], nums[r]);
        ++l;
      }
    }
  }
  void moveZeroes(vector<int> &nums) {
    int cnt = 0;
    for (int x : nums) {
      if (x != 0) {
        nums[cnt++] = x;
      }
    }
    for (; cnt < nums.size(); ++cnt) {
      nums[cnt] = 0;
    }
  }
};
